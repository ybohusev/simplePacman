#include "Map.h"

Map::Map() {
    // std::vector<int[2]> treas;

    fin.open("./maps/1.map");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 100; j++) {
            fin.get(mapRepr[i][j]);
            if (mapRepr[i][j] == '2')
                player = new Player("😐", j, i);
        }
        fin.ignore();
    }
    treasure = new Treasure("۰", mapRepr);
    fin.close();
}

void    Map::drawMap(WINDOW *win) {
    wattron(win, COLOR_PAIR(7));
    for (int i = 0; i < 30; i++) {
        for(int j = 0; j < 100; j++) {
            if (mapRepr[i][j] == '1')
                mvwaddch(win, i, j, ' ');
        }
    }
    wattroff(win, COLOR_PAIR(7));
}

void    Map::drawObjects(WINDOW *win, WINDOW *test) {
    treasure->drawTreasure(win, test);
    player->drawPlayer(win);

    std::pair<int, int> tmp = player->getCoords();
    mvwprintw(test, 28, 0, "TEST X %d, Y %d", std::get<0>(tmp), std::get<1>(tmp));
}

void    Map::moveObjects(WINDOW *win, int key) {
    player->movePlayer(win, mapRepr, key);
}

void    Map::playerTreasureColl(WINDOW *test) {
    treasure->delTreasure(player->getCoords());
}

Map::~Map() {
    delete player;
    delete treasure;
}