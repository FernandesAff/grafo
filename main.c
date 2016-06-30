///main.c
///
///Gerencia os dados inseridos pelo getopt e faz a chamada das funções de entrada,
///busca e saída do programa.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "busca.h"

///Função que mostra uma tela de ajuda ao usuário.

void show_help(char *name) {
    fprintf(stderr, "\
            [uso] %s <opcoes>\n\n\
            -e	ENTRADA    	recebe o nome do arquivo de entrada.\n\
            -o	ORIGEM		recebe a cidade de origem.\n", name);
    exit(-1) ;
}

//Função que gerencia as outras e organiza a ordem de execução do programa. 

int main (int argc, char **argv){
	int opt, origem, numCidades;
	char *entradaArq;
	TipoVertice *vertice;

	if ( argc < 2){///Mostra as opcoes de execucao do programa no terminal
		printf("Numero insuficiente de opcoes, insira ao menos duas:\n\n" );
		show_help(argv[0]);
	}

	while ((opt=getopt(argc, argv, "he:o:"))>0){
		switch (opt){
			case 'e':
				entradaArq=optarg;
				break;
			case 'o':
				origem = atoi(optarg);
				break;	
			default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: '%c'\n", optopt) ;
                return -1 ;	
		}
	}

	vertice=PreencherGrafo(&numCidades, entradaArq);
	if(origem<0 || origem>=numCidades){
		printf("Origem incorreta\n");
		return 0;
	}
	BuscaMT(vertice,origem,numCidades);
	EsvaziarGrafo(vertice, numCidades);
	return 0;
}