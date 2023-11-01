#include <stdio.h>

int main(){
	int placa;
	
	printf("Digite a placa do seu veiculo sem as letras: ");
	scanf("%d", &placa);
	if(placa<0 || placa > 9999){
		printf("Placa invalida");
	}else{
		if(placa%10 == 1 || placa%10 = 2){
			printf("Seu veiculo faz parte do rodizio na segunda-feira");
			
		}else if(placa%10 == 3 || placa%10 == 4){
			printf("Seu veiculo faz parte do rodizio na terca-feira");

		}else if(placa%10 == 5 || placa%10 == 6){
			printf("Seu veiculo faz parte do rodizio na quarta-feira");

		}else if(placa%10 == 7 || placa%10 == 8){
			printf("Seu veiculo faz parte do rodizio na quinta-feira");

		}else{
			printf("Seu veiculo faz parte do rodizio na sexta-feira");
		}
	}
}
