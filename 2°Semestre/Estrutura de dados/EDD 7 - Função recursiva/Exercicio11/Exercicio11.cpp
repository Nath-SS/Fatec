#include <stdio.h>

int quoc(int m, int n) {
    if (m < n) {
        return 0;
    } else {
        return 1 + quoc(m - n, n);
    }
}

int main(void){
	
	int m = 8, n = 4;
	printf("%d / %d = %d\n", m, n, quoc(m, n));
	return 0;

}
