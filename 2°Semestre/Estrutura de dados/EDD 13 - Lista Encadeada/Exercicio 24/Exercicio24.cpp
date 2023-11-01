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

void replace(Item x, Item y, Lista L) {
    if (L == NULL) {
        return;  // Caso base: lista vazia
    }
    if (L->item == x) {
        L->item = y;  // Substitui o item
    }
    replace(x, y, L->prox);  // Chama recursivamente para o próximo nó
}

int main(void) {
    Lista L = no(1, no(2, no(1, no(3, no(1, NULL)))));  // Lista: [1, 2, 1, 3, 1]
    exibe(L);
    replace(1, 5, L);
    exibe(L);
    destroi(&L);
    return 0;
}

