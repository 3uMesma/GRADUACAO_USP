all: busca.o main.o
	gcc busca.o main.o -o busca_vinho -std=c99 -Wall -lm
	
valgrind:
	 gcc -g -Wall -Werror *.c && valgrind ./a.out -s

busca.o:
	gcc -c busca.c -o busca.o -lm
	 
main.o:
	gcc -c main.c -o main.o -lm
	 
clean:
	rm *.o busca_vinho

run:
	./busca_vinho
