all: ag.o sort.o main.o
	gcc ag.o sort.o main.o -o genetico -std=c99 -Wall -lm
	
valgrind:
	 gcc -g -Wall -Werror *.c && valgrind ./a.out

ag.o:
	gcc -c ag.c -o ag.o -lm

sort.o:
	gcc -c sort.c -o sort.o -lm
	 
main.o:
	gcc -c main.c -o main.o -lm
	 
clean:
	rm *.o genetico

run:
	./genetico