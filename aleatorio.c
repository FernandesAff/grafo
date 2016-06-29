#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	int i,j,x,y,distancia;
	FILE *fp;

	fp=fopen("entradaArq100.txt","w");
	fprintf(fp, "100\n");

	for (i=0;i<100;i++){
		distancia=1+rand()%10;
		fprintf(fp, "%d %d %d\n", i,i+1,distancia);
		x=1+rand()%5;
		for(j=0;j<x;j++){
			y=50+j;
			distancia=1+rand()%10;
			if(i<10)fprintf(fp, "%d %d %d\n", i,y,distancia);	
		}
	}
	fclose(fp);
	return 0;
}