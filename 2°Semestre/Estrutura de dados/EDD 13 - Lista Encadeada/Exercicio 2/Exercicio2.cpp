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
    if (L == NULL) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    
    while (L->prox != NULL) {
        printf("%d, ", L->item);
        L = L->prox;
    }
    
    printf("%d]\n", L->item);
}



int main(void) {
	Lista I = no(3,no(1,no(5,NULL)));
	exibe(I);
	return 0;
}
