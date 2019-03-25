#include "Map.h"

Map::Map() {
    fin.open("./maps/1.map");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 100; j++) {
            fin.get(mapRepr[i][j]);
            if (mapRepr[i][j] == '2')
                player = new Player("😐", j, i);
            else if (mapRepr[i][j] == '3')
                firstEnemy = new Enemy("😈", j, i);
            else if (mapRepr[i][j] == '4')
                secondEnemy = new Enemy("💀", j, i);
        }
        fin.ignore();
    }
    treasure = new Treasure("•", mapRepr);
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

void    Map::drawObjects(WINDOW *win) {
    treasure->drawTreasure(win);
    player->drawPlayer(win);
    firstEnemy->drawEnemy(win);
    secondEnemy->drawEnemy(win);
}

void    Map::moveObjects(int key, int frames) {
    player->movePlayer(mapRepr, key);
    if (frames % 200 == 0)
        firstEnemy->moveEnemy(mapRepr, player->getCoords());
    if (frames % 300 == 0)
        secondEnemy->moveEnemy(mapRepr, player->getCoords());
}

void    Map::playerTreasureColl() {
    treasure->delTreasure(player->getCoords());
}

int     Map::playerEnemyColl() {
    if (firstEnemy->isCollide(player->getCoords()) ||
        secondEnemy->isCollide(player->getCoords())) {
            firstEnemy->setStartPos();
            secondEnemy->setStartPos();
            player->setStartPos();
            player->setLives();
        }
    return (player->getLives());
}

Map::~Map() {
    delete player;
    delete treasure;
    delete firstEnemy;
    delete secondEnemy;
}