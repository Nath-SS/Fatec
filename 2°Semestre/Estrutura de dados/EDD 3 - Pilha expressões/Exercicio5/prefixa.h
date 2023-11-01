#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"



char *prefixa(char *e) {
    Pilha P = pilha(strlen(e));
    char *prefixa = (char *) malloc(strlen(e) * sizeof(char));
    int j = 0;
    
    for (int i = strlen(e) - 1; i >= 0; i--) {
        if (isdigit(e[i])) {
            prefixa[j++] = e[i];
        }
        else if (e[i] == ')' || e[i] == '*' || e[i] == '/') {
            empilha(e[i], P);
        }
        else if (e[i] == '+' || e[i] == '-') {
            while (!vaziap(P) && (topo(P) == '*' || topo(P) == '/')) {
                prefixa[j++] = desempilha(P);
            }
            empilha(e[i], P);
        }
        else if (e[i] == '(') {
            while (topo(P) != ')') {
                prefixa[j++] = desempilha(P);
            }
            desempilha(P);
        }
    }
    
    while (!vaziap(P)) {
        prefixa[j++] = desempilha(P);
    }
    
    prefixa[j] = '\0';
    strrev(prefixa);
    destroip(&P);
    
    return prefixa;
}

/*int prio(char o){
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
}*/
