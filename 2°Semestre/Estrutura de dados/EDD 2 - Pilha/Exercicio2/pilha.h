#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha {
    int topo;
    int itens[MAX];
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return (p->topo == -1);
}

int pilhaCheia(Pilha *p) {
    return (p->topo == MAX-1);
}

void empilhar(Pilha *p, int item) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia!\n");
        exit(1);
    }
    p->itens[++(p->topo)] = item;
}

int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->itens[(p->topo)--];
}

int topo(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->itens[p->topo];
}

void ordenarPilha(Pilha *a, Pilha *b) {
    int temp;
    while (!pilhaVazia(a)) {
        temp = desempilhar(a);
        while (!pilhaVazia(b) && topo(b) < temp) {
            empilhar(a, desempilhar(b));
        }
        empilhar(b, temp);
    }
}
