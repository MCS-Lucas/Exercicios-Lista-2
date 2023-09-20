#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


int main() {

setlocale(LC_ALL, "Portuguese");

int i, aux, n, vet[5];

for (i=0; i<=4 ; i++){

    printf("Digite a um numero inteiro [%d] = ", i+1);
	scanf("%d", &vet[i]);

}

for (n=1 ; n<=5 ; n++){

    for (i=0; i<=3; i++){

        if(vet[i] > vet[i+1]){

            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;

        }
    }
}
printf("\n\n\n");

for(i=0;i<=4; i++){

printf("%d \t", vet[i]);

}

return 0;

}
