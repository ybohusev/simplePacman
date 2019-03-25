#include "Map.h"

Map::Map() {
    fin.open("./maps/1.map");
    std::string tmp;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 100; j++) {
            fin.get(mapRepr[i][j]);
            if (mapRepr[i][j] == '2')
                player = new Player("😐", j, i);
            else if (mapRepr[i][j] == '3')
                firstEnemy = new Enemy("😈", j, i);
            else if (mapRepr[i][j] == '4')
                secondEnemy = new Enemy("💀", j, i);
            else if (mapRepr[i][j] == '5') {
                yExit = i;
                xExit = j;
            }
        }
        fin.ignore();
    }
    treasure = new Treasure("•", mapRepr);
    fin.close();
}

void    Map::drawMap(WINDOW *win) {
    for (int i = 0; i < 30; i++) {
        for(int j = 0; j < 100; j++) {
            if (mapRepr[i][j] == '1') {
                wattron(win, COLOR_PAIR(7));
                mvwaddch(win, i, j, ' ');
                wattroff(win, COLOR_PAIR(7));
            }
            else if (mapRepr[i][j] == '5') {
                wattron(win, COLOR_PAIR(1));
                mvwaddch(win, i, j, ' ');
                wattroff(win, COLOR_PAIR(1));
            }
        }
    }
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

int    Map::playerTreasureColl() {
    if (treasure->delTreasure(player->getCoords()))
        player->setScore();
    return (player->getScore());
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

bool    Map::isExit() {
    std::pair<int, int> playerCoord = player->getCoords();
    if (xExit == std::get<0>(playerCoord) &&
        yExit == std::get<1>(playerCoord))
        return (true);
    return (false);
}

Map::~Map() {
    delete player;
    delete treasure;
    delete firstEnemy;
    delete secondEnemy;
}