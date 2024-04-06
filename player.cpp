//
// Created by ajeszny on 29.03.24.
//

#include "player.h"

SDL_Point& operator+=(SDL_Point& l, SDL_Point& r) {
    l.x += r.x;
    l.y += r.y;
    return l;
}

int Player::move(SDL_Point dir) {
    switch ((_cursor.x ==0&&dir.x < 0)||(_cursor.y ==0&&dir.y < 0)||(_cursor.x ==(NUM_HORIZONTAL_FRAMES-1)&&dir.x > 0)||(_cursor.y ==(NUM_VERTICAL_FRAMES-1)&&dir.y > 0)) {
        case 1:
            return 1;
    }
    _cursor += dir;
}

const char* Player::get_texture_path() {
    return _tpath.c_str();
}

int Player::get_x() const {
    return _cursor.x;
}

int Player::get_y() const {
    return _cursor.y;
}

void Player::challenge(Map& m) {
    m[_cursor.y][_cursor.x].realign(_col);
}

Player::Player(hood_card_descr::hood_color team) {
    _cursor = {0, 0};
    _tpath = "choice.png";
    _col = team;
}

hood_card_descr::hood_color Player::get_alignment() {
    return _col;
};
