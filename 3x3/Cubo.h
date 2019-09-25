#include <iostream>
#include "Secuencia.h"
using namespace std;

class Cubo{
private:
  char stickers[48];
  //int num;
public:

  Cubo();
  int pegatinasBien();
  int pegatinasF2R2B2L2();
  int pegatinasF2B2();
  int pegatinasU2D2F2R2B2L2();
  int pegatinasLD();
  void rotacionCara(char &a, char &b, char &c, char &d);
  void rotacionLaterales(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h);
  void intercambioCara(char &a, char &b, char &c, char &d);
  void intercambioLaterales(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h);
  void mostrar();
  void cambiarPegatina(int num, char color);
  void U();
  void Up();
  void U2();
  void F();
  void Fp();
  void F2();
  void R();
  void Rp();
  void R2();
  void B();
  void Bp();
  void B2();
  void L();
  void Lp();
  void L2();
  void D();
  void Dp();
  void D2();
  void mezclaSecuencia(Secuencia s);
  void mezclaSecuencia(string s);
};
