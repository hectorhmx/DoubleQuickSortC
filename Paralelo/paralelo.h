#include <stdio.h>
#include <stdlib.h>

int obtenerMedio(Lista *A,int p, int r){
	if(r-p == 0){
		return p;
	}
	int medio = p;
	int prom = 0;
	int i;
	//#pragma omp parallel for private(i) shared(A) reduction(+ : prom)
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
		#pragma omp task shared(A) firstprivate(p,r) if(r-p>100)
		{
			quickSort(A,p,q-1);
		}
		#pragma omp task shared(A) firstprivate(p,r) if(r-p>100)
		{
			quickSort(A,q+1,r);
		}
		#pragma omp taskwait
	}
}

void quickSortB(Lista *A,int p,int r){
	if(p<r){
		int q;
		q = particionarB(A,p,r);
		#pragma omp task shared(A) firstprivate(p,r) if(r-p>100)
		{
			quickSortB(A,p,q-1);
		}
		#pragma omp task shared(A) firstprivate(p,r)
		{
			quickSortB(A,q+1,r);
		}
		#pragma omp taskwait
	}
}

void doubleQuickSort(Lista *A){
    int contdir = 0,continv = 0;
	int i;
	#pragma omp parallel for private(i) shared(A) reduction(+ : contdir)
	for(i = 1;i < A->tam;i++){
        if(A->elementos[i-1] <= A->elementos[i]){
            contdir+=1;
        }
    }
    if(contdir == A->tam -1){
        return;
    }
	#pragma omp parallel for private(i) shared(A) reduction(+ : continv)
    for(i = 1;i < A->tam;i++){
        if(A->elementos[i-1] >= A->elementos[i]){
            continv+=1;
        }
    }
    if(continv == A->tam -1){
		#pragma omp parallel for private(i) shared(A)
        for(i = 0;i<A->tam/2;i++){
            swap(A,i,A->tam-1-i);
        }
        return;
    }
    double cerc = 1.7;
	omp_set_nested(1);
	omp_set_num_threads(4);
    if((continv >= (A->tam-1)/cerc) || (contdir >= (A->tam-1)/cerc)){
        /*
		printf("######################\n");
        printf("quickSortB");
        printf("######################\n");
		*/
		#pragma omp parallel shared(A) 
			#pragma omp single
			{
				quickSortB(A,0,A->tam-1);
			}
    }
	else{
		/*
        printf("######################\n");
        printf("quickSort\n");
        printf("######################\n");
		*/
		#pragma omp parallel shared(A)
			#pragma omp single
        	{
				quickSort(A,0,A->tam-1);
			}
    }
}
