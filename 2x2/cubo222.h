#ifndef CUBO_H
#define CUBO_H
#include <iostream>
#include "Secuencia.h"
using namespace std;

class Cubo{
  char stickers[24];

public:
  Cubo();
  void mostrar();
  int pegatinasBien();
  void rotacionCara(char &a, char &b, char &c, char &d);
  void rotacionLaterales(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h);
  void intercambioCara(char &a, char &b, char &c, char &d);
  void intercambioLaterales(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h);
  void U();
  void Up();
  void U2();
  void R();
  void Rp();
  void R2();
  void F();
  void Fp();
  void F2();
  void mezclaSecuencia(Secuencia s);
};
#endif
