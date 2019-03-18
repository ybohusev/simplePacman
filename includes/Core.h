#pragma once

#include <ncurses.h>
#include "pacman.h"

class Core
{
private:
    WINDOW *interface;
    
    void initNcurses();
public:
            Core();
    bool    Start();
            ~Core();
};