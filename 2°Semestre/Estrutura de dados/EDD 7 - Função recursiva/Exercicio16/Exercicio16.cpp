#include <stdio.h>

int hanoi(int n){
    if(n == 1){
        return 1;
    }else{
        return 2 * hanoi(n-1) + 1;
    }
}

int main(){
    int n = 3;
    int movimentos = hanoi(n);
    printf("O numero minimo de movimentos para resolver o problema das Torres de Hanoi com %d discos e %d.\n", n, movimentos);
    return 0;
}

