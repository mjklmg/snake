#ifndef LOGIC_H
#define LOGIC_H


#include <stdbool.h>
#include "snake.h"

// checks if the direction is legal, e. g. u cannot move LEFT while moving RIGHT
_Bool isDirectionLegal(SnakeBody *body, DIRECTION inputDir);

// handles snakes movement
void moveSnake(SnakeBody *body, DIRECTION inputDir);

// checks if border was touched
_Bool touchedBorder(SnakeBody *body, int boardHeight, int boardWidth);

#endif
