#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "render.h"
#include "ncurses.h"

#define TAIL_START_X 1
#define TAIL_START_Y 1
#define HEAD_START_X 2
#define HEAD_START_Y 1


#define WIN_START_Y 10
#define WIN_START_X 10
#define WIN_HEIGHT 20
#define WIN_WIDHT 50

int main(){

    SnakeBody *snakeBody = initializeSnake(TAIL_START_X, TAIL_START_Y, HEAD_START_X, HEAD_START_Y, LEFT);
    SnakeSegment *head = snakeBody->head;
    SnakeSegment *tail = snakeBody->tail;

	initscr();

	WINDOW *win = InitWindow(WIN_HEIGHT, WIN_WIDHT, WIN_START_Y, WIN_START_Y);
	addHead(snakeBody);
	
	DrawSnake(snakeBody, win);
	wrefresh(win);

    free(head);
    free(tail);
    free(snakeBody);

	getch();
	endwin();


	return 0;

}
