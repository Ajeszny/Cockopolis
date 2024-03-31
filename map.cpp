//
// Created by ajeszny on 29.03.24.
//

#include "map.h"

Map::Map(size_t x, size_t y) {
    for (int i = 0; i < y; ++i) {
        _map.emplace_back();
        for (int j = 0; j < x; ++j) {
            _map[i].push_back(Tile());
        }
    }
}

std::vector<Tile> &Map::operator[](size_t at) {
    return _map[at];
}
