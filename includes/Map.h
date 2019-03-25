#pragma once

#include "pacman.h"
#include "Player.h"
#include "Treasure.h"
#include "Enemy.h"

class Map
{
private:
    std::ifstream fin;
    char          mapRepr[30][100];
    Player        *player;   
    Treasure      *treasure;
    Enemy         *firstEnemy;
    Enemy         *secondEnemy;
public:
            Map();
    void    drawMap(WINDOW *win);
    void    drawObjects(WINDOW *win);
    void    moveObjects(int key, int frames);
    void    playerTreasureColl();
    int     playerEnemyColl();
            ~Map();
};