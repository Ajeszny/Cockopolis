//
// Created by ajeszny on 29.03.24.
//

#include "hood.h"


const char* card_paths[] = {"grassland.png"
                            ,"barracks.png"
                            ,"tower.png"
                            ,"farm.png"
                            ,"market.png"
                            ,"temple.png"
                            ,"workshop.png"
                            ," castle.png"
                            ,"tavern.png"
                            ,"home.png"
                            ,"agora1.png"
                            ,"agora2.png"
                            ,"agora3.png"
                            ,"agora4.png"};

const char* alignments[] = {
        "hearts.png",
        "diamonds.png",
        "spades.png",
        "clubs.png",
        "unaligned.png"
};

Hood::Hood(hood_card_descr::hood_color suit, hood_card_descr::hood_type t) {
    _col = suit;
    _tp = t;
    _tpath = card_paths[t];
}

const char *Hood::get_path() {
    return _tpath.c_str();
}

void Hood::set_type(hood_card_descr::hood_type tp) {
    this->_tp = tp;
    this->_tpath = card_paths[tp];
}

tile_saveable Hood::get_tile_info() {
    tile_saveable t{};
    strcpy(t.tpath, _tpath.c_str());
    t.color = (int)_col;
    t.type = (int)_tp;
    return t;
}

void Hood::set_color(hood_card_descr::hood_color c) {
    printf("%i", _col);
    _col = c;
}

const char *Hood::get_owner() {
    return alignments[_col];
}

hood_card_descr::hood_color Hood::get_color() {
    return _col;
}
