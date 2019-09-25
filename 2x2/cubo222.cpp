#include <iostream>
#include "cubo222.h"
using namespace std;

Cubo::Cubo(){
    stickers[0]='W';
    stickers[1]='W';
    stickers[2]='W';
    stickers[3]='W';
    stickers[4]='G';
    stickers[5]='G';
    stickers[6]='G';
    stickers[7]='G';
    stickers[8]='R';
    stickers[9]='R';
    stickers[10]='R';
    stickers[11]='R';
    stickers[12]='B';
    stickers[13]='B';
    stickers[14]='B';
    stickers[15]='B';
    stickers[16]='O';
    stickers[17]='O';
    stickers[18]='O';
    stickers[19]='O';
    stickers[20]='Y';
    stickers[21]='Y';
    stickers[22]='Y';
    stickers[23]='Y';
  }
  void Cubo::mostrar(){
    int cont=0;
    for(int i=0; i<24; i++){
      cout << stickers[i] << " ";
      if(cont==3){
        cout <<"|";
        cont=0;
      }
      else{
        cont++;
      }
    }
    cout << endl;
  }
  //Devuelve el número de pegatinas que estan en su cara
  int Cubo::pegatinasBien(){
    int num=0;
    int i;
    for(i=0; i<4; i++){
      if(stickers[i]=='W')
        num++;
    }
    for(i=4; i<8; i++){
      if(stickers[i]=='G')
        num++;
    }
    for(i=8; i<12; i++){
      if(stickers[i]=='R')
        num++;
    }
    for(i=12; i<16; i++){
      if(stickers[i]=='B')
        num++;
    }
    for(i=16; i<20; i++){
      if(stickers[i]=='O')
        num++;
    }
    for(i=20; i<24; i++){
      if(stickers[i]=='Y')
        num++;
    }
    return num;
  }
  //metodo que nos facilitará a la hora de girar una capa
  void Cubo::rotacionCara(char &a, char &b, char &c, char &d){
    char aux=a;
    a=b;
    b=c;
    c=d;
    d=aux;
  }
  //metodo que nos facilitará a la hora de girar una capa
  void Cubo::rotacionLaterales(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h){
    char aux1, aux2;
    aux1=a;
    aux2=b;
    a=c;
    b=d;
    c=e;
    d=f;
    e=g;
    f=h;
    g=aux1;
    h=aux2;
  }
  //metodo que nos facilitará a la hora de girar una capa
  void Cubo::intercambioCara(char &a, char &b, char &c, char &d){
    char aux=a;
    a=c;
    c=aux;
    aux=b;
    b=d;
    d=aux;
  }
  //metodo que nos facilitará a la hora de girar una capa
  void Cubo::intercambioLaterales(char &a, char &b, char &c, char &d, char &e, char &f, char &g, char &h){
    char aux=a;
    a=e;
    e=aux;
    aux=b;
    b=f;
    f=aux;
    aux=c;
    c=g;
    g=aux;
    aux=d;
    d=h;
    h=aux;
  }
  //Todos los métodos que hacen giros de capas en el cubo 2x2x2
  void Cubo::U(){
    rotacionCara(stickers[0],stickers[2],stickers[3],stickers[1]);
    rotacionLaterales(stickers[4],stickers[5],stickers[8],stickers[9],stickers[12],stickers[13],stickers[16],stickers[17]);
  }
  void Cubo::Up(){
    rotacionCara(stickers[0],stickers[1],stickers[3],stickers[2]);
    rotacionLaterales(stickers[17],stickers[16],stickers[13],stickers[12],stickers[9],stickers[8],stickers[5],stickers[4]);
  }
  void Cubo::U2(){
    intercambioCara(stickers[0],stickers[2],stickers[3],stickers[1]);
    intercambioLaterales(stickers[4],stickers[5],stickers[8],stickers[9],stickers[12],stickers[13],stickers[16],stickers[17]);
  }
  void Cubo::R(){
    rotacionCara(stickers[8],stickers[10],stickers[11],stickers[9]);
    rotacionLaterales(stickers[5],stickers[7],stickers[21],stickers[23],stickers[14],stickers[12],stickers[1],stickers[3]);
  }
  void Cubo::Rp(){
    rotacionCara(stickers[8],stickers[9],stickers[11],stickers[10]);
    rotacionLaterales(stickers[3],stickers[1],stickers[12],stickers[14],stickers[23],stickers[21],stickers[7],stickers[5]);
  }
  void Cubo::R2(){
    intercambioCara(stickers[8],stickers[10],stickers[11],stickers[9]);
    intercambioLaterales(stickers[5],stickers[7],stickers[21],stickers[23],stickers[14],stickers[12],stickers[1],stickers[3]);
  }
  void Cubo::F(){
    rotacionCara(stickers[4],stickers[6],stickers[7],stickers[5]);
    rotacionLaterales(stickers[20],stickers[21],stickers[10],stickers[8],stickers[3],stickers[2],stickers[17],stickers[19]);
  }
  void Cubo::Fp(){
    rotacionCara(stickers[4],stickers[5],stickers[7],stickers[6]);
    rotacionLaterales(stickers[19],stickers[17],stickers[2],stickers[3],stickers[8],stickers[10],stickers[21],stickers[20]);
  }
  void Cubo::F2(){
    intercambioCara(stickers[4],stickers[6],stickers[7],stickers[5]);
    intercambioLaterales(stickers[20],stickers[21],stickers[10],stickers[8],stickers[3],stickers[2],stickers[17],stickers[19]);
  }
  void Cubo::mezclaSecuencia(Secuencia s){
    string aux;
    for(int i=0; i<s.getTamanio();i++){
      aux=s.get(i);
      if(aux[0]=='U'){
        if(aux[1]==' ') U();
        else if(aux[1]=='p') Up();
        else  U2();
      }
      if(aux[0]=='R'){
        if(aux[1]==' ') R();
        else if(aux[1]=='p') Rp();
        else  R2();
      }
      if(aux[0]=='F'){
        if(aux[1]==' ') F();
        else if(aux[1]=='p') Fp();
        else  F2();
      }
    }
  }
