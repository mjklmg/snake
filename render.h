#ifndef RENDER_H

#include <ncurses.h>
#include "snake.h"

#define RENDER_H

WINDOW* initWindow(int WinHeight, int WinWidth, int WinStartY, int WinStartX);

void clearWindow(WINDOW *win);

void drawSnake(SnakeBody *snakeBody, WINDOW *win);

#endif
