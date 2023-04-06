hanoi.out : main.o stack.o
	gcc -g -Wall -Werror main.o stack.o -o hanoi.out

main.o : main.c
	gcc -g -Wall -Werror -c main.c

stack.o : stack.c
	gcc -g -Wall -Werror -c stack.c

clean:
	rm *.o
	rm *.out