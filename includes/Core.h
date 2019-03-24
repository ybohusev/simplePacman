#pragma once

#include <unistd.h>
#include "pacman.h"
#include "Map.h"

class Core
{
private:
    WINDOW *interface;
    WINDOW *gameField;
    Map    *map;
    void   initNcurses();
    void   draw();
    void   move();
    void   collision();
public:
           Core();
    bool   Start();
           ~Core();
};