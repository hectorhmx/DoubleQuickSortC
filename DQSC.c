#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "serial.h"

int main(){
	Lista lista = crearLista(2000);
	int i;
	for(i=0;i<5;i++){
		lista.elementos[i] = i;
	}
	fillList(&lista,0);
	printList(lista);
	doubleQuickSort(&lista);
	printList(lista);
	return 0;
}
