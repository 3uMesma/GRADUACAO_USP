all: cadastro.o lista.o login.o main.o
	gcc cadastro.o lista.o login.o main.o -o total -std=c99 -Wall -lm
	
valgrind:
	 gcc -g -Wall -Werror *.c && valgrind ./a.out

cadastro.o:
	gcc -c cadastro.c -o cadastro.o -lm

lista.o:
	gcc -c lista.c -o lista.o -lm

login.o:
	gcc -c login.c -o login.o -lm
	 
main.o:
	gcc -c main.c -o main.o -lm
	 
clean:
	rm *.o total

run:
	./total