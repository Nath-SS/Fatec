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

int equal(Lista A, Lista B) {
    if (A == NULL && B == NULL) {
        return 1;  // Caso base: ambas as listas são vazias, consideradas iguais
    }
    if (A == NULL || B == NULL) {
        return 0;  // Caso base: apenas uma das listas é vazia, consideradas diferentes
    }
    if (A->item != B->item) {
        return 0;  // Encontrou elementos diferentes, listas são diferentes
    }
    return equal(A->prox, B->prox);  // Chamada recursiva para os próximos nós das listas
}

int main(void) {
    Lista A = no(1, no(2, no(3, NULL)));  // Lista A: [1, 2, 3]
    Lista B = no(1, no(2, no(3, NULL)));  // Lista B: [1, 2, 3]
    exibe(A);
    exibe(B);
    int iguais = equal(A, B);
    if (iguais) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas sao diferentes.\n");
    }
    destroi(&A);
    destroi(&B);
    return 0;
}

