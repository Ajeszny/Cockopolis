#include "includes.h"
#include "window.h"

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Window w(600, 600);
    while(w.listen_for_end()) {
        w.push("hexagon32.png", {0, 0, 64, 64});
        w.show();
    }
    SDL_Quit();
    return 0;
}
