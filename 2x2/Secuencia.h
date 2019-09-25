#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Secuencia{
private:
	vector<string> secuencia;
public:
	int getTamanio();
	void borrar();
	void mostrar();
	string get(int i);
	void generaU();
	void generaR();
	void generaF();
	void generaMezcla(int tam);
	void intercambioMovs( int &i);
	void modificarMov();
};
#endif
