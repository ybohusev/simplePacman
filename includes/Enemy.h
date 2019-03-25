#pragma once

#include "pacman.h"
#include "Lee.h"

class Enemy
{
private:
    char*   _symb;
    int     _xCoord;
    int     _yCoord;
    int     xStartPos;
    int     yStartPos;
public:
            Enemy();
            Enemy(char *symb, int xCoord, int yCoord);

    void    drawEnemy(WINDOW *win);
    void    moveEnemy(char map[30][100], std::pair<int, int> playerCoord);
    bool    isCollide(std::pair<int, int> playerCoord);
    void    setStartPos();
    std::pair<int, int> getCoords();
    ~Enemy();
};