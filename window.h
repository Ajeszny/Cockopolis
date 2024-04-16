//
// Created by ajeszny on 28.03.24.
//

#ifndef COCKOPOLIS_WINDOW_H
#define COCKOPOLIS_WINDOW_H
#include "includes.h"
#include "texture.h"
#include "player.h"
#include "map.h"
#define DEFAULT_W 640
#define DEFAULT_H 512
#define DEFAULT_FRAME (DEFAULT_W/NUM_HORIZONTAL_FRAMES)

class Window {
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    SDL_Event _event{};
    std::vector<Texture> textures;
public:
    Window(int width, int height);
    ~Window();
    void show();
    void edit(Map& m, Player& p) const;
    [[nodiscard]] bool listen_for_end() const;
    void push(const string& path, SDL_Rect pos);
    void cpush(const string& path, SDL_Rect pos, uint8_t r, uint8_t g, uint8_t b);

    [[maybe_unused]] int ask_to_end_turn() const;
    SDL_Point poll_input() const;
};


#endif //COCKOPOLIS_WINDOW_H
