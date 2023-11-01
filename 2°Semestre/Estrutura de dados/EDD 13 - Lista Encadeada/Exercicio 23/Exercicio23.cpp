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

int count(Item x, Lista L) {
    if (L == NULL) {
        return 0;  // Caso base: lista vazia, item não encontrado
    }
    if (L->item == x) {
        return 1 + count(x, L->prox);  // Encontrou o item, incrementa 1 e chama recursivamente para o próximo nó
    }
    return count(x, L->prox);  // Item não encontrado, chama recursivamente para o próximo nó
}

int main(void) {
    Lista L = no(1, no(2, no(1, no(3, no(1, NULL)))));  // Lista: [1, 2, 1, 3, 1]
    exibe(L);
    int ocorrencias = count(1, L);
    printf("O item 1 ocorre %d vez(es) na lista.\n", ocorrencias);
    destroi(&L);
    return 0;
}

