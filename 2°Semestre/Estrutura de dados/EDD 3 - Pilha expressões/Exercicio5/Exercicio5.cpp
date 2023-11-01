#include <stdio.h>
#include <stdlib.h>
#include "prefixa.h"

int main(void){
	char e[513];
	printf("Infixa? ");
	
	gets(e);
	
	printf("Prefixa: %s\n", prefixa(e));
	
	return 0;
}
