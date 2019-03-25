#pragma once

#include "pacman.h"

class Player
{
private:
    char* _symb;
    int     _xCoord;
    int     _yCoord;
    int     xStartPos;
    int     yStartPos;
    int     lives;
    int     score;
public:
            Player();
            Player(char *symb, int xCoord, int yCoord);

    void    drawPlayer(WINDOW *win);
    void    movePlayer(char map[30][100], int key);
    std::pair<int, int> getCoords();
    void    setStartPos();
    int     getLives();
    int     getScore();
    void    setScore();
    void    setLives();
    ~Player();
};