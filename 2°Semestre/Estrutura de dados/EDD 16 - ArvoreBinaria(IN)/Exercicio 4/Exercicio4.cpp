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

Arv completa(int h) {
    if (h == 0)
        return NULL;
    return arv(completa(h - 1), rand() % 100, completa(h - 1));
}

int count_nodes(Arv A) {
    if (A == NULL)
        return 0;
    return 1 + count_nodes(A->esq) + count_nodes(A->dir);
}

Arv balanceada(int n) {
    if (n == 0)
        return NULL;
    int left_nodes = (n - 1) / 2;
    int right_nodes = n - 1 - left_nodes;
    return arv(balanceada(left_nodes), rand() % 100, balanceada(right_nodes));
}

int main(void) {
	srand(time(NULL));
	exibe(balanceada(9),0);
	return 0;
}


