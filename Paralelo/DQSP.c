#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "lista.h"
#include "paralelo.h"
#include <string.h>

#define TAM 16300
#define CASO 1 //0 peor caso 1 promedio 2 mejor
void generador(int caso,char archivo[]){
	int i = 0;
	Lista A;
	long double tiempo; 
	FILE *fp = fopen(archivo,"w+");
	for(i=1;i<=TAM;i++){
		tiempo = 0;
		A = crearLista(i);
		fillList(&A,caso);
		//printf("Lista original %d\n",i);
		//printList(A);
		tiempo = omp_get_wtime();
		doubleQuickSort(&A);
		tiempo = omp_get_wtime() - tiempo;

		fprintf(fp,"%d,%Lf\n",A.tam,tiempo);	
		//printf("Lista ordenada %d\n",i);
		//printList(A);
		if(i<TAM)
			free(A.elementos);
	}
	printf("termine un caso");
	fclose(fp);
	free(A.elementos);
}
int main(){
	generador(0,"Peor.txt");
	generador(1,"PromedioP.txt");
	generador(2,"MejorP.txt");
	return 0;
}
