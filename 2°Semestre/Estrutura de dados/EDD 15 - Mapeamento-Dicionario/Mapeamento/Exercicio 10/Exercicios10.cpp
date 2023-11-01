#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Chave[22];
typedef char Valor[22];
typedef struct map {
    Chave chave;
    Valor valor;
    struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
    Map n = (struct map*)malloc(sizeof(struct map));
    strcpy(n->chave, c);
    strcpy(n->valor, v);
    n->prox = p;
    return n;
}

void insm(Chave c, Valor v, Map *M) {
    while (*M && strcmp(c, (*M)->chave) > 0) {
        M = &(*M)->prox;
    }
    if (*M && strcmp(c, (*M)->chave) == 0) {
        strcpy((*M)->valor, v);
    } else {
        *M = no_map(c, v, *M);
    }
}

void exibem(Map M) {
    printf("[");
    while (M) {
        printf("(%s,%s)", M->chave, M->valor);
        if (M->prox) {
            printf(",");
        }
        M = M->prox;
    }
    printf("]\n");
}

int main(void) {
    Map I = NULL;
    insm("chave1", "valor1", &I);
    insm("chave2", "valor2", &I);
    insm("chave3", "valor3", &I);
    insm("chave4", "valor4", &I);
    exibem(I);
    insm("chave3", "valor5", &I);
    exibem(I);
    return 0;
}

