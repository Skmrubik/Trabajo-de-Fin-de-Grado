#include "BusquedaProfundidad.h"

  BusquedaProfundidad::BusquedaProfundidad(){
    movimientos[0]="U ";
    movimientos[1]="Up ";
    movimientos[2]="U2 ";
    movimientos[3]="F ";
    movimientos[4]="Fp ";
    movimientos[5]="F2 ";
    movimientos[6]="R ";
    movimientos[7]="Rp ";
    movimientos[8]="R2 ";
    movimientos[9]="B ";
    movimientos[10]="Bp ";
    movimientos[11]="B2 ";
    movimientos[12]="L ";
    movimientos[13]="Lp ";
    movimientos[14]="L2 ";
    movimientos[15]="D ";
    movimientos[16]="Dp ";
    movimientos[17]="D2 ";
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
    parar=false;
  }
  int BusquedaProfundidad::BusquedaProfundidadAux(int prof, Cubo c, Secuencia s, char ultMovimiento){
    if(prof==profMaxima && !parar){
      if(c.pegatinasLD()==2){
        solucion=s;
        s.mostrar();
        parar=true;
        return 0;
      }
    }
    else if(!parar){
      for(int i=0; i<18;i++){
        if(movPosibles[i] && ultMovimiento!=ultimosMovimientos[i]){
          Cubo cuboAux=c;
          cuboAux.mezclaSecuencia(movimientos[i]);
          Secuencia secAux=s;
          secAux.aniadirMovimiento(movimientos[i]);
          BusquedaProfundidadAux(prof+1,cuboAux,secAux, ultimosMovimientos[i]);
        }
      }
    }
  }
  int BusquedaProfundidad::BusquedaProfundidadTotal(int prof, Cubo c, Secuencia s, char ultMovimiento){
    if(prof==profMaxima && !parar){
      if(c.pegatinasBien()==48){
        solucion=s;
        parar=true;
        return 0;
      }
    }
    else if(!parar){
      for(int i=0; i<18;i++){
        if(movPosibles[i] && ultMovimiento!=ultimosMovimientos[i]){
          Cubo cuboAux=c;
          cuboAux.mezclaSecuencia(movimientos[i]);
          Secuencia secAux=s;
          secAux.aniadirMovimiento(movimientos[i]);
          BusquedaProfundidadTotal(prof+1,cuboAux,secAux, ultimosMovimientos[i]);
        }
      }
    }
  }
  void BusquedaProfundidad::setProfMaxima(int a){
    profMaxima=a;
  }
  void BusquedaProfundidad::setMovPosibles(bool mov[]){
    for(int i=0; i<18; i++){
      movPosibles[i]=mov[i];
    }
  }
  Secuencia BusquedaProfundidad::mostrarSolucion(){
    return solucion;
  }
