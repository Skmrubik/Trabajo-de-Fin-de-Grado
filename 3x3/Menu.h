#include "Genetico.h"
#include <stdlib.h>
class Menu{
public:
  void MenuPrincipal();
  void GeneraMezcla();
  void Resolver4etapas(Secuencia s,int algoritmo);
  void Resolver3etapas(Secuencia s,int algoritmo);
  void Resolver4etapas(Cubo c,int algoritmo);
  void Resolver3etapas(Cubo c,int algoritmo);
  void ResolverBLM(Secuencia s);
  void ResolverBLM(Cubo c);
  void CambiandoPegatinas();
};
