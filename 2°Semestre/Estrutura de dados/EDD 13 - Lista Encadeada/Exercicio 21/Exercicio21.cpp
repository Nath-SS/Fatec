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

int sorted(Lista L) {
    if (L == NULL || L->prox == NULL) {
        return 1;  // Caso base: lista vazia ou com apenas um nó, considerada ordenada
    }
    if (L->item > L->prox->item) {
        return 0;  // Encontrou elementos fora de ordem, lista não está ordenada
    }
    return sorted(L->prox);  // Chamada recursiva para o próximo nó da lista
}

int main(void) {
    Lista L = no(1, no(2, no(3, NULL)));  // Lista: [1, 2, 3]
    exibe(L);
    int ordenada = sorted(L);
    if (ordenada) {
        printf("A lista esta ordenada.\n");
    } else {
        printf("A lista nao esta ordenada.\n");
    }
    destroi(&L);
    return 0;
}

