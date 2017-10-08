#include "Punto.h"
#include "bibliotecas.h"
#include "genera.h"
#include "util.h"

void prueba_det(){
	unsigned short n,d,l,switcher;
	//cin>>n>>d>>l>>switcher;
	d=10;l=100;switcher=2;
	cin>>n;
	int** A;
	switch(switcher){
	case 1:
		A = genEuclideano(n,d,l);
		imprimeMatriz(n,A);
		break;
	case 2:
		A = genManhattan(n,d,l);
		imprimeMatriz(n,A);
		break;
	case 3:
		A = genGrafico(n,l);
		imprimeMatriz(n,A);
		break;
	default:
		break;
	}
	int* S=new int[n+2];
	S=evaluaMinimal(n,A);
	cout<<"Deterministicamente:"<<endl;
	cout<<"La menor incrustacion en la recta es de longitud "<<S[n]<<endl;
	cout<<"Y sigue la secuencia: "<<endl;
	imprimeVector(n,S);
	cout<<"permutacion numero "<<S[n+1]<<endl;
}

void prueba_heu(){
	unsigned short n,d,l,switcher;	
	//cin>>n>>d>>l>>switcher;
	d=10;l=100;
	cin>>n;
	int** A;
	
	int* S=new int[n+2];
	A = genEuclideano(n,d,l);
	//imprimeMatriz(n,A);

	S = gloton(n,A);

	cout<<"Heurísticamente: "<<endl;
	cout<<"La menor incrustacion en la recta es de longitud "<<S[n]<<endl;
	cout<<"Y sigue la secuencia: "<<endl;
	imprimeVector(n,S);
}

void det_contra_heu_2(int n){
	unsigned short d,l;
	//cin>>n>>d>>l;
	d=10;l=100;
	int** A;
	int** nueva;
	int* S=new int[n+2];
	A = genEuclideano(n,d,l);

	int long_det,long_heu;
	float dif_porc;

	S=evaluaMinimal(n,A);
	long_det=S[n];

	cout<<"Deterministicamente:"<<endl;
	cout<<"La menor incrustacion en la recta es de longitud "<<S[n]<<endl;
	cout<<"Y sigue la secuencia: "<<endl;
	imprimeVector(n,S);
	cout<<"permutacion numero "<<S[n+1]<<endl;


	S = gloton(n,A);
	long_heu=S[n];
	dif_porc = 100*((float)(long_heu-long_det))/(float)long_heu;

	cout<<"Heurísticamente: "<<endl;
	cout<<"La menor incrustacion en la recta es de longitud "<<S[n]<<endl;
	cout<<"Y sigue la secuencia: "<<endl;
	imprimeVector(n,S);
	cout<<"Error: "<<long_heu-long_det<<". Error Porcentual: "<< dif_porc <<"%."<<endl;
}
void det_contra_heu(int n){
	time_t inicia_d,termina_d,tiempo_d,inicia_h,termina_h,tiempo_h;
	unsigned short d,l;
	//cin>>n>>d>>l;
	d=10;l=100;
	int** A;
	int** nueva;
	int* S=new int[n+2];
	A = genEuclideano(n,d,l);

	int long_det,long_heu;
	float dif_porc;
	if(n<13){
		inicia_d=clock();
		S=evaluaMinimal(n,A);
		termina_d=clock();
		tiempo_d=termina_d-inicia_d;
		long_det=S[n];

		cout<<long_det<<"\t"<<tiempo_d<<"\t";

		inicia_h=clock();
		S = gloton(n,A);
		termina_h=clock();
		tiempo_h=termina_h-inicia_h;

		long_heu=S[n];
		dif_porc = 100*((float)(long_heu-long_det))/(float)long_heu;

		cout<<long_heu<<"\t"<<tiempo_h<<"\t";
		cout<<(long_heu-long_det)<<"\t"<< dif_porc;
		cout<<"\t"<<(tiempo_d-tiempo_h);
		cout<<endl;
	}else{

		inicia_h=clock();
		S = gloton(n,A);
		termina_h=clock();
		tiempo_h=termina_h-inicia_h;

		long_heu=S[n];

		cout<<long_heu<<"\t"<<tiempo_h<<endl;
	}


}

int main(){
	srand(time(NULL));
	//prueba_det();//15! tarda 17 hrs.
	//prueba_heu();
	int n,M=10;
	cin>>n;
	//for(int i=0;i<M;i++){
		det_contra_heu(n);
	//}
	cout<<CLOCKS_PER_SEC<<endl;
	return 0;
}


