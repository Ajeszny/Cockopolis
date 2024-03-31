//
// Created by ajeszny on 28.03.24.
//

#include "window.h"

Window::Window(int width, int height) {
    _window = SDL_CreateWindow("Cockopolis", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);//May add a fullscreen option later
    _renderer = SDL_CreateRenderer(_window, -1, 0);
}

void Window::show() {
    SDL_PollEvent(&_event);
    SDL_RenderClear(_renderer);
    //Here goes placing logic
    for (auto & texture : textures) {
        SDL_RenderCopy(_renderer, texture.get_texture(), nullptr, texture.get_rect());
    }
    textures.clear();
    SDL_RenderPresent(_renderer);
}

bool Window::listen_for_end() const {
    return _event.type != SDL_QUIT;
}

void Window::push(const string& path, SDL_Rect pos) {
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
