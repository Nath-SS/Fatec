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

void ins_isr(Item x, Lista *L) {
    while (*L != NULL) {
        if ((*L)->item == x) {
            return;  // Item já está na lista, retorna sem fazer a inserção
        }
        if ((*L)->item > x) {
            break;  // Encontrou posição de inserção
        }
        L = &(*L)->prox;
    }
    *L = no(x, *L);  // Insere o item na posição adequada
}

int main(void) {
    Lista L = no(1, no(3, no(5, NULL)));  // Lista: [1, 3, 5]
    exibe(L);
    printf("\n");
    
    ins_isr(2, &L);  // Insere o item 2 na lista
    exibe(L);  // Lista modificada: [1, 2, 3, 5]
    printf("\n");
    
    ins_isr(4, &L);  // Tenta inserir o item 4 na lista, mas já está presente, não faz a inserção
    exibe(L);  // Lista permanece a mesma: [1, 2, 3, 5]
    printf("\n");
    destroi(&L);
    return 0;
}

