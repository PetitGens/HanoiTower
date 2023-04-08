hanoi.out : main.o stack.o hanoi_engine.o
	gcc -g -Wall -Werror  stack.o hanoi_engine.o main.o -o hanoi.out

main.o : main.c
	gcc -g -Wall -Werror -c main.c

stack.o : stack.c
	gcc -g -Wall -Werror -c stack.c

hanoi_engine.o : hanoi_engine.h
	gcc -g -Wall -Werror -c hanoi_engine.c

clean:
	rm *.o
	rm *.out