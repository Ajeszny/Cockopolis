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

tile_saveable Tile::get_tile_info() {
    return _hood.get_tile_info();
}

void Tile::increment() {
    _hood.set_type((hood_card_descr::hood_type)(_hood.get_tile_info().type + 1));
}
