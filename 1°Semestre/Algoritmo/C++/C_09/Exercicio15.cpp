#include <stdio.h>

int void(){
	float peso, altura, imc;
	
	printf("Digite o seu peso: ");
	scanf("%f", &peso);
	printf("Digite a sua altura: ");
	scanf("%f", &altura);
	
	imc = peso/(altura*altura);
	
	if(imc >= 18,5 && imc<= 30 ){
		printf("Seu peso e normal");
		
	}else if(imc < 18,5){
		printf("Voce esta magro");
		
	}else{
		printf("Voce esta obeso");
	} 
}
