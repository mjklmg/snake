snake: main.c snake.c render.c
	gcc -o snake main.c snake.c render.c -lncurses

clean:
	rm -rf snake
