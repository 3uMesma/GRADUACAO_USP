all: rede.o main.o
	gcc rede.o main.o -o antirede -std=c99 -Wall

rede.o:
	gcc -c rede.c -o rede.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o antirede

run:
	./antirede
