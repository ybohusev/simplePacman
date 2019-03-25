#include "Player.h"

Player::Player() {}

Player::Player(char *symb, int xCoord, int yCoord) : _symb(symb),
                                                       _xCoord(xCoord),
                                                       _yCoord(yCoord),
                                                       xStartPos(xCoord),
                                                       yStartPos(yCoord),
                                                       score(0),
                                                       lives(3) {}

void    Player::drawPlayer(WINDOW *win) {
    mvwaddstr(win, _yCoord, _xCoord, _symb);
}

void    Player::movePlayer(char map[30][100], int key) {
    switch(key)
    {
        case KEY_UP:
            if (map[_yCoord - 1][_xCoord] != '1')
                _yCoord--;
            break;
        case KEY_DOWN:
            if (map[_yCoord + 1][_xCoord] != '1')
                _yCoord++;
            break;
        case KEY_LEFT:
            if (map[_yCoord][_xCoord - 2] != '1')
                _xCoord -= 2;
            break;
        case KEY_RIGHT:
            if (map[_yCoord][_xCoord + 2] != '1')
                _xCoord += 2;
            break;
    }
}

std::pair<int, int> Player::getCoords() {
    return (std::make_pair(_xCoord, _yCoord));
}

void    Player::setStartPos() {
    _xCoord = xStartPos;
    _yCoord = yStartPos;
}

int     Player::getLives() {
    return(lives);
}

int     Player::getScore() {
    return (score);
}

void    Player::setScore() {
    score += 20;
}

void    Player::setLives() {
    --lives;
}

Player::~Player() {}