#include <stdbool.h>
#include "snake.h"

_Bool isDirectionLegal(SnakeBody *body, DIRECTION inputDir){

	// checks if the direction is legal, e. g. u cannot move LEFT while moving RIGHT

	DIRECTION currentDir = body->dir;
	switch (inputDir) {
		case UP:
			if (currentDir==DOWN){
				return false;
			}
			break;
		case DOWN:
			if (currentDir==UP){
				return false;
			}
			break;
		case LEFT:
			if (currentDir==RIGHT){
				return false;
			}
			break;
		case RIGHT:
			if (currentDir==LEFT){
				return false;
			}
			break;
	}
	
	return true;
}

void moveSnake(SnakeBody *body, DIRECTION inputDir){

	body->dir = inputDir;

	addHead(body);
	deleteTail(body);
}

_Bool touchedBorder(SnakeBody *body, int boardHeight, int boardWidth ){

	// importing head coordinates
	int X = body->head->posX;
	int Y = body->head->posY;

	// checking if head touched the border
	if (X<=0 || X>=boardWidth-1){
		return true;
	}
	else if (Y<=0 || Y>=boardHeight-1){
		return true;
	}
	return false;
}
