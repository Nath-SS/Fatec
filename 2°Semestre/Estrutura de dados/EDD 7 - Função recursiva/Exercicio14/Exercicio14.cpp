#include <stdio.h>

int sd(int n) {
    if (n < 10) { // caso base: um único dígito
        return n;
    } else {
        int ultimo = n % 10; // extrai o último dígito
        int resto = n / 10; // obtém o número sem o último dígito
        return ultimo + sd(resto); // soma o último dígito com a soma dos demais dígitos
    }
}


int main(void){
	
	int n = 7859;
	printf("a soma dos numeros %d e = %d", n, sd(n));
	return 0;
}
