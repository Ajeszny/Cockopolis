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
    ///REALLY FUCKING INPORTANT:\n
    ///If you ever, EVER change the characters variable, _select WILL become unusable due to reallocation.
    ///Take this into consideration as the bugs produced by that are game-crushing
    ///(It took me a day to figure this out)
    ///UPD I use linked list now and it may've solved the problems with allocation
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
    void setchar(Character* ch);

    hood_card_descr::hood_color get_alignment();
///Я ПАНК МНЕ ПОХУЙ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::list<Character> characters;
};


#endif //COCKOPOLIS_PLAYER_H
