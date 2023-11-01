#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    char dado;
    struct Pilha *prox;
} Pilha;

void empilhar(Pilha **pilha, char dado) {
    Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
    novo->dado = dado;
    novo->prox = *pilha;
    *pilha = novo;
}

char desempilhar(Pilha **pilha) {
    Pilha *temp = *pilha;
    char dado = temp->dado;
    *pilha = temp->prox;
    free(temp);
    return dado;
}

int pilhaVazia(Pilha *pilha) {
    return pilha == NULL;
}

int balanceada(char *expressao) {
    Pilha *pilha = NULL;
    int i, len = strlen(expressao);
    for (i = 0; i < len; i++) {
        char c = expressao[i];
        if (c == '(' || c == '[' || c == '{') {
            empilhar(&pilha, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (pilhaVazia(pilha)) {
                return 0;
            }
            char topo = desempilhar(&pilha);
            if ((c == ')' && topo != '(') || (c == ']' && topo != '[') || (c == '}' && topo != '{')) {
                return 0;
            }
        }
    }
    return pilhaVazia(pilha);
}

