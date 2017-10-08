#include "bibliotecas.h"
bool apartado[1001];
bool ocupado[1001];
int** copia(int n,int** A){//1+3n+3n^2
	int**nueva = new int*[n];//1
	for(int i=0;i<n;i++){//n+n*(2+3n)
		nueva[i]=new int[n+2];//1
		for(int j=0;j<n;j++){//n+n*2
			nueva[i][j]=300-A[i][j];//2
		}
		nueva[i][i]=0;//1
	}
	return nueva;
}
void suma(int n,int** A){
	for(int i=0;i<n;i++){//2n+3n^2
		A[i][n]=0;//1
		for(int j=0;j<n;j++){
			A[i][n] += A[i][j];
		}
	}
}
pair<int,int> compara_primera(int n,int**A){
	int minima_i,minima_j;//2
	minima_i=0;//1
	minima_j=0;//1
	for(int i=1;i<n;i++){//n+n*2 = 3n
		if(A[i][n] > A[minima_i][n]){//1
			minima_i=i;//1
		}
	}
	for(int j=1;j<n;j++){//n+n*2 = 3n
		if(A[minima_i][j] > A[minima_i][minima_j]){//1
			minima_j=j;//1
		}
	}

	pair<int,int> par;//1
	par.first=minima_i;//1
	par.second=minima_j;//1
	apartado[minima_i]=true;//1
	apartado[minima_j]=true;//1
	return par;
}
//6n^2+11n+10
void aparta_primera(int n,int** A,pair<int,int> indice_min){
	A[indice_min.first][n]+=300;
	A[indice_min.second][n]+=300;
	A[indice_min.first][indice_min.second]=0;
	A[indice_min.second][indice_min.first]=0;
}
//6n^2+11n+14
pair<int,int> compara(int n,pair<int,int> indice_min,int**A){

	int minima_i=0,minima_j=0;//1
	if(A[indice_min.first][n] > A[indice_min.second][n]){//1
		minima_i=indice_min.first;//1
	}else{
		minima_i=indice_min.second;//1
	}

	for(int j=1;j<n;j++){//n+n*2 = 3n
		if(A[minima_i][j] >= A[minima_i][minima_j] && !ocupado[j]){//1
			minima_j=j;//1




		}
	}





	if(!apartado[minima_j]){//1
		apartado[minima_j]=true;//1
	}
	ocupado[minima_i]=true;//1
	pair<int,int> par;//1
	par.first=minima_i;//1

	par.second=minima_j;//1

	return par;
}
//3n+12
void aparta(int n,int** A,pair<int,int> indice_min,pair<int,int> anterior){
	for(int i=0;i<n;i++){//n+n*2 = 3n
		A[i][n]+=300;//2
	}

	A[anterior.second][n]-=A[anterior.first][anterior.second];//2

	//eliminamos la posibilidad de nueva elección
	for(int i=0;i<n;i++){//n+n*2 = 3n
		A[indice_min.first][i]=0;//1
		A[i][indice_min.first]=0;//1
	}
	A[indice_min.first][n]=0;//1
	anterior.first=indice_min.second;//1
}
//6n+4
void regresa(int n,int** nueva){

	for(int i=0;i<n;i++){//n+n*(2+3n)
		delete[] nueva[i];
	}
	delete[] nueva;
}
int* gloton(int n,int** A){
	int* S=new int[n+2];//1
	int** nueva;//1


	pair<int,int> indice_min,actual_min;//2
	deque<int> orden;//1
	nueva=copia(n,A);//3n^2+3n+1
	suma(n,nueva);//3n^2+2n

	indice_min = compara_primera(n,nueva);//6n+9
	aparta_primera(n,nueva,indice_min);//4
	orden.push_back(indice_min.first);//1
	orden.push_back(indice_min.second);//1

	for(int i=2;i<n;i++){//n-2+(n-2)*

		nueva[orden.front()][orden.back()]=0;//1
		nueva[orden.back()][orden.front()]=0;//1
		actual_min = compara(n,indice_min,nueva);//3n+12
		//actualiza minimo


		if(orden.front() == actual_min.first){//1
			orden.push_front(actual_min.second);//1
		}else{
			orden.push_back(actual_min.second);//1
		}
		indice_min.first=orden.front();//1
		indice_min.second=orden.back();//1

		aparta(n,nueva,actual_min,indice_min);//6n+4
	}
	deque<int>::iterator it=orden.begin();//1
	for(int i=0;i<n, it!=orden.end();i++,it++){//n+n*1 = 2n
		S[i]=(*it);//1
	}
	S[n]=calcSol(n,S,A);//2n+2
	regresa(n,nueva);
	return S;
}
//	15n^2+20n-18