//
// Created by ajeszny on 29.03.24.
//

#ifndef COCKOPOLIS_PLAYER_H
#define COCKOPOLIS_PLAYER_H
#include "includes.h"

class Player {
private:
    SDL_Point _cursor;
    string _tpath;
public:
    Player();
    ///Returns:
    ///0 if successful
    ///1 if trying to move out of bounds
    ///2 if dir is incorrect
    int move(SDL_Point dir);
    const char* get_texture_path();
    int get_x() const;
    int get_y() const;
};


#endif //COCKOPOLIS_PLAYER_H
