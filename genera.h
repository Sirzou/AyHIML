#include "bibliotecas.h"
using namespace std;
int** floydWarshall(int n,int** A);
std::list<unsigned int> generaPuntos(unsigned int i,unsigned short d,unsigned short l);
int** genEuclideano(unsigned short n,unsigned short d,unsigned short l);
int** genManhattan(unsigned short n,unsigned short d,unsigned short l);
int** genGrafico(unsigned short n,unsigned short l);