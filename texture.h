//
// Created by ajeszny on 28.03.24.
//

#ifndef COCKOPOLIS_TEXTURE_H
#define COCKOPOLIS_TEXTURE_H
#include "includes.h"

class Texture {
private:
    SDL_Texture* _texture;
    SDL_Rect _area;
public:
    Texture(SDL_Renderer* r, const char *path, int x, int y, int w, int h);
    ~Texture();
    SDL_Texture* get_texture();
    SDL_Rect* get_rect();
};


#endif //COCKOPOLIS_TEXTURE_H
