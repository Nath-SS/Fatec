#include <stdio.h>
#include <stdlib.h>
#include "posfixa.h"

int main(void){
	char e[513];
	printf("Infixa? ");
	
	gets(e);
	
	printf("Posfixa: %s\n", posfixa(e));
	
	return 0;
}
