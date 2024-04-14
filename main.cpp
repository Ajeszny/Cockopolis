#include "includes.h"
#include "window.h"
#include "player.h"
#include "map.h"

uint8_t reds[] = {255, 255, 0, 0};
uint8_t greens[4] = {0};
uint8_t blues[4] = {0};

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window w(DEFAULT_W, DEFAULT_H);
    Player p(hood_card_descr::SPADES);
    Map m("res.map");
    Character king(S_KING, hood_card_descr::SPADES, m);
    while(w.listen_for_end()) {
        w.edit(m, p);
        p.move(w.poll_input());
        for (int i = 0; i < NUM_VERTICAL_FRAMES; ++i) {
            for (int j = 0; j < NUM_HORIZONTAL_FRAMES; ++j) {
                w.push(m[i][j].get_path(), {j*DEFAULT_FRAME, i*DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME});
            }
        }
        for (int i = 0; i < NUM_VERTICAL_FRAMES; ++i) {
            for (int j = 0; j < NUM_HORIZONTAL_FRAMES; ++j) {
                w.push(m[i][j].get_hood(), {j*DEFAULT_FRAME, i*DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME});
                if (m[i][j].get_tile_info().type != hood_card_descr::NONE) w.push(m[i][j].get_owner(), {j*DEFAULT_FRAME, i*DEFAULT_FRAME, DEFAULT_FRAME/4, DEFAULT_FRAME/4});
                if (m[i][j].getchar()) w.push(m[i][j].getchar()->get_type(), {j*DEFAULT_FRAME, i*DEFAULT_FRAME, DEFAULT_FRAME/4, DEFAULT_FRAME/2});
            }
        }
        w.cpush(p.get_texture_path(), {p.get_x()*DEFAULT_FRAME, p.get_y()*DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME}, reds[p.get_alignment()], greens[p.get_alignment()], blues[p.get_alignment()]);
        w.show();
        m.update();
    }
    SDL_Quit();
    return 0;
}
