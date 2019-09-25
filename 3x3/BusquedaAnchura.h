#include <queue>
#include <iostream>
#include <vector>
#include "BusquedaLocal.h"
using namespace std;

struct Nodo{
public:
  Cubo cubo;
  Secuencia secuencia;
  char ultimoMovimiento;
};
class BusquedaAnchura{
private:
  Nodo raiz;
  queue <Nodo> cola;
  Secuencia movimientos;
  char ultimosMovimientos[18];
  Secuencia solucion;
public:
  BusquedaAnchura();
  Nodo operacion(Nodo actual, string s);
  Secuencia BA(Cubo c, bool movPosibles[],int fase);
};
