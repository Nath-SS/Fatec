#include <stdio.h>

int main(void){
	int n1, n2, m;
	printf("Numero 1: ");
	scanf("%f", &n1);
	printf("Numero 2: ");
	scanf("%f", &n2);
	if( n1 > n2 ){
		printf("O n�mero 1 � maior.");	
	} else if(n2 > n1){
		printf("O n�mero 2 � maior");
	} else{
		printf("Os n�meros s�o iguais");
	}
	return 0;
}
