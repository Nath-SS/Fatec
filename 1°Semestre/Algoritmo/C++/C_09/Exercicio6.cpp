#include <stdio.h>

int main(void){
	int faltas;
	float media;
	printf("Faltas: ");
	scanf("%d", &faltas);
	printf("Media: ");
	scanf("%f", &media);
	if( media >= 6 && faltas <= 5 ){
		printf("Aprovado");	
	} else{
		printf("Reprovado");
	}
	return 0;
}
