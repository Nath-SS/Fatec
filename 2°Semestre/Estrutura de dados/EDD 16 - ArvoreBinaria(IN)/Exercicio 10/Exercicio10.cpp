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

Arv clone(Arv A) {
    if (A == NULL)
        return NULL;
    Arv novoNo = arv(NULL, A->item, NULL);
    novoNo->esq = clone(A->esq);
    novoNo->dir = clone(A->dir);
    return novoNo;
}

void exibe(Arv A, int n) {
    if (A == NULL)
        return;
    exibe(A->dir, n + 1);
    printf("%*s%d\n", 3 * n, "", A->item);
    exibe(A->esq, n + 1);
}

int main(void) {
    // Construindo uma árvore de exemplo
    Arv A = arv(arv(NULL, 2, NULL), 1, arv(NULL, 3, arv(NULL, 4, NULL)));

    // Clonando a árvore
    Arv cloneA = clone(A);

    // Exibindo a árvore original
    printf("Arvore original:\n");
    exibe(A, 0);

    // Exibindo o clone da árvore
    printf("\nClone da arvore:\n");
    exibe(cloneA, 0);

    return 0;
}

