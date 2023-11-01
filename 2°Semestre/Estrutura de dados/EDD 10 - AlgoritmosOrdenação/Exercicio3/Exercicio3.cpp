#include <stdio.h>

void exibe(int v[], int n){
	
	for(int i= 0; i<n; i++){
		printf("Sequencia: %d \n", v[i]);
	}
	
}

void empurra(int v[], int n){
	int aux = v[n];
	v[n] = v[n+1];
    v[n+1] = aux;
}

void bsr(int v[], int n) {
    if (n == 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i+1]) {
            empurra(v, i);
        }
    }
    bsr(v, n-1);
}


int main(void){
	
	int v[9]={51, 82, 38, 99, 75, 19, 69, 46, 27};
	bsr(v, 9);
	exibe(v, 9);
	return 0;
	
}
