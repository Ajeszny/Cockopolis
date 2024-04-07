//
// Created by ajeszny on 06.04.24.
//

#include "character.h"

const char* types[] = {
        "h_king.png",
        "h_queen.png",
        "h_jack.png",
        "r_joker.png",
        "s_king.png",
        "s_queen.png",
        "s_jack.png",
        "b_joker.png"
};

const char *Character::get_type() {
    return types[_type];
}

int Character::get_x() const {
    return _pos.x;
}

int Character::get_y() const {
    return _pos.y;
}

void Character::claim(Map &m) {
    m[_pos.y][_pos.x].realign(_owner);
    m[_pos.y][_pos.x].setchar(this);
}

int Character::move(SDL_Point dir, Map& m) {
    _pos.x += dir.x;
    _pos.y += dir.y;
    claim(m);
    return 0;
}

void Character::set_pos(SDL_Point pos) {
    (*_map)[_pos.y][_pos.x].setchar(nullptr);
    _pos = pos;
    (*_map)[_pos.y][_pos.x].setchar(this);
}

Character::Character(PCharacter type, hood_card_descr::hood_color owner, Map& m) {
    _type = type;
    _owner = owner;
    _pos = {0, 0};
    _map = &m;
    m[0][0].setchar(this);
}
