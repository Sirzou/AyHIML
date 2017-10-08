#include "bibliotecas.h"
#include "util.h"
long long int nf[16]={1,1,2,6,
24,120,720,5040,40320,362880,
3628800,39916800,479001600,
6227020800,87178291200,
1307674368000};
int longitudMinima;
int respuesta[1001];
int contador;
int calcSol(unsigned short n,int* S,int** A){
	int longitud=0;
	for(int i=1;i<n;i++){
		longitud+=A[S[i]][S[i-1]];
	}
	return longitud;
}
int* evaluaMinimal(unsigned short n,int**A){
	longitudMinima=5000;
	int* S= new int[n+2];
	for(int i=0;i<n;i++){
		S[i]=i;
	}
	permute(n,n,S,A);
	return respuesta;
}
void evenPermute(int N,int n,int*S,int**A,int suma){
	if(N>n+1){
		suma+=A[S[n]][S[n+1]];
	}
	oddPermute(N, n-1, S, A,suma);
	for(int i=0;i<(n-1);i++){
		swap(S[i], S[n-1]);
		oddPermute(N, n-1, S, A,suma);
	}
}
void oddPermute(int N,int n,int*S,int**A,int suma){
	if(n==1){
		suma+=A[S[n-1]][S[n]]+A[S[n]][S[n+1]];
		if(!esMinima(suma,longitudMinima)){
			for(int i=0;i<N;i++){
				respuesta[i]=S[i];
			}
		respuesta[N]=longitudMinima;
		respuesta[N+1]=contador;
		}
		contador++;
	}else{
		if(N>n+1){
			suma+=A[S[n]][S[n+1]];
		}
		evenPermute(N,n-1,S, A,suma);
		for(int i=0;i<(n-1);i++){
			swap(S[0], S[n-1]);
			evenPermute(N,n-1,S, A,suma);
		}
	}
}
void permute(int N,int n,int * S,int ** A){
	int suma=0;
	contador=0;
	longitudMinima=5000;
	int x=calcSol(n,S, A);
	if(n%2!=0){
		oddPermute(N,n,S,A,suma);
	}else{
		evenPermute(N,n,S,A,suma);
	}
}