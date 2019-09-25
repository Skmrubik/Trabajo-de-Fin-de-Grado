#include "Secuencia.h"
string Secuencia::get(int i){
  return secuencia[i];
}
int Secuencia::getTamanio(){
  return secuencia.size();
}
void Secuencia::borrar(){
  secuencia.clear();
}
void Secuencia::mostrar(){
  for(int i=0; i<secuencia.size();i++){
    cout << secuencia[i];
  }
  cout << endl;
}
//Al hacer un movimiento U añade a cad dicho movimiento
void Secuencia::generaU(){
  int num = rand() % 3;
  if(num==0){
    secuencia.push_back("U ");
  }
  else if(num==1){
    secuencia.push_back("Up ");
  }
  else{
    secuencia.push_back("U2 ");
  }
}
//Al hacer un movimiento R añade a cad dicho movimiento
void Secuencia::generaR(){
  int num = rand() % 3;
  if(num==0){
    secuencia.push_back("R ");
  }
  else if(num==1){
    secuencia.push_back("Rp ");
  }
  else{
    secuencia.push_back("R2 ");
  }
}
//Al hacer un movimiento F añade a cad dicho movimiento
void Secuencia::generaF(){
  int num = rand() % 3;
  if(num==0){
    secuencia.push_back("F ");
  }
  else if(num==1){
    secuencia.push_back("Fp ");
  }
  else{
    secuencia.push_back("F2 ");
  }
}
//genera una solución aleatoria de c (tamaño "tam") y devuelve cuantas pegatinas estan bien
void Secuencia::generaMezcla(int tam){
  int num = rand() %3;
  for(int i=0; i<tam; i++){
    int aux = rand() % 2 + 1;
    num=(num+aux)%3;
    if(num==0){
      generaR();
    }
    else if(num==1){
      generaU();
    }
    else{
      generaF();
    }
  }
}

//Dada una cadena de movimientos y un entero i, intercambia los movimientos i e i+1
void Secuencia::intercambioMovs( int &i){
  if(i==secuencia.size()-1)   i=0;

  string aux=secuencia[i];
  secuencia[i]=secuencia[i+1];
  secuencia[i+1]=aux;
  i++;
}
//modifica un movimiento de la cadena girando la misma capa del movimiento de una mamera distinta
void Secuencia::modificarMov(){
  int i= rand() % (secuencia.size());
  if(secuencia[i][1]==' '){
    secuencia[i][1]='p';
    secuencia[i]+=' ';
  }
  else if(secuencia[i][1]=='p'){
    secuencia[i][1]='2';
  }
  else{
    secuencia[i][1]='p';
  }
}
