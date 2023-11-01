#include <stdio.h>
#include "pilha.h"


int main() {
	
    Pilha a, b;
    int n, item, i;

    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    inicializarPilha(&a);
    inicializarPilha(&b);

    for (i = 0; i < n; i++) {
        printf("Digite o %do elemento: ", i+1);
        scanf("%d", &item);
        empilhar(&a, item);
    }

    ordenarPilha(&a, &b);

    printf("Pilha ordenada:\n");
    while (!pilhaVazia(&b)) {
        printf("%d\n", desempilhar(&b));
    }

    return 0;
}	

