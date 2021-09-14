app: main.c dca1d.c dca1d.h
	gcc main.c dca1d.c dca1d.h -o odca.out

dca1d.c: dca1d.h
	gcc -c dca1d.c