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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(Arv A) {
    if (A == NULL)
        return 0;
    int alturaEsq = altura(A->esq);
    int alturaDir = altura(A->dir);
    return 1 + max(alturaEsq, alturaDir);
}

int main(void) {
    // Construindo uma árvore de exemplo
    Arv A = arv(arv(NULL, 2, NULL), 1, arv(NULL, 3, arv(NULL, 4, NULL)));

    // Calculando a altura da árvore
    int resultado = altura(A);

    // Exibindo o resultado
    printf("Altura da arvore: %d\n", resultado);

    return 0;
}

