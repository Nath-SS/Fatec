#include <stdio.h>
#include <ctype.h>
#include "pilha.h"
#include "fila.h"

int main(void) {
	char s[256];
	Fila F = fila(256);
	Pilha P = pilha(256);
	
	printf("\nFrase? ");
	gets(s);
	
	for(int i=0; s[i]; i++){
		if(isalpha(s[i]) ) {
			enfileira(toupper(s[i]),F);
			empilha(toupper(s[i]),P);
		}
	}
	printf("Palindromo: \n");

	while(!vaziaf(F) && finalf(F) == topo(P)){
		printf("Pilha: %c Fila: %c \n", desempilha(P), desenfileira(F));
	
	}
	printf("\n");
	if( vaziaf(F) ){
		puts("A frase e palindroma");	
	}else{
		puts("A frase nao e palindroma");
	}
	destroif(&F);
	destroip(&P);
	
	return 0;
}


