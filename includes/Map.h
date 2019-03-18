#pragma once

#include "pacman.h"

class Map
{
private:
    std::ifstream fin;
    std::string   mapRepr[30];
    WINDOW        *statMap;
public:
            Map();
    void    drawMap();
            ~Map();
};