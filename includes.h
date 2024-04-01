//
// Created by ajeszny on 28.03.24.
//

#ifndef COCKOPOLIS_INCLUDES_H
#define COCKOPOLIS_INCLUDES_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

#define NUM_HORIZONTAL_FRAMES 10
#define NUM_VERTICAL_FRAMES 8

struct __attribute__((packed)) tile_saveable {
    char tpath[256];
    int color;
    int type;
};

struct __attribute__((packed)) map_file {
  tile_saveable tiles[NUM_VERTICAL_FRAMES][NUM_HORIZONTAL_FRAMES];
};

using std::string;
namespace hood_card_descr {
    enum hood_color {
        HEARTS,
        DIAMONDS,
        SPADES,
        CLUBS,//Who tf came up with those names
        UNALIGNED
    };

    enum hood_type {
        NONE=0,
        ACE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };
}
#endif //COCKOPOLIS_INCLUDES_H
