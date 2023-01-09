all: circulo.o ponto.o main.o
	gcc main.o circulo.o ponto.o -o p_e_c -std=c99 -Wall

ponto.o:
	gcc -c ponto.c -o ponto.o

circulo.o:
	gcc -c circulo.c -o circulo.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o p_e_c

run:
	./p_e_c
