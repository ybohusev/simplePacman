#pragma once

#include <unistd.h>
#include "pacman.h"
#include "Map.h"

class Core
{
private:
    bool   fail;
    bool   win;
    int    lives;
    int    score;

    WINDOW *interface;
    WINDOW *gameField;
    WINDOW *splash;
    Map    *map;

    void   initNcurses();
    void   draw();
    void   drawInterface();
    void   move();
    void   collision();

    int    frames;
public:
           Core();
    bool   Start();
    void   end();
           ~Core();
};