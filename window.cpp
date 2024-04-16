//
// Created by ajeszny on 28.03.24.
//

#include "window.h"

//TODO: add another array for blacks
enum PCharacter char_arr[][2] = {
        {
                H_JACK,
                H_QUEEN
        },
        {
                S_JACK,
                S_QUEEN
        }
};

Window::Window(int width, int height) {
    _window = SDL_CreateWindow("Cockopolis", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                               SDL_WINDOW_OPENGL);//May add a fullscreen option later
    _renderer = SDL_CreateRenderer(_window, -1, 0);
}


void Window::show() {
    SDL_PollEvent(&_event);
    SDL_RenderClear(_renderer);
    //Here goes placing logic
    for (auto &texture: textures) {
        SDL_RenderCopy(_renderer, texture.get_texture(), nullptr, texture.get_rect());
    }
    textures.clear();
    SDL_RenderPresent(_renderer);
}

bool Window::listen_for_end() const {
    return _event.type != SDL_QUIT;
}

void Window::push(const string &path, SDL_Rect pos) {
    textures.emplace_back(_renderer, path.c_str(), pos.x, pos.y, pos.w, pos.h);
}

Window::~Window() {
    textures.clear();
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

SDL_Point Window::poll_input() const {
    if (_event.type == SDL_KEYDOWN) {
        switch (_event.key.keysym.sym) {
            case SDLK_w:
                return {0, -1};
            case SDLK_a:
                return {-1, 0};
            case SDLK_s:
                return {0, 1};
            case SDLK_d:
                return {1, 0};
            default:
                return {0, 0};
        }
    }
    return {0, 0};
}

void Window::edit(Map &m, Player &p) const {
    if ((_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_SPACE)) {
        if (p.getchar()) {
            if (!m[p.get_y()][p.get_x()].getchar()) {
                p.getchar()->set_pos({p.get_x(), p.get_y()});
                p.getchar()->claim(m);
                p.getchar()->action();
                p.setchar(nullptr);
            }
            return;
        }
        if (m[p.get_y()][p.get_x()].getchar()&&
                m[p.get_y()][p.get_x()].getchar()->can_move()
        &&m[p.get_y()][p.get_x()].getchar()->get_owner() == p.get_alignment()) p.select(*m[p.get_y()][p.get_x()].getchar());
    }
    if ((_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_c) && p.getchar()) {
        if (m[p.get_y()][p.get_x()].take_hero()) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (i == 1 && j == 1 || !(p.get_x() > 0
                                              && p.get_y() > 0
                                              && p.get_x() < NUM_HORIZONTAL_FRAMES
                                              && p.get_y() < NUM_VERTICAL_FRAMES)) {
                        continue;
                    }

                    if (m[i + p.get_y() - 1][j + p.get_x() - 1].get_alignment() == p.get_alignment()) {
                        p.getchar()->move({j - 1, i - 1}, m);
                        p.getchar()->action();
                        p.setchar(nullptr);
                        p.characters.push_back(Character(char_arr[p.get_alignment()/2][m[p.get_y()][p.get_x()].get_tile_info().type - 1],
                                                  p.get_alignment(), m));
                        auto it = p.characters.end();
                        std::advance(it, -1);

                        it->set_pos({p.get_x(), p.get_y()});
                        return;
                    }

                }
            }
        }
    }
    if ((_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_ESCAPE)) {
        p.setchar(nullptr);
    }
}

void Window::cpush(const string &path, SDL_Rect pos, uint8_t r, uint8_t g, uint8_t b) {
    textures.emplace_back(_renderer, path.c_str(), pos.x, pos.y, pos.w, pos.h);
    textures[textures.size() - 1].change_color(r, g, b);
}

int Window::ask_to_end_turn() const {
    return (_event.type == SDL_KEYDOWN && _event.key.keysym.sym == SDLK_g) * 1 + (_event.type == SDL_QUIT) * 2;
}
