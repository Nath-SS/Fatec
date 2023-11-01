#include <stdio.h>
#include <stdlib.h>

typedef int Chave;
typedef int Valor;
typedef struct map {
    Chave chave;
    Valor valor;
    struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
    Map n = (struct map*)malloc(sizeof(struct map));
    n->chave = c;
    n->valor = v;
    n->prox = p;
    return n;
}

void insm(Chave c, Valor v, Map *M) {
    while (*M && c > (*M)->chave) {
        M = &(*M)->prox;
    }
    if (*M && c == (*M)->chave) {
        (*M)->valor = v;
    } else {
        *M = no_map(c, v, *M);
    }
}

void exibem(Map M) {
    printf("[");
    while (M) {
        printf("(%d,%d)", M->chave, M->valor);
        if (M->prox) {
            printf(",");
        }
        M = M->prox;
    }
    printf("]\n");
}

int main(void) {
    Map I = NULL;
    insm(36, 10, &I);
    insm(15, 20, &I);
    insm(42, 30, &I);
    insm(29, 40, &I);
    exibem(I);
    insm(29, 50, &I);
    exibem(I);
    return 0;
}

