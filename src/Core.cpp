#include "Core.h"

Core::Core() {
	initNcurses();
	map = new Map();
}

bool    Core::Start() {
	// map->drawMap(gameField);
	// wrefresh(gameField);
    while(true){
		move();
		collision();
		draw();
    }
    return (true);
}

void	Core::draw() {
	werase(gameField);
	werase(interface);
	map->drawMap(gameField);
	map->drawObjects(gameField, interface);
	wrefresh(gameField);
	wrefresh(interface);
}

void	Core::move() {
	int key;
	if ((key = wgetch(gameField)) != ERR)
		map->moveObjects(gameField, key);
}

void	Core::initNcurses() {
    initscr();
	clear();
	noecho();
	cbreak();
	gameField = newwin(30, 100, 0, 0);
	interface = newwin(30, 20, 0, 101);
	nodelay(gameField, TRUE);
	keypad(gameField, TRUE);
	curs_set(0);
	start_color();
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
}

void	Core::collision() {
	map->playerTreasureColl(interface);
}

Core::~Core() {
	delete map;
	delwin(gameField);
	delwin(interface);
	endwin();
}