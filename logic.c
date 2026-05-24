#include <stdbool.h>
#include <stdlib.h>
#include <ncurses.h>

#include "snake.h"
#include "logic.h"

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

void moveSnake(SnakeBody *body, DIRECTION inputDir, _Bool didSnakeEat){

	body->dir = inputDir;

	addHead(body);

	if (!didSnakeEat){
		deleteTail(body);
	}
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

_Bool touchedSelf(SnakeBody *body){

	int headX = body->head->posX;
	int headY = body->head->posY;

	SnakeSegment *current = body->head->next;

	int currentX; 
	int currentY;

	while(current){

		currentX = current->posX;
		currentY = current->posY;

		if (currentX == headX && currentY == headY){
			return true;
		}
		current = current->next;
	}

	return false;
}

DIRECTION inputDirection(SnakeBody *body){

    int key = getch();

    DIRECTION dir = body->dir; // keep current direction

    switch (key){
        case KEY_LEFT:
            if (isDirectionLegal(body, LEFT))
                dir = LEFT;
            break;

        case KEY_RIGHT:
            if (isDirectionLegal(body, RIGHT))
                dir = RIGHT;
            break;

        case KEY_UP:
            if (isDirectionLegal(body, UP))
                dir = UP;
            break;

        case KEY_DOWN:
            if (isDirectionLegal(body, DOWN))
                dir = DOWN;
            break;
    }

	flushinp();
    return dir;
}

_Bool isAppleOnSnake(int appleX, int appleY, int snakeSegmentX, int snakeSegmentY ){
	if (appleX == snakeSegmentX && appleY == snakeSegmentY){
		return true;
	}
	return false;
}

Apple* initApple(int boardHeight, int boardWidth, SnakeBody *body){


	Apple *apple = malloc(sizeof(Apple));

	SnakeSegment *snakeSegment = body->head;

	int snakeSegmentX;
	int snakeSegmentY;

	int appleX;
	int appleY;

	_Bool collision;
// apples position initialization, checking if its coliding with snake
	
	do {
// random generation of position, setting collision to false for now
		appleX = rand() % (boardWidth-2) + 1;
		appleY = rand() % (boardHeight-2) + 1;

		snakeSegment = body->head;
		collision = false;

// validiating if those coords collide with snake, if so, we generate new ones with a while loop
		while(snakeSegment){
			snakeSegmentX = snakeSegment->posX;
			snakeSegmentY = snakeSegment->posY;

			snakeSegment = snakeSegment->next;

			if (isAppleOnSnake(appleX, appleY, snakeSegmentX, snakeSegmentY)){
				collision = true;
			}
		}

	}while (collision);
	
	apple->posX = appleX;
	apple->posY = appleY;

	return apple;
}

// we will check if snake has eaten so we can decide if we delete tail this tick or not
// by usuing value of this funtion as an argument to moveSnake()
// double pointer to apple so u can initalize new apple after eating one
_Bool didSnakeEat(Apple **apple, SnakeBody *body, int boardHeight, int boardWidth){

	int appleX = (*apple)->posX;
	int appleY = (*apple)->posY;


	int snakeHeadX = body->head->posX;
	int snakeHeadY = body->head->posY;

	if (isAppleOnSnake(appleX, appleY, snakeHeadX, snakeHeadY)){
		free(*apple); // freeing memory used for an old apple
		*apple = initApple(boardHeight, boardWidth, body);
		return true;
	}

	return false;
}
