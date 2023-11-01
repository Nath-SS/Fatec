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

int pert(Item x, Lista L) {
	while( L != NULL && L->item < x ){
		L = L->prox;
	}
	return (L != NULL && L->item == x);
}

int pert_rec(Item x, Lista L) {
    if (L == NULL || L->item > x) {
        return 0;  // Item não encontrado
    } else if (L->item == x) {
        return 1;  // Item encontrado
    } else {
        return pert_rec(x, L->prox);  // Chama recursivamente para o próximo nó da lista
    }
}

int main(void) {
    Lista L = no(1, no(2, no(3, no(4, NULL))));  // Lista: [1, 2, 3, 4]
    
    int resultado1 = pert_rec(3, L);  // Verifica se o item 3 está presente na lista
    int resultado2 = pert_rec(5, L);  // Verifica se o item 5 está presente na lista
    
    printf("Resultado 1: %d\n", resultado1);
    printf("Resultado 2: %d\n", resultado2);
    
    destroi(&L);
    return 0;
}

