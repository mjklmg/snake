#ifndef SNAKE_H

#define SNAKE_H

typedef enum { UP, DOWN, LEFT, RIGHT} DIRECTION;

typedef struct SnakeSegment{
	int posX;
	int posY;
	struct SnakeSegment *next;
	struct SnakeSegment *prev;

}SnakeSegment;


typedef struct SnakeBody{
	SnakeSegment *head;
	SnakeSegment *tail;
	DIRECTION dir;
}SnakeBody;

SnakeSegment* createSnakeSegment(int X, int Y);

SnakeBody* initializeSnake(int TAIL_START_X, int TAIL_START_Y, int HEAD_START_X, int HEAD_START_Y, DIRECTION);

void addHead(SnakeBody *body);

void deleteTail(SnakeBody *body);

#endif
