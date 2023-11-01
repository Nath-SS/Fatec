#include <stdio.h>

int main(void){
	int n;
	int contador = 1;
	printf("Digite o numero: ");
	scanf("%d", &n);
	for(int i = 1; contador <= n; i+=2, contador++){
		printf("%d",&i);
	}
}
