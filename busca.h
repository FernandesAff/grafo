///grafo.h
///
///Faz a definição das estruturas usadas no módulo de busca e os protótipos das funções.

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void DFS (TipoVertice *, int, int, int, int *, int);

int VerificarCidades (TipoVertice *, int);

void CopiaVetor (int *, int *, int);

void ImprimirSaida(TipoVertice *, int *, int);

void BuscaMT (TipoVertice *,int, int);