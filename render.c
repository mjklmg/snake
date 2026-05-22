#include <ncurses.h>

#include "snake.h"
#include "logic.h"


WINDOW* initWindow(int WinHeight, int WinWidth, int WinStartY, int WinStartX) {
	WINDOW *win = newwin(WinHeight, WinWidth, WinStartY, WinStartX);
	refresh();
	box(win, 0, 0);
	wrefresh(win);
	return win;
}
void clearWindow(WINDOW *win){
	wclear(win)	;
	box(win, 0, 0);
	wrefresh(win);
}

void drawSnake(SnakeBody *body, WINDOW *win){

	SnakeSegment *segment = body->head;

	while (segment){
		mvwprintw(win, segment->posY, segment->posX, "o");
		segment = segment->next;
	}
};

void drawApple(Apple *apple, WINDOW *win){
	mvwprintw(win, apple->posY, apple->posX, "@");
}

