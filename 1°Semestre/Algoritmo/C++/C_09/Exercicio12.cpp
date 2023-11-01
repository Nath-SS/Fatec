#include <stdio.h>
#include <conio.h>
main() {
	int d, m, a, x;
	printf("\nData de nascimento: ");
	scanf("%d/%d/%d", &d, &m, &a);
	x = d*100+m+a;
	switch( (x/100 + x%100)%5 ) {
		case 0:
			printf("timido");
			break;
		case 1: 
			printf("sonhador");
			break;
		case 2:
			printf("paquerador");
			break;
		case 3:
			printf("atraente");
			break;
		case 4:
			printf("irresistível");
			break;
		}
	getch();
}
