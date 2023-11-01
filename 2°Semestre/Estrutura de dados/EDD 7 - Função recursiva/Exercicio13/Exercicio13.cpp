#include <stdio.h>

int q(int n) {
    if (n == 1) {
        return 1;
    } else {
        return q(n-1) + 2*n - 1;
    }
}

int main(void){
	
	int n = 4;
	printf("O quadrado de %d e = %d", n, q(n));
	return 0;
}
