all:programa limpa

programa:main.o grafo.o busca.o
	gcc main.o grafo.o busca.o -o grafo

main.o:main.c
	gcc -c main.c

grafo.o: grafo.c
	gcc -c grafo.c

busca.o: busca.c
	gcc -c busca.c		

limpa:
	rm *.o