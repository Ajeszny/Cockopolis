//
// Created by ajeszny on 29.03.24.
//

#ifndef COCKOPOLIS_MAP_H
#define COCKOPOLIS_MAP_H
#include "includes.h"
#include "tile.h"

class Map {
private:
    std::vector<std::vector<Tile>> _map;
public:
    Map(size_t x, size_t y);
    Map(const char* path);
    void save(const char* path);
    std::vector<Tile>& operator[](size_t at);
};



#endif //COCKOPOLIS_MAP_H
