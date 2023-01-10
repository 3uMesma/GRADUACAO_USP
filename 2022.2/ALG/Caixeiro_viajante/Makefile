all: conn.o dmconfig.o pathfinder.o main_runcodes.o
	gcc conn.o dmconfig.o pathfinder.o main_runcodes.o -o runcodes_run -Ofast
all_teste: conn.o main_teste.o dmconfig.o pathfinder.o
	gcc conn.o dmconfig.o pathfinder.o main_teste.o -o teste_run -Ofast
main_teste.o: main_teste.c
	gcc -c main_teste.c -o main_teste.o
main_runcodes.o: mainruncodes.c
	gcc -c mainruncodes.c -o main_runcodes.o
conn.o: Connector.c Connector.h dmconfig.o
	gcc -c Connector.c -o conn.o
dmconfig.o: DMconfig.c DMconfig.h
	gcc -c DMconfig.c -o dmconfig.o
pathfinder.o: Pathfinder.c Pathfinder.h #conn.o dmconfig.o
	gcc -c Pathfinder.c -o pathfinder.o
clear_teste:
	rm *.o main_teste
clear:
	rm *.o runcodes_run;
test:
	clear
	make clear_teste
	make all_teste
	make run_teste
run:
	./runcodes_run
run_teste:
	time ./teste_run

