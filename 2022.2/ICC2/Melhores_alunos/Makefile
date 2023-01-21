all: cadastro_alunos.o main.o
	gcc cadastro_alunos.o main.o -o tabela -std=c99 -Wall -lm
	
valgrind:
	 gcc -g -Wall -Werror *.c && valgrind ./a.out -s

cadastro_alunos.o:
	gcc -c cadastro_alunos.c -o cadastro_alunos.o -lm
	 
main.o:
	gcc -c main.c -o main.o -lm
	 
clean:
	rm *.o tabela

run:
	./tabela
