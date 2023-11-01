#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(void) {
	char c[513];
	
	Pilha P = pilha(513);
	
	printf("Cadeia? ");
	gets(c);
	
	for(int i=0; c[i]; i++){
		if(c[i] != ' '){
			empilha(c[i],P);
		}else{
			while(!vaziap(P)){
				printf("%c", desempilha(P));
			}
			printf(" ");
		}
	}
	
	while(!vaziap(P)){
		printf("%c", desempilha(P));
	}
	
	destroip(&P);
	
	return 0;
}
