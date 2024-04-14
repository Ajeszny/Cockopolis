//
// Created by ajeszny on 06.04.24.
//

#ifndef COCKOPOLIS_CHARACTER_H
#define COCKOPOLIS_CHARACTER_H
#include "includes.h"
#include "map.h"

class Character {
private:
    PCharacter _type;
    SDL_Point _pos;
    hood_card_descr::hood_color _owner;
    Map* _map;
    int _actions;
public:
    ///Takes care of:\n
    ///Character type\n
    ///Character owner\n
    ///Link to map\n
    ///NOT the position(sets to 0.0)
    Character(PCharacter type, hood_card_descr::hood_color owner, Map& m);
    const char* get_type();
    [[nodiscard]] int get_x() const;
    [[nodiscard]] int get_y() const;
    void claim(Map& m);
    int move(SDL_Point dir, Map& m);
    void set_pos(SDL_Point pos);
    void update();
    ///Called during EVERY action\n
    ///Increases character's _actions counter
    void action();
};


#endif //COCKOPOLIS_CHARACTER_H
