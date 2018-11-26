#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int tam;
	int *elementos;
}Lista;

void printList(Lista lista){
        int i;
	printf("[");
        for(i=0;i<lista.tam;i++){
                printf("%d,",lista.elementos[i]);
        }
        printf("]\n");
}


Lista crearLista(int tam){
	Lista lista;
	lista.tam = tam;
	lista.elementos = (int*)calloc(tam,sizeof(int));
	return lista;
}

int aleatorio(int tam){
	return rand()%(tam);
}

void swap(Lista *list,int x, int y){
	int aux = list->elementos[x];
	list->elementos[x] = list->elementos[y];
	list->elementos[y] = aux;
}

void fillList(Lista *list,int caso){
	int i = 0;
	if(caso ==0){//peor caso
		for(i=0;i<list->tam;i++){
			list->elementos[i] = list->tam-i;
		}
	}
	else if(caso == 1){
		for(i=0;i<list->tam;i++){
			list->elementos[i] = aleatorio(list->tam);
		}
	}
	else if(caso == 2){
		for(i=0;i<list->tam;i++){
                	list->elementos[i] = i; //cambiar por aleatorio
                }
		//ordenar
		swap(list,(int) (list->tam-1)/2, list->tam-1);
	}
	else{
		printf("Error en el caso");

	}
}

