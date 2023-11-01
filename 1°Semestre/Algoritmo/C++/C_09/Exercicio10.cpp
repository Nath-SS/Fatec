#include <stdio.h>

int main(void){
	
	float x, y;
	char c;
	
	printf("Digite a expressao: ");
	scanf("%f %c %f", &x, &c,&y);
	switch(c){
		case '+':{
			printf("Valor = %.2f\n", x+y);
			break;
		}
		case '-':{
			printf("Valor = %.2f\n", x-y);
			break;
		}
		case '*':{
			printf("Valor = %.2f\n", x*y);
			break;
		}
		case '/':{
			if(x == 0 || y == 0){
				printf("Divisao por 0 é impossivel.");
			}else{
				printf("Valor = %.2f\n", x/y);
			}
			break;
		}
		default:{
			printf("Operador invalido: %c\n", c);
			break;
		}
	}
}
