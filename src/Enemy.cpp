#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(char *symb, int xCoord, int yCoord) : _symb(symb),
                                                   _xCoord(xCoord),
                                                   _yCoord(yCoord),
                                                   xStartPos(xCoord),
                                                   yStartPos(yCoord) {}

void    Enemy::drawEnemy(WINDOW *win) {
    mvwaddstr(win, _yCoord, _xCoord, _symb);
}

void    Enemy::moveEnemy(char map[30][100], std::pair<int, int> playerCoord) {
    char    tmp[30][100];
    int     finx = std::get<0>(playerCoord);
    int     finy = std::get<1>(playerCoord);

    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 100; j++) {
            if (map[i][j] == '1')
                tmp[i][j] = WALL;
            else
                tmp[i][j] = BLANK;
        }
    }
    lee(tmp, _xCoord, _yCoord, finx, finy);
}

std::pair<int, int> Enemy::getCoords() {
    return (std::make_pair(_xCoord, _yCoord));
}

bool    Enemy::isCollide(std::pair<int, int> playerCoord) {
    if (std::get<0>(playerCoord) == _xCoord && std::get<1>(playerCoord) == _yCoord)
        return (true);
    return (false);
}

void    Enemy::setStartPos() {
    _xCoord = xStartPos;
    _yCoord = yStartPos;
}

Enemy::~Enemy() {}