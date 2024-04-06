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

Map::Map(const char *path) {
    FILE* fp = fopen(path, "rb");
    if (!fp) {
        throw file_does_not_exist();
    }
    map_file f{};
    if (fread(&f, sizeof(f), 1, fp) != 1) {
        throw file_does_not_exist();
    }
    for (int i = 0; i < f.y; ++i) {
        _map.emplace_back();
        for (int j = 0; j < f.x; ++j) {
            _map[i].emplace_back("grassland.png", (hood_card_descr::hood_type)f.tiles[i][j].type, (hood_card_descr::hood_color)f.tiles[i][j].color);
        }
    }
    fclose(fp);
}

void Map::save(const char *path) {
    map_file f{};
    f.y = _map.size();
    f.x = _map[0].size();
    for (int i = 0; i < _map.size(); ++i) {
        for (int j = 0; j < _map[i].size(); ++j) {
            f.tiles[i][j] = _map[i][j].get_tile_info();
        }
    }
    FILE* fp = fopen(path, "wb");
    if (!fp) {
        throw file_does_not_exist();
    }
    fwrite(&f, sizeof(f), 1, fp);
    fclose(fp);
}
