#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche(int v[],int n, int s){

	srand(s);//definida em stdlib.h 
	for(int i=0;i<n;i++){
		v[i]=rand()%1000;
	}
}

void intercala(int v[],int p,int m,int u) {

	int *w =(int*) malloc((u-p+1)*sizeof(int));
	int i= p, j=m+1,k=0;
	while(i<=m && j<=u )
		w[k++]=(v[i]<v[j])?v[i++]:v[j++];
	while(i<=m ){
		w[k++]=v[i++];
	}
	while(j<=u ){
		w[k++]=v[j++];
	}
	for(k=0; k<=u-p; k++){
		v[p+k]=w[k];
	}
	free(w);
}

void ms(int v[],int p,int u) {
	if(p==u ){
		return;
	}
	int m =(p+u)/2;
	ms(v,p,m);
	ms(v,m+1,u);
	intercala(v,p,m,u);
}

void troca(int v[],int i,int j) {
	int x =v[i];
	v[i]= v[j];
	v[j]= x;
}

void bsort(int v[],int n) {

	for(int i= 1; i<n; i++){
		for(int j=0; j<n-i; j++){
			if(v[j] > v[j+1] ){
				troca(v,j,j+1);
			}
		}
	}
}


void msort(int v[],int n) {
	ms(v,0,n-1);
}


int main(void) {

	int v[1e5];
	double t,b,m;
	puts("     n bsort msort");
	
	for(int n= 1e4; n<=1e5; n+=1e4) {
		preenche(v,n,1);
		t = clock();                     // definida em time.h
		bsort(v,n);
		b = (clock()-t)/CLOCKS_PER_SEC;  // tempo do bsort
		
		preenche(v,n,1);
		t =clock();
		msort(v,n);
		m = (clock()-t)/CLOCKS_PER_SEC;  // tempo do msort
		printf("%6d %5.1f %5.1f\n",n,b,m);
	}
	
	return 0;
}
