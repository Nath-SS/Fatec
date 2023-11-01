#include <stdio.h>
#include <string.h>
#include "pilha.h" // pilha de char *

int main(void) {
    Pilha P = pilha(5);
    char buffer[256];
    char *s;
    for (int i = 1; i <= 3; i++) {
        printf("?");
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = '\0'; 
            s = _strdup(buffer); 
            empilha(s, P);
        }
    }
    while (!vaziap(P)) {
        char *elemento = desempilha(P);
        puts(elemento);
        free(elemento); 
    }
    return 0;
}

