#include <cmath>
#include <list>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <deque>
using namespace std;

int calcSol(unsigned short n,int* S,int** A);
int* evalua(unsigned short n,int** A);
int* evaluaMinimal(unsigned short n,int**A);
void evenPermute(int N,int n,int*S,int**A,int suma);
void oddPermute(int N,int n,int*S,int**A,int suma);
void permute(int N,int n,int * S,int ** A);
int reEvalua(int N,int i,int j,int** A,int* S,int suma);


int** copia(int n,int** A);
void suma(int n,int** A);
pair<int,int> compara_primera(int n,int**A);
void aparta_primera(int n,int** A,pair<int,int> indice_min);
pair<int,int> compara(int n,pair<int,int> indice_min,int**A);
void aparta(int n,int** A,pair<int,int> indice_min,pair<int,int> anterior);
int* gloton(int n,int** A);