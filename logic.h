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
void moveSnake(SnakeBody *body, DIRECTION inputDir, _Bool didSnakeEat);

// checks if border was touched
_Bool touchedBorder(SnakeBody *body, int boardHeight, int boardWidth);

// check if snake touched itself lolololol
_Bool touchedSelf(SnakeBody *body);

// handling user input as direction
DIRECTION inputDirection(SnakeBody *body);

// checking if apple colides with a snake segment
_Bool isAppleOnSnake(int appleX, int appleY, int snakeSegmentX, int snakeSegmentY);

// initializing apple, checking collision with snake body
Apple* initApple(int boardWidth, int boardHeight, SnakeBody *body);

// checking if snake eaten apple, returning true or false for the sake of checking if snake deletes 
// his tale
_Bool didSnakeEat(Apple **apple, SnakeBody *body, int boardHeight, int boardWidth);

#endif
