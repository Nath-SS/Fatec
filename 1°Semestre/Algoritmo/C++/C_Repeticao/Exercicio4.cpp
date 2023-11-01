#include <stdio.h>

int main(void){
	double x, fixo;
	int n;
	printf("Digite o numero a ser potencializado: ");
	scanf("%lf", &x);
	printf("Agora digite a qual potencia ele deve ser elevado: ");
	scanf("%d", &n);
	fixo = x;
	
	if(n == 0){
		printf("O resultado e: 1);

	}else if(n == 1){
		printf("O resultado e: %lf", x);

	}else{
	
		for(int i = 2; i <= n; i++){
			x =+ x*fixo;
		}
	}
	printf("O resultado e: %lf", x);
}
