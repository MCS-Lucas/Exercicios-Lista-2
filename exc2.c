#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
	
	int aux;
	
	aux = *a;
	*a = *b;
	*b = aux;
	
}

void bubbleSort(int vet[], int n){
	
	int i, j;
	
	for(i = 0; i < n - 1; i++){
		
		for(j = 0; j < n - i - 1; j++){
			
			if(vet[j] > vet[j + 1]){
				
				swap(&vet[j], &vet[j + 1]);
				
			}
		}
	}
}

int part(int vet[], int low, int high){
	
	int pivo = vet[high];
	int j;
	int i = (low - 1);
	
	for(j = low; j <= high - 1; j++){
		
	
		if (vet[j] < pivo){
		
			i++;
			swap(&vet[i], &vet[j]);
			
		}
	}
	
	swap(&vet[i + 1], &vet[high]);
	
	return (i + 1);
	
}

void quicksort (int vet[], int low, int high ){
	
	if(low < high){
		
		int pi = part(vet,low,high);
		quicksort(vet, low, pi - 1);
        quicksort(vet, pi + 1, high);
	}
	
	
}

void merge(int vet[], int left, int middle, int right){
	
	int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = vet[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = vet[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vet[k] = L[i];
            i++;
        } else {
        	vet[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int vet[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(vet, left, middle);
        mergeSort(vet, middle + 1, right);

        merge(vet, left, middle, right);
    }
}

int main(){	
	int n, i;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n];
	
	
	srand(time(NULL));
    for (i = 0; i < n; i++) {
        vet[i] = rand() % 1000;  
    }
	
	int bubbleVet[n], quickVet[n], mergeVet[n];
	
    for (i = 0; i < n; i++) {
        bubbleVet[i] = vet[i];
        quickVet[i] = vet[i];
        mergeVet[i] = vet[i];
    }
	
	clock_t start_time = clock();
    bubbleSort(bubbleVet, n);
    clock_t end_time = clock();
    
    double bubbleTime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    start_time = clock();
    quicksort(quickVet, 0, n - 1);
    end_time = clock();
    
    double quickTime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    start_time = clock();
    mergeSort(mergeVet, 0, n - 1);
    end_time = clock();
    
    double mergeTime = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	
	printf("Tempo de execucao do Bubble Sort: %f segundos\n", bubbleTime);
    printf("Tempo de execucao do Quicksort: %f segundos\n", quickTime);
    printf("Tempo de execucao do Mergesort: %f segundos\n", mergeTime);

    return 0;
}
