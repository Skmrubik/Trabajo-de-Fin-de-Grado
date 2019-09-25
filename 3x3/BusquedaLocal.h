#include "Cubo.h"
#include <iostream>
using namespace std;

class BusquedaLocal{
private:
  Secuencia mejor;
  Secuencia actual;
  Secuencia vecina;
public:
  BusquedaLocal();
  Secuencia generaVecino(Secuencia s, int &i, int fase);
  Secuencia busquedaLocal(Cubo c, int it, Secuencia s, int fase);
  Secuencia busquedaLocalMejor(Cubo c, Secuencia s, int fase);
  Secuencia busquedaMultiarranque(int tamSecuencia,int itArranque, int itBL, Cubo c,int fase);
  int pegatinasBienSecuencia(Cubo c,  Secuencia s, int fase);
};
