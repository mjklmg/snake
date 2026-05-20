snake: main.c snake.c render.c logic.c
	gcc -o snake main.c snake.c render.c logic.c -lncurses -Wall -Wextra -g
clean:
	rm -rf snake
