#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#include "snake.h"
#include "render.h"
#include "logic.h"

#define TAIL_START_X 1
#define TAIL_START_Y 1
#define HEAD_START_X 2
#define HEAD_START_Y 1

// board 50x20
#define WIN_START_Y 10
#define WIN_START_X 10
#define WIN_HEIGHT 22
#define WIN_WIDHT 22

void freeGame(SnakeBody *body){
	SnakeSegment *segment = body->head;

	while (segment){
		SnakeSegment *current = segment;
		segment = segment->next;
		free(current);
	}
	free(body);
}

int main(){

	// initilization of a snake
    SnakeBody *body = initializeSnake(TAIL_START_X, TAIL_START_Y, HEAD_START_X, HEAD_START_Y, RIGHT);
	// init of an apple
	Apple *apple = initApple(WIN_HEIGHT, WIN_WIDHT, body);

	// initialization of a window
	initscr();
	keypad(stdscr, TRUE);
	noecho(); //Don't echo keypresses

	WINDOW *win = initWindow(WIN_HEIGHT, WIN_WIDHT, WIN_START_Y, WIN_START_X);
	nodelay(stdscr, true);

	//game loop
	while (touchedBorder(body, WIN_HEIGHT, WIN_WIDHT)==false){

		clearWindow(win);

		DIRECTION dir = inputDirection(body);

		moveSnake(body, dir);

		drawSnake(body, win);

		drawApple(apple, win);

		wrefresh(win);

		usleep(200000);
	}	

	//feeing memory
	freeGame(body);
	delwin(win);
	endwin();

	return 0;

}
