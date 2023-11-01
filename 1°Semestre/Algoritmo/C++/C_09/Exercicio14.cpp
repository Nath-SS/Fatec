#include <stdio.h>

int main(){
	int placa;
	
	printf("Digite a placa do seu veiculo sem as letras: ");
	scanf("%d", &placa);
	if(placa<0 || placa > 9999){
		printf("Placa invalida");
	}else{
		switch(placa%10){
			
			case 1:
			case 2:{
				printf("Seu veiculo faz parte do rodizio na segunda-feira");
				break;
			}
			
			case 3:
			case 4:{
				printf("Seu veiculo faz parte do rodizio na terca-feira");
				break;
			}
			
			case 5:
			case 6:{
				printf("Seu veiculo faz parte do rodizio na quarta-feira");
				break;
			}
			
			case 7:
			case 8:{
				printf("Seu veiculo faz parte do rodizio na quinta-feira");
				break;
			}
			
			default:{
				printf("Placa inválida");
				break;
			}
		}
	}
}
