#include "Treasure.h"

Treasure::Treasure() {}
Treasure::Treasure(char *symbol, char map[30][100]) :_symbol(symbol) {
    int x[2];
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] == '0' && j % 2 != 0) {
                x[0] = i;
                x[1] = j;
                _coords.push_back(std::make_pair(i, j)); 
            }
        }
    }
}

void    Treasure::drawTreasure(WINDOW *win) {
    for (std::vector<std::pair<int, int>>::iterator it = _coords.begin();
         it != _coords.end(); ++it) {
        mvwaddstr(win, std::get<0>(*it), std::get<1>(*it), _symbol);
    }
    
}

void    Treasure::delTreasure(std::pair<int, int> playerCoords) {
     for (std::vector<std::pair<int, int>>::iterator it = _coords.begin();
                                            it != _coords.end(); it++) {
        if (std::get<0>(playerCoords) == std::get<1>(*it) && 
            std::get<1>(playerCoords) == std::get<0>(*it)) {
            _coords.erase(it);
            break ;
        }
    }
}

Treasure::~Treasure() {
}