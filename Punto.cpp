#include "Punto.h"
Punto::Punto(){
	dimension=0;
	for(int i=0;i<10;i++){
		coord[i]=0;
	}
}
//Punto::Punto(int dimension,list<unsigned int> lista){
Punto::Punto(unsigned short dimension,list<unsigned int> lista){
	this->dimension=dimension;
	list<unsigned int>::iterator it=lista.begin();
	for(int i=0;i<dimension;it++,i++){
		coord[i]=*it;
	}
}
Punto::Punto(const Punto &old){
	dimension= old.dimension;
	for(int i=0;i<dimension;i++){
		coord[i] = old.coord[i];
	}
}
Punto::~Punto(){}
unsigned int Punto::getCoord(unsigned int index){
	return coord[index];
}
unsigned short Punto::getDim(){
	return dimension;
}
unsigned int Punto::distanciaEuclideana(Punto *otro){
	float resultado=0;
	for(int i=0;i<dimension;i++){
		resultado+=std::pow((double)getCoord(i)-(double)(otro)->getCoord(i),2);
	}
	resultado=sqrt(resultado);
	return ceil(resultado);
}
unsigned int Punto::distanciaManhattan(Punto *otro){
	unsigned int resultado=0;
	for(int i=0;i<dimension;i++){
		resultado+=std::abs((int)getCoord(i)-(int)otro->getCoord(i));
	}
	return resultado;
}