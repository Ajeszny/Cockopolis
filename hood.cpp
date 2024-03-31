//
// Created by ajeszny on 29.03.24.
//

#include "hood.h"

const char* card_paths[] = {"grassland.png", "agora.png", "barracks.png"};

Hood::Hood(hood_card_descr::hood_color suit, hood_card_descr::hood_type t) {
    _col = suit;
    _tpath = card_paths[t];
}

const char *Hood::get_path() {
    return _tpath.c_str();
}

void Hood::set_type(hood_card_descr::hood_type tp) {
    this->_tpath = card_paths[tp];
}
