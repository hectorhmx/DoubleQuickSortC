#include <stdio.h>
#include <stdlib.h>

int obtenerMedio(Lista *A,int p, int r){
	if(r-p == 0){
		return p;
	}
	int medio = p;
	int prom = 0;
	int i;
	for(i=p;i<=r;i++){
		prom +=A->elementos[i]; 
	}
	prom = prom/(r-p);
	int anterior = NULL;
	int actual;
	for(int i = p;i<=r;i++){
		actual = prom - A->elementos[i];
		if(anterior = NULL 	|| anterior > abs(actual)){
			anterior = abs(actual);
			medio = i;
		}
	}
	return medio;
}

int particionar(Lista *A,int p,int r){
	int x = A->elementos[r];
	int j = p-1;
	int i;
	for(i=p;i<r;i++){
		if(A->elementos[i]<=x){
			j+=1;
			swap(A,i,j);
		}
	}
	swap(A,j+1,r);
	return j+1;
}
int particionarB(Lista *A,int p,int r){
	int y =obtenerMedio(A,p,r);
	swap(A,y,r);
	int x = A->elementos[r];
	int j = p-1;
	int i;
	for(i=p;i<r;i++){
		if(A->elementos[i]<=x){
			j+=1;
			swap(A,i,j);
		}
	}
	swap(A,j+1,r);
	return j+1;
}


void quickSort(Lista *A,int p,int r){
	if(p<r){
		int q;
		q = particionar(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

void quickSortB(Lista *A,int p,int r){
	if(p<r){
		int q;
		q = particionarB(A,p,r);
		quickSortB(A,p,q-1);
		quickSortB(A,q+1,r);
	}
}

void doubleQuickSort(Lista *A){
    int contdir = 0,continv = 0;
    for(int i = 1;i < A->tam;i++){
        if(A->elementos[i-1] <= A->elementos[i]){
            contdir+=1;
        }
    }
    if(contdir == A->tam -1){
        return;
    }
    for(int i = 1;i < A->tam;i++){
        if(A->elementos[i-1] >= A->elementos[i]){
            continv+=1;
        }
    }
    if(continv == A->tam -1){
        
        return;
    }
    double cerc = 1.7;
    if((continv >= (A->tam-1)/cerc) || (contdir >= (A->tam-1)/cerc)){
        printf("######################\n");
        printf("quickSortB");
        printf("######################\n");
        quickSortB(A,0,A->tam-1);
    }
	else{
        printf("######################\n");
        printf("quickSort\n");
        printf("######################\n");
        quickSort(A,0,A->tam-1);
    }
}