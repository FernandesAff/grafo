///busca.c
///
///Implementa as funções que buscam o caminho mais curto a se percorrer e imprime a saída.

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

///Variáveis globais estáticas que guardam o menor caminho a se percorrer e sua distância total.

static int menorDistancia=-1;
static int *menorCaminho;

///Função que verifica se a busca passou por todos os vértices do grafo.

int VerificarCidades (TipoVertice *vertice, int numCidades){
	int cinza=0;

	while (cinza<numCidades && vertice[cinza].cor==GREY){
		cinza++;
	}
	if (cinza==numCidades)return 1;
	else return 0;
}

///Função que copia os dados de um vetor com os dados de um determinado caminho para o vetor que
///deve conter o menor caminho.

void CopiaVetor (int *caminho, int *menorCaminho, int tamanho){
	int i;

	for(i=0;i<tamanho;i++){
		menorCaminho[i]=caminho[i];
	}
}

///Função que faz uma busca por profundidade no grafo, alterando a marcação no vértice com todas
///as adjacências já verificadas, o tornando branco e não preto. Isso faz com que o algoritmo
///percorra todos os caminhos do grafo.

void DFS (TipoVertice *vertice, int origem, int numCidades, int distancia, int *caminho, int i){
	TipoApontador atual;

	caminho[i]=origem;
	i++;

	///Verifica se o caminho que está sendo percorrido não está maior que o menor caminho já computado,
	///garantindo assim uma poda nos dados a serem verificados e aumentando a eficiência.

	if(menorDistancia!=-1 && distancia>menorDistancia) return;

	vertice[origem].cor=GREY;
	atual=vertice[origem].listaAdj.primeiro;
	while(atual!=NULL){
		if(vertice[atual->cidade].cor==WHITE){
			DFS(vertice, atual->cidade, numCidades,distancia+atual->distancia, caminho, i);
		}	
		atual=atual->prox;
	}
	if ((VerificarCidades(vertice, numCidades)==1 && distancia<menorDistancia) || (VerificarCidades(vertice, numCidades)==1 && menorDistancia==-1)){
		menorDistancia=distancia;
		CopiaVetor(caminho, menorCaminho, numCidades);
	}
	vertice[origem].cor=WHITE;
}

///Função que imprime a saída do programa. Contém o caminho mais curto, a distância total desse
///caminho e as distâncias parciais entre cada cidade. 

void ImprimirSaida(TipoVertice *vertice, int *menorCaminho, int numCidades){
	TipoApontador atual;
	int i;

	printf("\n");
	if(menorDistancia!=-1){
		for(i=0;i<numCidades-1;i++){
			atual=vertice[menorCaminho[i]].listaAdj.primeiro;
			while(atual->cidade!=menorCaminho[i+1]){
				atual=atual->prox;
			}
			printf("Distância entra as cidades %d e %d: %d\n", menorCaminho[i], menorCaminho[i+1], atual->distancia);
		}
		printf("\nCaminho mais curto:\n%d", menorCaminho[0]);
		for (i=1;i<numCidades;i++){
			printf("-%d", menorCaminho[i]);
		}
		printf("\n\nDistância Total: %d\n\n", menorDistancia);
	}
	else{
		printf("\nPartindo dessa cidade não é possível passar por todas as outras sem passar duas vezes em uma mesma cidade.\n\n");
	}
}	

///Função que inicializa a busca pelo melhor trajeto e gerencia a impressão das saídas do programa.

void BuscaMT (TipoVertice *vertice, int origem, int numCidades){
	int caminho[numCidades],i;

	menorCaminho=(int*)malloc(numCidades*sizeof(int));
	DFS (vertice, origem, numCidades, 0, caminho, 0);
	ImprimirSaida(vertice,menorCaminho,numCidades);
}