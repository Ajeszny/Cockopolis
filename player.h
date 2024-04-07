//
// Created by ajeszny on 29.03.24.
//

#ifndef COCKOPOLIS_PLAYER_H
#define COCKOPOLIS_PLAYER_H
#include "includes.h"
#include "map.h"
#include "character.h"

class Player {
private:
    SDL_Point _cursor;
    string _tpath;
    hood_card_descr::hood_color _col;
    Character* _select;
public:
    Player(hood_card_descr::hood_color team);
    ///Returns:
    ///0 if successful
    ///1 if trying to move out of bounds
    ///2 if dir is incorrect
    int move(SDL_Point dir);
    int chmove(SDL_Point dir);
    void select(Character& c);
    const char* get_texture_path();
    int get_x() const;
    int get_y() const;
    void challenge(Map& m);
    Character* getchar();

    hood_card_descr::hood_color get_alignment();
};


#endif //COCKOPOLIS_PLAYER_H
