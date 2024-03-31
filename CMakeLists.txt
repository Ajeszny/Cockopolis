cmake_minimum_required(VERSION 3.27)
project(Cockopolis)

set(CMAKE_CXX_STANDARD 23)

add_executable(Cockopolis main.cpp
        includes.h
        window.cpp
        window.h
        texture.cpp
        texture.h
        player.cpp
        player.h
        map.cpp
        map.h
        tile.cpp
        tile.h
        hood.cpp
        hood.h)

target_link_libraries(Cockopolis "SDL2main" "SDL2" "SDL2_image")
