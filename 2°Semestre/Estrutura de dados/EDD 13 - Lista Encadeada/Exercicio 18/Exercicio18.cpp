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

int in(Item x, Lista L) {
    if (L == NULL) {
        return 0;  // Item não encontrado
    }
    if (L->item == x) {
        return 1;  // Item encontrado
    }
    return in(x, L->prox);  // Chamada recursiva para o próximo nó da lista
}

int main(void) {
    Lista L = no(1, no(2, no(3, NULL)));  // Lista: [1, 2, 3]
    exibe(L);
    int encontrado = in(2, L);
    if (encontrado) {
        printf("Item encontrado na lista.\n");
    } else {
        printf("Item nao encontrado na lista.\n");
    }
    destroi(&L);
    return 0;
}

