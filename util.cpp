#include "util.h"
#include "Punto.h"

void imprimeMatriz(unsigned short n,int** A){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			std::cout<<A[i][j]<<"\t";
		}
			std::cout<<endl;
	}
}
void imprimeVector(int n,int* S){
	for(int i=0;i<n;i++){
		std::cout<<S[i]<<"\t";
	}
	std::cout<<endl;
}
void imprime_vector_matriz(int n,int j,int** A){
	for(int i=0;i<n;i++){
		std::cout<<A[i][j]<<"\t";
	}
	std::cout<<endl;
}
bool esMinima(int x,int &longitudMinima){
	longitudMinima=min(x,longitudMinima);
	if(longitudMinima!=x){
		return true;
	}
	return false;
}