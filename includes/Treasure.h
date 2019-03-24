#pragma once

#include "pacman.h"
#include <vector>

class Treasure
{
private:
    std::vector<std::pair<int, int>> _coords;
    char                             *_symbol;
public:
            Treasure();
            Treasure(char *symbol, char map[30][100]);
    
    void    delTreasure(std::pair<int, int> playerCoords);
    void    drawTreasure(WINDOW *win, WINDOW *test);
    ~Treasure();
};