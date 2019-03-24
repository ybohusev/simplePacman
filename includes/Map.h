#pragma once

#include "pacman.h"
#include "Player.h"
#include "Treasure.h"

class Map
{
private:
    std::ifstream fin;
    char          mapRepr[30][100];
    Player        *player;   
    Treasure      *treasure;
public:
            Map();
    void    drawMap(WINDOW *win);
    void    drawObjects(WINDOW *win, WINDOW *test);
    void    moveObjects(WINDOW *win, int key);
    void    playerTreasureColl(WINDOW *test);
            ~Map();
};