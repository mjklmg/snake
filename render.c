#include "ncurses.h"
#include "snake.h"

WINDOW* InitWindow(int WinHeight, int WinWidth, int WinStartY, int WinStartX) {
	WINDOW *win = newwin(WinHeight, WinWidth, WinStartY, WinStartX);
	refresh();
	box(win, 0, 0);
	wrefresh(win);
	return win;
}

void DrawSnake(SnakeBody *snakeBody, WINDOW *win){

	SnakeSegment *segment = snakeBody->head;

	while (segment){
		mvwprintw(win, segment->posY, segment->posX, "o");
		segment = segment->next;
	}
};

