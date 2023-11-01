#include <stdio.h>

void exibe(int v[], int n){
	
	for(int i= 0; i<n; i++){
		printf("Sequencia: %d \n", v[i]);
	}
	
}

void empurra(int v[], int u, int tamanho){
	int max = 0, imax = 0;
    for (int i = 0; i < tamanho; i++) {
        if (v[i] > max) {
            max = v[i];
            imax = i;
        }
    }
    if(v[imax] != v[u] ){
    	int aux = v[imax+1];
    	v[imax] = aux;
    	v[imax+1] = max;
    	empurra(v, u, tamanho);
	}else{
		return;
	}
}

int main(void){
	
	int v[9]={51, 82, 38, 99, 75, 19, 69, 46, 27};
	int tamanho = sizeof(v) / sizeof(v[0]);
	empurra(v, 8, tamanho);
	exibe(v, tamanho);
	return 0;
	
}
