#include "includes.h"
#include "window.h"
#include "player.h"
#include "map.h"

uint8_t reds[] = {255, 255, 0, 0};
uint8_t greens[4] = {0};
uint8_t blues[4] = {0};

void turn(Window& w, Map& m, Player& p) {
    for (auto &c:p.characters) {
        c.reset_action_limit();
    }
    bool quit = false;
    while (1) {
        switch (w.ask_to_end_turn()) {
            case 0:
                break;
            case 1:
                quit = true;
                w.show();
                printf("Turn ended!");
                goto end;
            case 2:
                SDL_Quit();
                exit(0);
            default:
                SDL_Quit();
                exit(1);
        }
        w.edit(m, p);
        p.move(w.poll_input());
        for (int i = 0; i < NUM_VERTICAL_FRAMES; ++i) {
            for (int j = 0; j < NUM_HORIZONTAL_FRAMES; ++j) {
                w.push(m[i][j].get_path(), {j * DEFAULT_FRAME, i * DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME});
            }
        }
        for (int i = 0; i < NUM_VERTICAL_FRAMES; ++i) {
            for (int j = 0; j < NUM_HORIZONTAL_FRAMES; ++j) {
                w.push(m[i][j].get_hood(), {j * DEFAULT_FRAME, i * DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME});
                if (m[i][j].get_tile_info().type != hood_card_descr::NONE) w.push(m[i][j].get_owner(),
                                                                                  {j * DEFAULT_FRAME, i * DEFAULT_FRAME,
                                                                                   DEFAULT_FRAME / 4,
                                                                                   DEFAULT_FRAME / 4});
                if (m[i][j].getchar()) w.push(m[i][j].getchar()->get_type(),
                                              {j * DEFAULT_FRAME, i * DEFAULT_FRAME, DEFAULT_FRAME / 4,
                                               DEFAULT_FRAME / 2});
            }
        }
        w.cpush(p.get_texture_path(),
                {p.get_x() * DEFAULT_FRAME, p.get_y() * DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME},
                reds[p.get_alignment()], greens[p.get_alignment()], blues[p.get_alignment()]);
        w.show();
        m.update();
    }
    end:;
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window w(DEFAULT_W, DEFAULT_H);
    Player p(hood_card_descr::SPADES);
    Player ph(hood_card_descr::HEARTS);
    ph.move({1, 1});
    Map m("res.map");
    p.characters.emplace_back(S_KING, hood_card_descr::SPADES, m);
    p.characters.begin()->set_pos({1, 1});
    ph.characters.emplace_back(H_KING, hood_card_descr::HEARTS, m);

    while(w.listen_for_end()) {
        turn(w, m, p);
        turn(w, m, ph);
    }
    SDL_Quit();
    return 0;
}
