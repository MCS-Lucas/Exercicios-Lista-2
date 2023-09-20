#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionreverso(int vet[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] < key) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}

int main() {
	
	srand(time(NULL));
	
    int vet[] = {rand() % 100,rand() % 100,rand() % 100,rand() % 100,rand() % 100};
    int n = sizeof(vet) / sizeof(vet[0]);
	int i;


    printf("Vetor original: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    insertionreverso(vet, n);

    printf("Vetor ordenado em ordem decrescente: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}

