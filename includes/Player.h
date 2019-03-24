#pragma once

#include "pacman.h"

class Player
{
private:
    char* _symb;
    int     _xCoord;
    int     _yCoord;
public:
            Player();
            Player(char *symb, int xCoord, int yCoord);

    void    drawPlayer(WINDOW *win);
    void    movePlayer(WINDOW *win, char map[30][100], int key);
    std::pair<int, int> getCoords();
    ~Player();
};