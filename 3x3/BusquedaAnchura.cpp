#include "BusquedaAnchura.h"


  BusquedaAnchura::BusquedaAnchura(){
    movimientos.aniadirMovimiento("U ");
    movimientos.aniadirMovimiento("Up ");
    movimientos.aniadirMovimiento("U2 ");
    movimientos.aniadirMovimiento("F ");
    movimientos.aniadirMovimiento("Fp ");
    movimientos.aniadirMovimiento("F2 ");
    movimientos.aniadirMovimiento("R ");
    movimientos.aniadirMovimiento("Rp ");
    movimientos.aniadirMovimiento("R2 ");
    movimientos.aniadirMovimiento("B ");
    movimientos.aniadirMovimiento("Bp ");
    movimientos.aniadirMovimiento("B2 ");
    movimientos.aniadirMovimiento("L ");
    movimientos.aniadirMovimiento("Lp ");
    movimientos.aniadirMovimiento("L2 ");
    movimientos.aniadirMovimiento("D ");
    movimientos.aniadirMovimiento("Dp ");
    movimientos.aniadirMovimiento("D2 ");
    ultimosMovimientos[0]='U';
    ultimosMovimientos[1]='U';
    ultimosMovimientos[2]='U';
    ultimosMovimientos[3]='F';
    ultimosMovimientos[4]='F';
    ultimosMovimientos[5]='F';
    ultimosMovimientos[6]='R';
    ultimosMovimientos[7]='R';
    ultimosMovimientos[8]='R';
    ultimosMovimientos[9]='B';
    ultimosMovimientos[10]='B';
    ultimosMovimientos[11]='B';
    ultimosMovimientos[12]='L';
    ultimosMovimientos[13]='L';
    ultimosMovimientos[14]='L';
    ultimosMovimientos[15]='D';
    ultimosMovimientos[16]='D';
    ultimosMovimientos[17]='D';
  }
  Nodo BusquedaAnchura::operacion(Nodo actual, string s){
    Nodo nuevo;
    Cubo aux=actual.cubo;
    Secuencia sec=actual.secuencia;
    aux.mezclaSecuencia(s);
    nuevo.cubo=aux;
    sec.aniadirMovimiento(s);
    nuevo.secuencia=sec;
    nuevo.ultimoMovimiento=s[0];
    return nuevo;
  }
  Secuencia BusquedaAnchura::BA(Cubo c, bool movPosibles[], int fase){
    int tam=0;
    Nodo raiz;
    raiz.cubo=c;
    Secuencia s;
    raiz.secuencia=s;
    raiz.ultimoMovimiento='-';
    cola.push(raiz);
    bool resuelto=false;
    while(!resuelto){
      Nodo actual=cola.front();
      /*
      if(tam!=actual.secuencia.tamSecuencia()){
        tam++;
        cout <<"Tamanio: "<< tam << endl;
      }*/
      if(fase==0){
        if(actual.cubo.pegatinasF2B2()==12){
          solucion=actual.secuencia;
          resuelto=true;
        }
      }
      if(fase==1){
        if(actual.cubo.pegatinasF2R2B2L2()==24){
          solucion=actual.secuencia;
          resuelto=true;
        }
      }
      if(fase==2){
        if(actual.cubo.pegatinasU2D2F2R2B2L2()==48){
          solucion=actual.secuencia;
          resuelto=true;
        }
      }
      if(fase==3){
        if(actual.cubo.pegatinasBien()==48){
          solucion=actual.secuencia;
          resuelto=true;
        }
      }
      if(!resuelto){
        for(int i=0; i<18; i++){
          if(movPosibles[i] && actual.ultimoMovimiento!=ultimosMovimientos[i]){
            Nodo hijo=operacion(actual,movimientos.mostrarMovimiento(i));
            cola.push(hijo);
          }
        }
      }
      cola.pop();
    }
    return solucion;
  }
