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

int soma(Arv A) {
    if (A == NULL)
        return 0;
    return A->item + soma(A->esq) + soma(A->dir);
}

int main(void) {
    // Construindo uma árvore de exemplo
    Arv A = arv(arv(NULL, 2, NULL), 1, arv(NULL, 3, NULL));

    // Calculando a soma dos itens na árvore
    int resultado = soma(A);

    // Exibindo o resultado
    printf("Soma dos itens: %d\n", resultado);

    return 0;
}

