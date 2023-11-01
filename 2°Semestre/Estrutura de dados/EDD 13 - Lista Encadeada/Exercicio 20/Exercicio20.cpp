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

Item minimum(Lista L) {
    if (L == NULL) {
        printf("Erro fatal: Lista vazia.\n");
        exit(1);
    }
    if (L->prox == NULL) {
        return L->item;  // Encontrou o menor item
    }
    Item proximo_minimo = minimum(L->prox);  // Chamada recursiva para o próximo nó da lista
    if (L->item < proximo_minimo) {
        return L->item;  // O item atual é menor que o próximo mínimo encontrado
    } else {
        return proximo_minimo;  // O próximo mínimo encontrado é menor que o item atual
    }
}

int main(void) {
    Lista L = no(3, no(1, no(2, NULL)));  // Lista: [3, 1, 2]
    exibe(L);
    Item menor = minimum(L);
    printf("Menor item: %d\n", menor);
    destroi(&L);
    return 0;
}

