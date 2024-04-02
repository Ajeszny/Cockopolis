#include "includes.h"
#include "window.h"
#include "player.h"
#include "map.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window w(DEFAULT_W, DEFAULT_H);
    Player p;
    Map m(NUM_HORIZONTAL_FRAMES, NUM_VERTICAL_FRAMES);
    while(w.listen_for_end()) {
        p.move(w.poll_input());
        w.edit(m, p.get_x(), p.get_y());
        for (int i = 0; i < NUM_VERTICAL_FRAMES; ++i) {
            for (int j = 0; j < NUM_HORIZONTAL_FRAMES; ++j) {
                w.push(m[i][j].get_path(), {j*DEFAULT_FRAME, i*DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME});
            }
        }
        m[5][7].set_type(hood_card_descr::ACE);
        for (int i = 0; i < NUM_VERTICAL_FRAMES; ++i) {
            for (int j = 0; j < NUM_HORIZONTAL_FRAMES; ++j) {
                w.push(m[i][j].get_hood(), {j*DEFAULT_FRAME, i*DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME});
            }
        }
        w.push(p.get_texture_path(), {p.get_x()*DEFAULT_FRAME, p.get_y()*DEFAULT_FRAME, DEFAULT_FRAME, DEFAULT_FRAME});
        w.show();
        m.save("res.map");
    }
    SDL_Quit();
    return 0;
}
