#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class Secuencia{
private:
  vector<string> secuencia;
public:
  Secuencia();
  void aniadirMovimiento(string s);
  void eliminarUltMovimiento();
  string mostrarMovimiento(int i);
  int tamSecuencia();
  void borrarSecuencia();
  string generaMov(char id);
  void generaSecuenciaAleatoria(int tam);
  void generaSecuenciaAleatoriaFase1(int tam);
  void generaSecuenciaAleatoriaFase2(int tam);
  void generaSecuenciaAleatoriaFase3(int tam);
  void mostrar();
  void intercambioMovimientos(int &i);
  void intercambioMovimientos();
  void cambiarMovimiento();
  void modificarMovimiento();
  void modificarMovimiento(int i);
  void modificarMovimientoFase1();
  void modificarMovimientoFase1(int i);
  void modificarMovimientoFase2();
  void modificarMovimientoFase2(int i);
  void concatenarSecuencia(Secuencia s);
  void cancelarMovimientos();
  void insertarMovimiento(string s,int i);
  void eliminarMovimiento(int i);
  void movimientosParalelos();
};
