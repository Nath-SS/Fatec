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

Lista inversa(Lista L) {
    Lista novaLista = NULL;
    while (L != NULL) {
        novaLista = no(L->item, novaLista);
        L = L->prox;
    }
    return novaLista;
}

Lista intervalo(int p, int u) {
    Lista novaLista = NULL;
    if (p > u) {
        return novaLista;  // Retorna lista vazia se p > u
    }
    for (int i = p; i <= u; i++) {
        novaLista = no(i, novaLista);
    }
    return inversa(novaLista);  // Retorna a lista invertida
}

int main(void) {
    Lista I = intervalo(-2, 3);
    exibe(I);
    destroi(&I);
    return 0;
}

