all: circulo.o ponto.o main.o
	gcc main.o circulo.o ponto.o -o p_e_c -std=c99 -Wall -lm 

ponto.o: ponto.c ponto.h
	gcc -c ponto.c -o ponto.o

circulo.o: circulo.c circulo.h
	gcc -c circulo.c -o circulo.o

main.o: circulo.c circulo.h
	gcc -c main.c -o main.o

clean:
	rm *.o p_e_c

run:
	./p_e_c
