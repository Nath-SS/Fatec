#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int valor(char *e) {
	Pilha P = pilha(256);
	for(int i = 0; e[i]; i++){
		//printf("Iniciou um loop \n");
		if(isdigit(e[i]) ){
		//	printf("Entrou no if \n");
			empilha(e[i]-'0',P);
		//	printf("Empilhou na pilha \n");
		}else{
			int y = desempilha(P);
			int x = desempilha(P);
			switch(e[i] ) {
				case'+': empilha(x+y,P); break;
				case'-': empilha(x-y,P); break;
				case'*': empilha(x*y,P); break;
				case'/': empilha(x/y,P); break;
			}
			/*printf("Pilha: ");
			for (int i = 0; i <= P->topo; i++) {
			  printf("%d ", P->item[i]);
			}
			printf("\n");*/
		}
	}
	int z = desempilha(P);
	destroip(&P);
	return z;
}
int prio(char o){
	switch (o){
		case '(': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
	}
	return -1;
}


char *posfixa (char *e){
	static char s[256];
	int j = 0;
	Pilha P = pilha(256);
	for(int i=0; e[i]; i++){
		if(e[i]=='('){
			empilha('(', P);
		}else if(isdigit(e[i]) ){
			s[j++] = e[i];	
		}else if(strchr("+-/*", e[i])){
			while(!vaziap(P) && prio(topo(P)) >= prio(e[i])){
				s[j++] = desempilha(P);
			}
			empilha(e[i], P);
		}else if(e[i]==')'){
			while(topo(P) != '('){
				s[j++] = desempilha(P);
			}
			desempilha(P);
		}
	}
	while(!vaziap(P)){
		s[j++] = desempilha(P);
	}
	s[j] = '\0';
	destroip(&P);
	return s;
}
