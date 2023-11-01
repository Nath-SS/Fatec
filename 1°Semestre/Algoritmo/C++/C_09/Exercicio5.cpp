#include <stdio.h>

int main(void){
	int n1, n2, m;
	printf("Numero 1: ");
	scanf("%f", &n1);
	printf("Numero 2: ");
	scanf("%f", &n2);
	if( n1 > n2 ){
		printf("O número 1 é maior.");	
	} else if(n2 > n1){
		printf("O número 2 é maior");
	} else{
		printf("Os números são iguais");
	}
	return 0;
}
