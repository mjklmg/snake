#ifndef LOGIC_H
#define LOGIC_H


#include <stdbool.h>
#include "snake.h"

typedef struct Apple {
	int posX;
	int posY;
} Apple;

// checks if the direction is legal, e. g. u cannot move LEFT while moving RIGHT
_Bool isDirectionLegal(SnakeBody *body, DIRECTION inputDir);

// handles snakes movement
void moveSnake(SnakeBody *body, DIRECTION inputDir);

// checks if border was touched
_Bool touchedBorder(SnakeBody *body, int boardHeight, int boardWidth);

DIRECTION inputDirection(SnakeBody *body);

_Bool isAppleOnSnake(int appleX, int appleY, int snakeSegmentX, int snakeSegmentY);

Apple* initApple(int boardWidth, int boardHeight, SnakeBody *body);

#endif
