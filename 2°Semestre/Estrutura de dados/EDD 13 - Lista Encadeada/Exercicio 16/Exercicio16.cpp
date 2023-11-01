#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

Lista rnd(int n, int m) {
    if (n <= 0) {
        return NULL;  // Lista vazia, retorna NULL
    }
    int randomItem = rand() % m;  // Gera um item aleatório no intervalo [0, m-1]
    return no(randomItem, rnd(n-1, m));  // Cria um novo nó com o item aleatório e faz a chamada recursiva para o restante da lista
}

int main(void) {
    srand(time(NULL));  // Inicializa a semente aleatória
    Lista R = rnd(10, 5);  // Cria uma lista com 10 itens aleatórios no intervalo [0, 4]
    exibe(R);
    destroi(&R);
    return 0;
}

