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

void rem_todo(Item x, Lista *L) {
    Lista aux, ant = NULL;
    Lista atual = *L;
    
    while (atual != NULL) {
        if (atual->item == x) {
            if (ant == NULL) {
                *L = atual->prox;
            } else {
                ant->prox = atual->prox;
            }
            
            aux = atual;
            atual = atual->prox;
            free(aux);
        } else {
            ant = atual;
            atual = atual->prox;
        }
    }
}

int main(void) {
    Lista L = no(1, no(2, no(3, no(2, no(4, NULL)))));  // Lista: [1, 2, 3, 2, 4]
    rem_todo(2, &L);  // Remove todas as ocorrências de 2 na lista
    
    exibe(L);  // Exibe a lista resultante
    
    destroi(&L);
    return 0;
}

