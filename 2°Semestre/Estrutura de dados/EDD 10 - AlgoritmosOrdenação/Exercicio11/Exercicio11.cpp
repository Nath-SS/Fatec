#include <stdio.h>
#include <stdlib.h>

int rlsearch(int x, int v[], int n){
	if(n < 0){
		return 0;
	}
	if(x == v[n]){
		return 1;
	}else{
		rlsearch(x, v, n-1);
	}
}

int main(void) {
	int v[8] = {66,80,31,48,27,75,19,52};
	int tamanho = sizeof(v) / sizeof(v[0]);
	printf("27: %d\n", rlsearch(27,v,tamanho-1));
	printf("51: %d\n", rlsearch(51,v,tamanho-1));
	return 0;
}
