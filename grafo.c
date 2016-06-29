/// grafo.c
///
///	Implementa as funções referentes a um grafo.

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

///Função que inicializa o grafo, ou seja, cria listas  de adjacência vazias em um 
///vetor que as contém.

void FGVazio (TipoVertice *vertice, int numCidades){
	int i;

	for(i=0;i<numCidades;i++){
		vertice[i].listaAdj.primeiro=NULL;
		vertice[i].cor=WHITE;
	}
}

///Função que insere uma aresta no grafo.

void InserirAresta (TipoVertice *vertice, int cidade1, int cidade2, int distancia){
	TipoApontador novo;

	novo=(TipoApontador) malloc (sizeof (TipoNoAdj));
	novo->cidade=cidade2;
	novo->distancia=distancia;
	novo->prox=vertice[cidade1].listaAdj.primeiro;
	vertice[cidade1].listaAdj.primeiro=novo;
}

///Função que inicializa um arquivo de texto e inicializa os dados contidos nele, 
///preenchendo o grafo.

TipoVertice* PreencherGrafo(int *numCidades, char *entradaArq){
	int cidade1, cidade2, distancia;
	FILE *fp;
	TipoVertice *vertice;

	fp=fopen(entradaArq, "r+");
	fscanf(fp,"%d\n", numCidades);
	vertice=(TipoVertice *) malloc ((*numCidades)*sizeof(TipoVertice));
	FGVazio(vertice, *numCidades);

	while(fscanf(fp,"%d %d %d\n", &cidade1, &cidade2, &distancia)!=EOF){
		InserirAresta(vertice, cidade1, cidade2, distancia);
		InserirAresta(vertice, cidade2, cidade1, distancia);
	}
	fclose(fp);
	return vertice;
}

///Função que imprime o grafo na tela.

void ImprimirGrafo (TipoVertice *vertice, int numCidades){
	int i;
	TipoApontador aux;

	for (i=0;i<numCidades;i++){
		printf("%d\n", i);
		aux=vertice[i].listaAdj.primeiro;
		while (aux!=NULL){
			printf("%d %d\n", aux->cidade, aux->distancia);
			aux=aux->prox;
		}	
		printf("\n");	
	}
}