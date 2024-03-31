//
// Created by ajeszny on 29.03.24.
//

#include "tile.h"

Tile::Tile(const char* path, hood_card_descr::hood_type t, hood_card_descr::hood_color h) {
    _tpath = path;
    _owner = nullptr;
    _hood = Hood(h, t);
}

const char *Tile::get_path() {
    return _tpath.c_str();
}

void Tile::set_type(hood_card_descr::hood_type tp) {
    _hood.set_type(tp);
}

const char *Tile::get_hood() {
    return _hood.get_path();
}
