#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Chave;
typedef char Valor[22];
typedef struct map {
	Chave chave;
	Valor valor;
	struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p){
	Map n = (struct map*)malloc(sizeof(struct map));
	n->chave = c;
	strcpy(n->valor,v);
	n->prox = p;
	return n;
}

void insm(Chave c, Valor v, Map *M){
	while( *M && c>(*M)->chave){
		M = &(*M)->prox;
	}
	if(*M && c==(*M)->chave){
		strcpy((*M)->valor,v);
	}else{
		*M = no_map(c,v,*M);
	}
}

void renm(Chave c, Map *M){
	while(*M && c>(*M)->chave){
		M = &(*M)->prox;
	}
	if( *M==NULL || c!=(*M)->chave){
		return;
	}
	Map n = *M;
	*M = n->prox;
	free(n);
}

void exibem(Map M){
	printf("[");
	while(M){
		printf("(%d,%s)", M->chave,M->valor);
		if(M->prox){
			printf(",");
		}
		M = M->prox;
	}
	printf("]\n");
}

void insmr(Chave c, Valor v, Map *I) {
    if (*I == NULL || c < (*I)->chave) {
        *I = no_map(c, v, *I);
    } else if (c == (*I)->chave) {
        strcpy((*I)->valor, v);
    } else {
        insmr(c, v, &((*I)->prox));
    }
}

void remmr(Chave c, Map *I) {
    if (*I == NULL) {
        return;
    }
    if ((*I)->chave == c) {
        Map n = *I;
        *I = n->prox;
        free(n);
        remmr(c, I);
    } else {
        remmr(c, &((*I)->prox));
    }
}

int main(void) {
    Map I = NULL;
    insmr(1, "valor1", &I);
    insmr(2, "valor2", &I);
    insmr(3, "valor3", &I);
    exibem(I);  // Exibe o mapeamento I: [(1,valor1),(2,valor2),(3,valor3)]

    // Remove a chave 2 do mapeamento I
    remmr(2, &I);
    exibem(I);  // Exibe o mapeamento I atualizado: [(1,valor1),(3,valor3)]

    return 0;
}

