#include <stdio.h>

int resto(int m, int n) {
    if (m < n) {
        return m;
    } else {
        return resto(m - n, n);
    }
}

int main(void){
	
	int m = 7, n = 3;
	printf("o resto entre %d e %d = %d\n", m, n, resto(m, n));
	return 0;

}
