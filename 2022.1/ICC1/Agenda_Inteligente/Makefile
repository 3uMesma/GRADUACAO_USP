all: funcoes.o main.o
	gcc funcoes.o main.o -o agenda -std=c99 -Wall -lm

funcoes.o:
	gcc -c funcoes.c -o funcoes.o -lm
	 
main.o:
	gcc -c main.c -o main.o -lm
	 
clean:
	rm *.o agenda

run:
	./agenda
