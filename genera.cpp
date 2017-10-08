#include "genera.h"
#include "Punto.h"
int** floydWarshall(int n,int** A){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        A[i][j]= std::min(A[i][j],A[i][k] + A[k][j]);
      }
    }
  }
  return A;
}
std::list<unsigned int> generaPuntos(unsigned int i,unsigned short d,unsigned short l){
  int x;
	std::list<unsigned int> lista;
	//std::cout<<"punto "<<i<<": ";
	for(int j=0;j<d;j++){
		//x=distribution(generator);
		x=rand()%(l-1)+1;
		lista.push_back(x);
		//std::cout<<" "<<x;
	}
  return lista;
}
int** genEuclideano(unsigned short n,unsigned short d,unsigned short l){
	Punto punto[n];
	for (unsigned int i=0;i<n;i++){
		Punto punkt(d,generaPuntos(i,d,l));
		//std::cout<<endl;
		punto[i]=punkt;
	}
	int** A = new int*[n];
	for (int i=0;i<n;i++){
		A[i]=new int[n+2];
		for(int j=0;j<n;j++){
			A[i][j]=punto[i].distanciaEuclideana(&punto[j]);
			//cout<<"distancia de "<<i<<" a "<<j<<": "<<A[i][j]<<endl;
		}
		//cout<<endl;
	}
	return A;
}
int** genManhattan(unsigned short n,unsigned short d,unsigned short l){
	Punto punto[n];
	for (unsigned int i=0;i<n;i++){
		Punto punkt(d,generaPuntos(i,d,l));
		cout<<endl;
		punto[i]=punkt;
  }
	int** A = new int*[n];
	for (int i=0;i<n;i++){
		A[i]=new int[n+2];
		for(int j=0;j<n;j++){
			A[i][j]=punto[i].distanciaManhattan(&punto[j]);
			//cout<<"distancia de "<<i<<" a "<<j<<": "<<A[i][j]<<endl;
		}
		//cout<<endl;
	}
	return A;
}
int** genGrafico(unsigned short n,unsigned short l){
	int** A = new int*[n];
	for (int i=0;i<n;i++){
		A[i]=new int[n+2];
		for(int j=0;j<n;j++){
			A[i][j] = rand()%(l-1)+1;
			//cout<<"distancia de "<<i<<" a "<<j<<": "<<A[i][j]<<endl;
		}
		A[i][i]=0;
		//cout<<endl;
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			A[i][j] = A[j][i];
		}
		A[i][i]=0;
	}
	A = floydWarshall(n,A);
	return A;
}