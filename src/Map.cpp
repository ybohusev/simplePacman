#include "Map.h"

Map::Map() {
    fin.open("./maps/1.map");
    for (int i = 0; !fin.eof(); i++) {
        fin >> mapRepr[i];
    }
    fin.close();
    statMap = newwin(30, 100, 0, 0);
}

void    Map::drawMap() {
    for (int i = 0; i < 30; i++) {
        for(int j = 0; j < 100; j++)
        {
            if (mapRepr[i][j] == '1') {
                wattron(statMap, COLOR_PAIR(7));
                mvwaddch(statMap, i, j, ' ');
                wattroff(statMap, COLOR_PAIR(7));
            }
            else if (mapRepr[i][j] == '2')
                mvwprintw(statMap, i, j, "\u2639");
        }
    }
    wrefresh(statMap);
}

Map::~Map() {
    delwin(statMap);
}