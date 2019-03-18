#pragma once

#include "pacman.h"
#include "Map.h"

class Core
{
private:
    WINDOW *interface;
    Map     *map;
    void initNcurses();
public:
            Core();
    bool    Start();
            ~Core();
};