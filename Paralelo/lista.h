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
        printf("]tam = %d\n",lista.tam);
}


Lista crearLista(int tam){
	Lista lista;
	lista.tam = tam;
	lista.elementos = (int*)calloc(tam,sizeof(int));
	return lista;
}

int aleatorio(int tam){
	return rand() % tam;
}

void swap(Lista *list,int x, int y){
	int aux = list->elementos[x];
	list->elementos[x] = list->elementos[y];
	list->elementos[y] = aux;
}

void fillList(Lista *list,int caso){
	int i = 0;
	if(list->tam == 0){
		exit(-1);
	}
	if(caso == 0){//peor caso
		for(i=0;i<list->tam;i++){
			list->elementos[i] = list->tam-i-1;
		}
		swap(list,(int) (list->tam-1)/2, list->tam-1);
	}
	else if(caso == 1){
		for(i=0;i<list->tam;i++){
			list->elementos[i] = aleatorio(list->tam);
		}
	}
	else if(caso == 2){
		for(i=0;i<list->tam;i++){
                	list->elementos[i] = i;
                }
	}
	else{
		exit(-1);
		printf("Error en el caso");

	}
}

