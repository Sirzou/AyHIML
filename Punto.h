#include "bibliotecas.h"
class Punto{
	int coord[10];
	unsigned short dimension;
public:
	Punto();
	Punto(unsigned short,list<unsigned int>);
	Punto(const Punto &old);
	~Punto();
	unsigned int getCoord(unsigned int);
	unsigned short getDim();
	unsigned int distanciaEuclideana(Punto*);
	unsigned int distanciaManhattan(Punto*);
};