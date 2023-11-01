#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void exibe(Arv A, int n) {
    if (A == NULL)
        return;
    exibe(A->dir, n + 1);
    printf("%*s%d\n", 3 * n, "", A->item);
    exibe(A->esq, n + 1);
}

Arv aleatoria(int n) {
    if (n == 0)
        return NULL;
    return arv(aleatoria(rand() % n), rand() % 100, aleatoria(rand() % n));
}

int main(void) {
    srand(time(NULL));
    exibe(aleatoria(9), 0);
    return 0;
}

