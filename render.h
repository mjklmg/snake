#ifndef RENDER_H

#include "ncurses.h"
#include "snake.h"

#define REDNER_H

WINDOW* InitWindow(int WinHeight, int WinWidth, int WinStartY, int WinStartX);
void DrawSnake(SnakeBody *snakeBody, WINDOW *win);

#endif
