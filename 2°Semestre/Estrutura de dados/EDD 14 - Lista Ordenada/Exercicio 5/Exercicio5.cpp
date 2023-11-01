#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;
} *Lista;

Lista no(Item x,Lista p) {
	Lista n =(struct no*)malloc(sizeof(struct no));
	n->item =x;
	n->prox =p;
	return n;
}

void exibe(Lista L) {
	while(L !=NULL ) {
		printf("%d\n",L->item);
		L =L->prox;
	}
}

void ins(Item x, Lista *L){
	while(*L != NULL && (*L)->item<x){
		L = &(*L)->prox;
	}
	*L = no(x, *L);
}

void destroi(Lista* L) {
    while (*L) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
}

void exiba_rd(Lista L) {
    if (L != NULL) {
        printf("%d\n", L->item);   // Exibe o item atual
        exiba_rd(L->prox);         // Chama recursivamente para o próximo item
    }
}

int main(void) {
    Lista L = no(1, no(2, no(3, NULL)));  // Lista: [1, 2, 3]
    exiba_rd(L);  // Exibe os itens em ordem direta: 1, 2, 3
    
    destroi(&L);
    return 0;
}

