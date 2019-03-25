#include "Core.h"

Core::Core() : fail(false), win(false) {
	initNcurses();
	map = new Map();
	frames = 0;
}

bool    Core::Start() {
    while(!fail && !win){
		frames++;
		move();
		collision();
		draw();
		drawInterface();
    }
	end();
    return (true);
}

void	Core::end() {
	std::string tmp;
	int	 col;

	if (fail) {
		tmp = "FAIL";
		col = 8;
	}
	else if (win) {
		tmp = "WIN";
		col = 7;
	}

	wattron(splash, COLOR_PAIR(col));
	wborder(splash, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	mvwprintw(splash, H/2, W/2 - 4, tmp.c_str());
	wattroff(splash, COLOR_PAIR(col));
	wrefresh(splash);
	sleep(5);
	wclear(splash);
}

void	Core::draw() {
	werase(gameField);
	map->drawMap(gameField);
	map->drawObjects(gameField);
	wrefresh(gameField);
}

void   Core::drawInterface() {
	werase(interface);
	wattron(interface, COLOR_PAIR(4));
	wborder(interface, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wattroff(interface, COLOR_PAIR(4));
	wattron(interface, COLOR_PAIR(6));
	mvwprintw(interface, 2, 30, "Lives: %d", lives);
	mvwprintw(interface, 2, 60, "Score: %d", score);
	wattroff(interface, COLOR_PAIR(6));
	wrefresh(interface);
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
	splash = newwin(H, W, 0, 0);
	gameField = newwin(H, W, 0, 0);
	interface = newwin(5, 100, 30, 0);
	keypad(gameField, TRUE);
	nodelay(gameField, TRUE);
	curs_set(0);
	start_color();
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_CYAN);
	init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
}

void	Core::collision() {
	score = map->playerTreasureColl();
	lives = map->playerEnemyColl();

	if (map->isExit())
		win = true;
	else if (lives == 0)
		fail = true;
}

Core::~Core() {
	delete map;
	delwin(gameField);
	delwin(interface);
	delwin(splash);
	endwin();
}