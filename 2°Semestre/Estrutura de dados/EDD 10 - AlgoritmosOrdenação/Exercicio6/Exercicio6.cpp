#include <stdio.h>
#include <stdlib.h>


void preenche(int v[],int n, int s){

	srand(s);//definida em stdlib.h 
	for(int i=0;i<n;i++){
		v[i]=rand()%1000;
	}
}

void exibe(int v[], int n){
	
	for(int i= 0; i<n; i++){
		printf("Sequencia: %d \n", v[i]);
	}
	
}

int main(void){
	
	int v[10], n = 10, s = 10;
	preenche(v, n, s);
	exibe(v, 10);
	return 0;
}
