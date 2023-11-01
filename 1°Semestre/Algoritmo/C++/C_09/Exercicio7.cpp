#include <stdio.h>

int main(void){
	int faltas;
	float media;
	printf("Faltas: ");
	scanf("%d", &faltas);
	printf("Media: ");
	scanf("%f", &media);
	if( faltas > 5 || media < 4 ){
		printf("Reprovado");	
	} else if ( media > 6){
		printf("Aprovado");
	} else{
		printf("Recuperação");
	}
	return 0;
}
