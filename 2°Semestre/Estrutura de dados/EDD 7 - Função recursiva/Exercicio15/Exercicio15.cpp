#include <stdio.h>

int qd(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + qd(n / 2);
    }
}


int main(void){
	
	int n = 13;
	printf("quantidade de digitos binarios do numero %d e = %d", n, qd(n));
	return 0;
}
