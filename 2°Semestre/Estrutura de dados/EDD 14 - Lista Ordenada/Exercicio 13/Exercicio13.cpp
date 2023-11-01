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

int osd(Lista L) {
    if (L == NULL || L->prox == NULL) {
        return 1;  // Lista vazia ou com apenas um nó é considerada ordenada
    } else if (L->item >= L->prox->item) {
        return osd(L->prox);  // Verifica recursivamente o restante da lista
    } else {
        return 0;  // Lista não está ordenada simplesmente decrescente
    }
}

int main(void) {
    Lista L1 = no(4, no(3, no(2, no(1, NULL))));  // Lista ordenada: [4, 3, 2, 1]
    Lista L2 = no(4, no(2, no(3, no(1, NULL))));  // Lista não ordenada: [4, 2, 3, 1]
    
    int resultado1 = osd(L1);  // Verifica se a lista L1 está ordenada simplesmente decrescente
    int resultado2 = osd(L2);  // Verifica se a lista L2 está ordenada simplesmente decrescente
    
    printf("Resultado 1: %d\n", resultado1);
    printf("Resultado 2: %d\n", resultado2);
    
    destroi(&L1);
    destroi(&L2);
    return 0;
}

