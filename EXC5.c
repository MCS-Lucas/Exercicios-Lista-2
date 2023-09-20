#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

void insertionSort(int vet[], int tam) {
    int i, j, key;
    for (i = 1; i < tam; i++) {
        key = vet[i];
        j = i - 1;

        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }

        vet[j + 1] = key;
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


    int tam = linhas * colunas;
    int vetorUnico[tam];

    for (i = 0; i < tam; i++) {
        vetorUnico[i] = matriz[i];
    }


    insertionSort(vetorUnico, tam);

    for (i = 0; i < tam; i++) {
        matriz[i] = vetorUnico[i];
    }

    printf("Matriz ordenada por insertion sort:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i * colunas + j]);
        }
        printf("\n");
    }

    return 0;
}

