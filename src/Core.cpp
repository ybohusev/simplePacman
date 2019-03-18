#include "Core.h"

Core::Core() {
    initNcurses();
	interface = newwin(5, 5, 10, 10);
	box(interface, 0, 0);
	wrefresh(interface);

}

bool    Core::Start() {
    while(true){
        /* code */
    }
    return (true);
}

void Core::initNcurses() {
    initscr();
	// raw();
	// keypad(stdscr, TRUE);
	noecho();
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
	// printw("Hello\n");
	// refresh();
	// getch();
	// endwin();
}

Core::~Core() {
	delwin(interface);
}