// fila.h - implementacao dinamica sequencial de fila

#include <stdlib.h>
#include <stdio.h>

#define avanca(i) (i = (i+1) % F->max)

typedef int Itemf;

typedef struct fila {
   int   max;
   int   total;
   int   inicio;
   int   final;
   Itemf *item;
} *Fila;

Fila fila(int m) {
   Fila F = (struct fila*)malloc(sizeof(struct fila));
   F->max    = m;
   F->total  = 0;
   F->inicio = 0;
   F->final  = 0; 
   F->item   =(int*) malloc(m*sizeof(Itemf));
   return F;
}

int vaziaf(Fila F) {
   return ( F->total == 0 );
}

int cheiaf(Fila F) {
   return ( F->total == F->max );
}

void enfileira(Itemf x, Fila F) {
   if( cheiaf(F) ) { puts("fila cheia!"); abort(); }
   F->item[F->final] = x;
   avanca(F->final);
   F->total++;
}

Itemf desenfileira(Fila F) {
   if( vaziaf(F) ) { puts("fila vazia!"); abort(); }
   Itemf x = F->item[F->inicio];
   avanca(F->inicio);
   F->total--;
   return x;
}

Itemf iniciof(Fila F){
	if(vaziaf(F) ){ puts("fila vazia!"); abort();}
	return F->item[F->inicio];
}

Itemf finalf(Fila F){
	if(vaziaf(F)){ puts("fila vazia!"); abort();}
	int final = (F->total - (F->total-(F->total-1)) + F->max) % F->max;
	return F->item[final];
}

void destroif(Fila *G) {
   free((*G)->item);
   free(*G);
   *G = NULL;
}
