//
// Created by ajeszny on 29.03.24.
//

#ifndef COCKOPOLIS_TILE_H
#define COCKOPOLIS_TILE_H
#include "includes.h"
#include "hood.h"

class Character;

class Player;

class Tile {
private:
    string _tpath;
    Player* _owner;
    Hood _hood;
    Character* _c;
public:
    Tile(const char* path = "grassland.png", hood_card_descr::hood_type=hood_card_descr::NONE, hood_card_descr::hood_color=hood_card_descr::UNALIGNED);
    const char* get_path();
    void set_type(hood_card_descr::hood_type tp);
    const char* get_hood();
    const char* get_owner();
    tile_saveable get_tile_info();
    void increment();
    void realign(hood_card_descr::hood_color n);
    void setchar(Character* c);
    Character* getchar();
};


#endif //COCKOPOLIS_TILE_H
