#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(void){
 float a, b, c, x1, x2, delta;
 
 printf("Digite o valor do termo a: ");
 scanf("%f", &a);
 printf("Digite o valor do termo b: ");
 scanf("%f", &b);
 printf("Digite o valor do termo c: ");
 scanf("%f", &c);
 

 delta = b*b - 4*a*c;
 x1 = (-b + sqrt(delta)) / (2*a);
 x2 = (-b - sqrt(delta)) / (2*a);
 
 if(delta < 0) {
 	
	printf("A equacao nao possui raizes reais");
	
 } else {
 	printf("O valor de x1: %.2fn", x1);
 	printf("O valor de x2: %.2fn", x2);
 }
}


