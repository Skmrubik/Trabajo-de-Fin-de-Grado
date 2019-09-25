#include "BusquedaAnchura.h"
using namespace std;

class BusquedaProfundidad{
private:
  bool movPosibles[18];
  char ultimosMovimientos[18];
  int profMaxima;
  string movimientos[18];
  Secuencia solucion;
  bool parar;
public:

  BusquedaProfundidad();
  int BusquedaProfundidadAux(int prof, Cubo c, Secuencia s, char ultMovimiento);
  int BusquedaProfundidadTotal(int prof, Cubo c, Secuencia s, char ultMovimiento);
  void setProfMaxima(int a);
  void setMovPosibles(bool mov[]);
  Secuencia mostrarSolucion();
};
