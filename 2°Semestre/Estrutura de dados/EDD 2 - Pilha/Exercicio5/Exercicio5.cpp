#include <stdio.h>
#include <string.h>
#include "pilha.h" // pilha de char *

int main (void) {

	Pilha P = pilha(5);
	char s[11];
	for(int i=1; i<=3; i++){
		printf("?");
		fgets(s, sizeof(i), stdin);
		char* copia = strdup(s);
		empilha(copia,P);
	}while(!vaziap(P)){
		char* elemento = desempilha(P);
		printf(elemento);
	}
	return 0;
}

