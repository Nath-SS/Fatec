#include <stdio.h>

int sd(int n) {
    if (n < 10) { // caso base: um �nico d�gito
        return n;
    } else {
        int ultimo = n % 10; // extrai o �ltimo d�gito
        int resto = n / 10; // obt�m o n�mero sem o �ltimo d�gito
        return ultimo + sd(resto); // soma o �ltimo d�gito com a soma dos demais d�gitos
    }
}


int main(void){
	
	int n = 7859;
	printf("a soma dos numeros %d e = %d", n, sd(n));
	return 0;
}
