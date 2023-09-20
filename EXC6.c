#include <stdio.h>
#include <stdlib.h>

void SearchSeq(int matriz[][100], int linhas, int colunas, int val, int *linhaF, int *colF) {
    int f = 0; 
    int i, j;
    
    
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
           
            if (matriz[i][j] == val) {
                *linhaF = i;       
                *colF = j;     
                f = 1;           
                break;                   
            }
        }
        
        if (f) {
            break; 
        }
    }
    
    if (!f) {
        *linhaF = -1; 
        *colF = -1;  
    }
}

int main() {
    int linhas, colunas, val, linhaF, colF, i, j;

    printf("Informe o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Informe o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz[100][100];

    printf("Informe os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Informe o valor a ser buscado: ");
    scanf("%d", &val);

    SearchSeq(matriz, linhas, colunas, val, &linhaF, &colF);

    if (linhaF != -1 && colF != -1) {
        printf("O valor %d foi encontrado na posicao (%d, %d)\n", val, linhaF + 1, colF + 1);
    } else {
        printf("O valor %d não foi encontrado na matriz.\n", val);
    }

    return 0;
}

