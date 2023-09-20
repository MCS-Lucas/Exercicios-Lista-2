#include <stdio.h>

void swap(int *a, int *b) {
	
    int aux;
	
	aux = *a;
    *a = *b;
    *b = aux;
}

int part(int vet[], int low, int high) {
    int pivo = vet[high];
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++) {
        if (vet[j] < pivo) {
            i++;
            swap(&vet[i], &vet[j]);
        }
    }

    swap(&vet[i + 1], &vet[high]);
    return (i + 1);
}

void quickSort(int vet[], int low, int high) {
	
	int pi;
	
    if (low < high) {
        pi = part(vet, low, high);

        quickSort(vet, low, pi - 1);
        quickSort(vet, pi + 1, high);
    }
}

int main() {
    int linhas, colunas, i, j;

    printf("Informe o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Informe o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[linhas * colunas];

    printf("Informe os numeros da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i * colunas + j]);
        }
    }

	quickSort(matriz, 0, linhas * colunas - 1);
 

    printf("Matriz ordenada por Quick Sort:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i * colunas + j]);
        }
        printf("\n");
    }

    return 0;
}

