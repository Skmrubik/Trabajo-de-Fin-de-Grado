#include <map>
#include "BusquedaProfundidad.h"
class Genetico{
private:
  multimap<int,Secuencia> poblacion;
  Cubo cubo;
  int tamPoblacion;
  int tamSecuencia;

public:
  Genetico(Cubo c, int tam, int tamSec,int fase);
  void mostrarPoblacion();
  void cruzar(Secuencia p1, Secuencia p2, Secuencia &h1, Secuencia &h2);
  Secuencia generacional(int faseIni, int fase,int generaciones,bool memetico,int BLgen, bool BLmejor,int BLit);
};
