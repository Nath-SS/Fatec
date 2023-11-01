#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    char expressao[100];
    
    printf("Digite uma expressao com chaves, colchetes e parenteses: ");
    fgets(expressao, 100, stdin);
    
    if (balanceada(expressao)) {
        printf("A expressao esta balanceada.\n");
    } else {
        printf("A expressao nao esta balanceada.\n");
    }
    return 0;
}
