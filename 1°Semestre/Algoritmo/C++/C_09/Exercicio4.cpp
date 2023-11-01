#include <stdio.h>

int main(void){
	float p1, p2, m;
	printf("Notas 1: ");
	scanf("%f", &p1);
	printf("Notas 2: ");
	scanf("%f", &p2);
	m = (p1+p2)/2;
	if( m>=6){
		printf("Aprovado");	
	} else{
		printf("Reprovado");
	}
	return 0;
}
