#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
    Lista n = (struct no*)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void exibe(Lista L) {
    while (L != NULL) {
        printf("%d ", L->item);
        L = L->prox;
    }
    printf("\n");
}

void destroi(Lista* L) {
    while (*L) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

Item nth(int n, Lista L) {
    if (L == NULL) {
        printf("Erro fatal: Lista vazia.\n");
        exit(1);
    }
    if (n == 1) {
        return L->item;  // Encontrou o enésimo item
    }
    return nth(n - 1, L->prox);  // Chamada recursiva para o próximo nó da lista
}

int main(void) {
    Lista L = no(1, no(2, no(3, NULL)));  // Lista: [1, 2, 3]
    exibe(L);
    Item enesimo = nth(2, L);
    printf("Enesimo item: %d\n", enesimo);
    destroi(&L);
    return 0;
}

