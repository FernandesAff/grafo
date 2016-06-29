///grafo.h
///
///Faz a definição das estruturas usadas no módulo e os protótipos das funções.

#define WHITE 0
#define GREY 1

#include <stdio.h>
#include <stdlib.h>

typedef struct TipoNoAdj *TipoApontador;

typedef struct TipoNoAdj{
	int cidade;
	int distancia;
	TipoApontador prox;
}TipoNoAdj;

typedef struct{
	TipoApontador primeiro;
}TipoListaAdj;

typedef struct{
	TipoListaAdj listaAdj;
	int cor;
}TipoVertice;

void FGVazio (TipoVertice *, int);

void InserirAresta (TipoVertice *, int, int, int);

TipoVertice* PreencherGrafo(int *, char *);

void ImprimirGrafo (TipoVertice *, int);