#include "Core.h"

Core::Core() {
	initNcurses();
	map = new Map();
	frames = 0;
}

bool    Core::Start() {
    while(true){
		frames++;
		move();
		collision();
		draw();
    }
    return (true);
}

void	Core::draw() {
	werase(gameField);
	map->drawMap(gameField);
	map->drawObjects(gameField);
	wrefresh(gameField);
}

void	Core::move() {
	int key = wgetch(gameField);
		map->moveObjects(key, frames);
}

void	Core::initNcurses() {
    initscr();
	clear();
	noecho();
	cbreak();
	gameField = newwin(30, 100, 0, 0);
	interface = newwin(30, 20, 0, 101);
	keypad(gameField, TRUE);
	nodelay(gameField, TRUE);
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
	map->playerTreasureColl();
	int lives = map->playerEnemyColl();

	// for (int i = 0; i < lives; i++)
		mvwprintw(interface, 0, 0, "Lives: %d", lives);
	wrefresh(interface);
}

Core::~Core() {
	delete map;
	delwin(gameField);
	delwin(interface);
	endwin();
}