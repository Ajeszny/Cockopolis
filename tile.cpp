//
// Created by ajeszny on 29.03.24.
//

#include "tile.h"

Tile::Tile(const char* path, hood_card_descr::hood_type t, hood_card_descr::hood_color h) {
    _tpath = path;
    _owner = nullptr;
    _hood = Hood(h, t);
    _c = nullptr;
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
    if (_hood.get_tile_info().type == hood_card_descr::KING) {
        _hood.set_type(hood_card_descr::NONE);
        return;
    }
    _hood.set_type((hood_card_descr::hood_type)(_hood.get_tile_info().type + 1));
}

void Tile::realign(hood_card_descr::hood_color n) {
    _hood.set_color(n);
}

const char *Tile::get_owner() {
    return _hood.get_owner();
}

void Tile::setchar(Character *c) {
    _c = c;
}

Character *Tile::getchar() {
    return _c;
}

