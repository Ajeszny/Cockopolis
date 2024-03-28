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
}

SDL_Texture *Texture::get_texture() {
    return _texture;
}

SDL_Rect *Texture::get_rect() {
    return &_area;
}
