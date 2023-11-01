#include <stdio.h>

int main (void){
	int n;
	printf("Digite um numero: ");
	scanf("%d", &n);
	for(int i = n; i >= 0; i--){
		printf("%d", &n);
	}
	/*do{
		printf("%d", &n);
		n--;
	}while(n >= 0);
	*/
}
