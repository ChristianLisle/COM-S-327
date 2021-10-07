app: main.c ca.c ca.h
	gcc main.c ca.c ca.h -o odca.out

dca1d.c: ca.h
	gcc -c ca.c