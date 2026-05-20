#include <stdlib.h>
#include <stdio.h>
#include "snake.h"


SnakeSegment* createSnakeSegment(int X, int Y){
	SnakeSegment *CreatedSnakeSegment = malloc(sizeof(SnakeSegment));

	CreatedSnakeSegment->posX = X;
	CreatedSnakeSegment->posY = Y;
	CreatedSnakeSegment->next = NULL;
	CreatedSnakeSegment->prev = NULL;
	
	return CreatedSnakeSegment;

}

SnakeBody* initializeSnake(int TAIL_START_X, int TAIL_START_Y, int HEAD_START_X, int HEAD_START_Y, DIRECTION dir){

	SnakeBody *body = malloc(sizeof(SnakeBody));

	SnakeSegment *tail = createSnakeSegment(TAIL_START_X, TAIL_START_Y);
	SnakeSegment *head = createSnakeSegment(HEAD_START_X, HEAD_START_Y);
	tail->prev = head;
	head->next = tail;

	body->head = head;
	body->tail = tail;

	body->dir = dir;

	return body;
}

void addHead(SnakeBody *body){

	DIRECTION dir = body->dir;

	// allocating the memory for a new head, handling case if program runs out of heap, tho it would never happen as this game uses only so much memory
	SnakeSegment *NewHead = malloc(sizeof(SnakeSegment));

	if (NewHead == NULL) {
        // Handle the error gracefully instead of crashing
        fprintf(stderr, "Error: Out of memory!\n");
        exit(1); 
    }

	SnakeSegment *OldHead = body->head;

	NewHead->next = OldHead;
	NewHead->prev = NULL;

	switch (dir){
		// up / down
		case UP: 
			NewHead->posY = OldHead->posY-1;
			NewHead->posX = OldHead->posX;
			break;
		case DOWN: 
			NewHead->posY = OldHead->posY+1;
			NewHead->posX = OldHead->posX;
			break;
		// left / right
		case LEFT: 
			NewHead->posX = OldHead->posX-1;
			NewHead->posY = OldHead->posY;
			break;
		case RIGHT:
			NewHead->posX = OldHead->posX+1;
			NewHead->posY = OldHead->posY;
			break;
	}

	OldHead->prev=NewHead;
	body->head = NewHead;
}

void deleteTail(SnakeBody *body){
	SnakeSegment *tail = body->tail;

	SnakeSegment *newTail = tail->prev;
	newTail->next = NULL;
	body->tail=newTail;

	free(tail);
}
