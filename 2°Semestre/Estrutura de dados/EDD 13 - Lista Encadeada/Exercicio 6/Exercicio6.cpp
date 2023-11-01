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


Lista intervalo(int n){
	Lista L = NULL;
	int i = 1;
	while(i<= n){
		L = no(i,L);
		i++;
	}
	return L;
}

int main(void) {
	Lista A = intervalo(10);
	exibe(A);
	return 0;
}
