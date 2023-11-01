#include <stdio.h>

int main(void){
	float salario;
	
	printf("Digite o seu salario: ");
	scanf("%f", &salario);
	if(salario <= 1,903.98){
		printf("Voce esta isento do imposto de renda");
	}else if(salario > 1,903.98 && salario <= 2,826.65){
		printf("O seu imposto de renda sera 7,5% do seu salario");
	}else if(salario > 2,826.65 && salario <= 3,751.05){
		printf("O seu imposto de renda sera 15,0% do seu salario");
	}else if(salario > 3,751.05 && salario <= 4,664.68){
		printf("O seu imposto de renda sera 22,5% do seu salario");
	}else{
		printf("O seu imposto de renda sera 27,5% do seu salario");
	}
	
}
