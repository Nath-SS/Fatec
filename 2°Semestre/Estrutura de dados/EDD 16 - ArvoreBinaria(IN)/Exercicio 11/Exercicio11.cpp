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

int pertence(Item x, Arv A) {
    if (A == NULL)
        return 0;
    if (A->item == x)
        return 1;
    return pertence(x, A->esq) || pertence(x, A->dir);
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

    // Verificando pertinência de itens
    int item1 = 2;
    int item2 = 5;

    if (pertence(item1, A))
        printf("%d pertence a arvore A.\n", item1);
    else
        printf("%d nao pertence a arvore A.\n", item1);

    if (pertence(item2, A))
        printf("%d pertence a arvore A.\n", item2);
    else
        printf("%d nao pertence a arvore A.\n", item2);

    return 0;
}

