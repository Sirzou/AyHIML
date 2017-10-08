#include<iostream>
using namespace std;
bool tomado[1000];
bool repetido[1000];
bool esta_tomado(int num){
	if(!tomado[num]){
		tomado[num]=true;
	}else{
		if(!repetido[num]){
			repetido[num]=true;
		}else{
			cout<<"Error.Repetido!"<<endl;
			return true;
		}
	}
	return false;
}/*
int main(){
	int a,b;
	for(int i=0;i<1000;i++){
		cin>>a>>b;
		if(esta_tomado(a)||esta_tomado(b)){
			cout<<"linea "<<i<<endl;
			return 0;
		}
	}
	return 0;
}*/