all: forkin.o shell.o
	gcc forkin.o shell.o

forkin.o: forkin.c forkin.h
	gcc -c forkin.c

shell.o: shell.c forkin.h
	gcc -c shell.c

run:
	./a.out 
