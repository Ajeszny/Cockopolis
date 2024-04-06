//
// Created by ajeszny on 28.03.24.
//

#include "texture.h"

Texture::~Texture() {
    SDL_DestroyTexture(_texture);
}

Texture::Texture(SDL_Renderer* r, const char *path, int x, int y, int w, int h) {
    _area = {x, y, w, h};
    _texture = IMG_LoadTexture(r, path);
    if (!_texture) {
        printf("WSZYSTKO POSZŁO W PIZDĘ!!! %s", SDL_GetError());
    }
}

SDL_Texture *Texture::get_texture() {
    return _texture;
}

SDL_Rect *Texture::get_rect() {
    return &_area;
}

void Texture::change_color(uint8_t r, uint8_t g, uint8_t b) {
    int err = SDL_SetTextureColorMod(_texture, r, g, b);
    if (err == -1) {
        printf("WSZYSTKO POSZŁO W PIZDĘ!!! %s", SDL_GetError());
    }
}


