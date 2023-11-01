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

Item maximo(Lista L) {
    if (L == NULL) {
        printf("Erro fatal: Lista vazia.\n");
        exit(1);
    }

    Item max = L->item;
    L = L->prox;
    while (L != NULL) {
        if (L->item > max) {
            max = L->item;
        }
        L = L->prox;
    }

    return max;
}

int main(void) {
    Lista I = no(3, no(1, no(5, NULL)));
    exibe(I);
    printf("Maior item: %d\n", maximo(I));
    destroi(&I);
    return 0;
}

