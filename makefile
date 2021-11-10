app: main.c ca.c ca.h
	gcc main.c ca.c ca.h -o gol

dca1d.c: ca.h
	gcc -c ca.c