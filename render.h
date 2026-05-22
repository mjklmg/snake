#ifndef RENDER_H

#define RENDER_H

#include <ncurses.h>

#include "snake.h"
#include "logic.h"

WINDOW* initWindow(int WinHeight, int WinWidth, int WinStartY, int WinStartX);

void clearWindow(WINDOW *win);

void drawSnake(SnakeBody *snakeBody, WINDOW *win);

void drawApple(Apple *apple, WINDOW *win);

#endif
