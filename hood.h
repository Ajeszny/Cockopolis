//
// Created by ajeszny on 29.03.24.
//

#ifndef COCKOPOLIS_HOOD_H
#define COCKOPOLIS_HOOD_H
#include "includes.h"


class Hood {
private:
    string _tpath;
    hood_card_descr::hood_color _col;
    hood_card_descr::hood_type _tp;
public:
    Hood(hood_card_descr::hood_color suit=hood_card_descr::UNALIGNED, hood_card_descr::hood_type t=hood_card_descr::NONE);
    const char* get_path();
    const char* get_owner();
    void set_type(hood_card_descr::hood_type tp);
    tile_saveable get_tile_info();
    void set_color(hood_card_descr::hood_color c);
    hood_card_descr::hood_color get_color();
};


#endif //COCKOPOLIS_HOOD_H
