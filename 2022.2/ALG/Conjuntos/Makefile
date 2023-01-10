all: main.o tree.o conjunto.o item.o
	gcc main.o tree.o conjunto.o item.o -o runnable
main.o: main.c
	gcc -c main.c -o main.o
tree.o: tree.c tree.h
	gcc -c tree.c -o tree.o
conjunto.o: conjunto.c conjunto.h
	gcc -c conjunto.c -o conjunto.o
item.o: item.c item.h
	gcc -c item.c -o item.o
clear:
	rm *.o runnable
run:
	./runnable
test:
	clear
	make clear
	make all
	make run