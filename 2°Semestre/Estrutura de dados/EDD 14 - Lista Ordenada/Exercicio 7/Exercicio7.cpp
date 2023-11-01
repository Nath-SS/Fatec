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

void rem(Item x, Lista *L) {
	while( *L != NULL && (*L)->item < x ){
		L = &(*L)->prox;
	}
	if( *L == NULL || (*L)->item > x ){
		return;
	}
	Lista n = *L;
	*L = n->prox;
	free(n);
}

int main(void) {
	Lista I = NULL;
	ins(4,&I); ins(1,&I); ins(3,&I); ins(5,&I); ins(2,&I);
	rem(3,&I);
	exibe(I);
	return 0;
}


