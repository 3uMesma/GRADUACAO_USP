all: item.o fila.o main.o
	gcc item.o fila.o main.o -o fila -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

filaencadeada.o:
	gcc -c fila.c -o fila.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o fila

run:
	./fila
