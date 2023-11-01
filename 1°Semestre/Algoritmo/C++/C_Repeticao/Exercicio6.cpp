#include <stdio.h>

int main(void){
	int ter, n;
	
	printf("Insira um valor para o qual deseja calcular seu termial: ");
	scanf("%d", &n);

	for(ter = 1; n > 1; n--){
		ter = ter + n;
	}
	
	printf("\nTermial calculado: %d", ter);

}

