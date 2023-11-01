#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct arv {
    struct arv* esq;
    Item item;
    struct arv* dir;
} *Arv;

Arv arv(Arv e, Item x, Arv d) {
    Arv n = (struct arv*)malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;
    return n;
}

int folhas(Arv A) {
    if (A == NULL)
        return 0;
    if (A->esq == NULL && A->dir == NULL)
        return 1;
    return folhas(A->esq) + folhas(A->dir);
}

int main(void) {
    // Construindo uma árvore de exemplo
    Arv A = arv(arv(NULL, 2, NULL), 1, arv(NULL, 3, arv(NULL, 4, NULL)));

    // Calculando a quantidade de folhas na árvore
    int resultado = folhas(A);

    // Exibindo o resultado
    printf("Quantidade de folhas: %d\n", resultado);

    return 0;
}

