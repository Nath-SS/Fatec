#include <stdio.h>

int par(int n){
	if(n > 0){
		par(n-2);
	}else if(n == 0){
		printf("E um numero par");
	}else{
		printf("Nao e um numero par");
	}
}

int main(void){
	
	int n;
	printf("Num? ");
	scanf("%d", &n);
	par(n);
	
	return 0;
}
