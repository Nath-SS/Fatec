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
        printf("%d\n", L->item);
        L = L->prox;
    }
}

void destroi(Lista* L) {
    while (*L) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

void anexa(Lista* A, Lista B) {
    if (!B) {
        return;
    }
    while (*A) {
        A = &(*A)->prox;
    }
    *A = B;
}

int pertence(Item x, Lista L) {
    while (L != NULL) {
        if (L->item == x) {
            return 1;  // O item pertence à lista
        }
        L = L->prox;
    }
    return 0;  // O item não pertence à lista
}

int main(void) {
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    int item = 2;
    if (pertence(item, I)) {
        printf("%d pertence a lista.\n", item);
    } else {
        printf("%d nao pertence a lista.\n", item);
    }
    destroi(&I);
    return 0;
}

