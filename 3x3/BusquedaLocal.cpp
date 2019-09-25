#include "BusquedaLocal.h"

BusquedaLocal::BusquedaLocal(){}
Secuencia BusquedaLocal::generaVecino(Secuencia s, int &i, int fase){
  Secuencia aux=s;
  if(fase!=3){
    int random = rand() % 10; //Dependiendo de este random, hacemos una mutación u otra
    if(random<4){
      if(fase==0)   aux.modificarMovimiento();
      if(fase==1)   aux.modificarMovimientoFase1();
      if(fase==2)   aux.modificarMovimientoFase2();
    }
    else{
      aux.intercambioMovimientos(i);
    }

  }
  else{
    aux.intercambioMovimientos(i);
  }

  return aux;
}

int BusquedaLocal::pegatinasBienSecuencia(Cubo c, Secuencia s, int fase){
  c.mezclaSecuencia(s);
  if(fase<2){
    if(fase==0){
      return c.pegatinasF2B2();
    }
    else{
      return c.pegatinasF2R2B2L2();
    }
  }
  else{
    if(fase==2){
      return c.pegatinasU2D2F2R2B2L2();
    }
    else{
      return c.pegatinasBien();
    }
  }

}

Secuencia BusquedaLocal::busquedaLocal(Cubo c, int it, Secuencia s, int fase){
  int indice=0;
  int pegatinas;
  if(fase<2){
    if(fase==0) pegatinas=12;
    else pegatinas=24;
  }
  else{
    if(fase==2) pegatinas=47;
    else pegatinas=48;
  }

  int stickersBien=pegatinasBienSecuencia(c,s,fase);
  Secuencia mejorSolucion=s;
  for(int i=0; i<it && stickersBien!=pegatinas; i++){
    Secuencia vecina=generaVecino(mejorSolucion,indice,fase);
    if(pegatinasBienSecuencia(c,vecina,fase)>stickersBien){
      mejorSolucion=vecina;
      stickersBien=pegatinasBienSecuencia(c,vecina,fase);
    }

  }
  return mejorSolucion;
}

Secuencia BusquedaLocal::busquedaLocalMejor(Cubo c, Secuencia s, int fase){
  int indice=0;
  int pegatinas;
  if(fase==0) pegatinas=12;
  if(fase==1) pegatinas=24;
  if(fase==2) pegatinas=47;
  if(fase==3) pegatinas=48;
  int stickersBien=pegatinasBienSecuencia(c,s,fase);
  Secuencia mejorSolucion=s;
  bool encuentraMejor=true;
  while(encuentraMejor && stickersBien!=pegatinas){
    encuentraMejor=false;
    if(fase==3){
      for(int i=0; i<s.tamSecuencia()-1; i++){
        int pegatinasSecuenciaOrigen=pegatinasBienSecuencia(c,mejorSolucion,fase);
        s.intercambioMovimientos(i);
        int pegatinasSecuenciaMod=pegatinasBienSecuencia(c,s,fase);
        if(pegatinasSecuenciaMod>pegatinasSecuenciaOrigen){
          mejorSolucion=s;
          encuentraMejor=true;
        }
        s.intercambioMovimientos(i);
      }
    }
    else{
      for(int i=0; i<s.tamSecuencia(); i++){
        int pegatinasSecuenciaOrigen=pegatinasBienSecuencia(c,mejorSolucion,fase);
        if(fase==0)   s.modificarMovimiento(i);
        if(fase==1)   s.modificarMovimientoFase1(i);
        if(fase==2)   s.modificarMovimientoFase2(i);
        int pegatinasSecuenciaMod=pegatinasBienSecuencia(c,s,fase);
        if(pegatinasSecuenciaMod>pegatinasSecuenciaOrigen){
          mejorSolucion=s;
          encuentraMejor=true;
        }
        pegatinasSecuenciaOrigen=pegatinasBienSecuencia(c,mejorSolucion,fase);
        if(fase==0)   s.modificarMovimiento(i);
        if(fase==1)   s.modificarMovimientoFase1(i);
        if(fase==2)   s.modificarMovimientoFase2(i);
        pegatinasSecuenciaMod=pegatinasBienSecuencia(c,s,fase);
        if(pegatinasSecuenciaMod>pegatinasSecuenciaOrigen){
          mejorSolucion=s;
          encuentraMejor=true;
        }
        if(fase==0)   s.modificarMovimiento(i);
        if(fase==1)   s.modificarMovimientoFase1(i);
        if(fase==2)   s.modificarMovimientoFase2(i);
        stickersBien=pegatinasBienSecuencia(c,mejorSolucion,fase);
      }
    }

  }
  return mejorSolucion;
}

Secuencia BusquedaLocal::busquedaMultiarranque(int tamSecuencia, int itArranque, int itBL, Cubo c, int fase){
  if(fase==0)   actual.generaSecuenciaAleatoria(tamSecuencia);
  if(fase==1)   actual.generaSecuenciaAleatoriaFase1(tamSecuencia);
  if(fase==2)   actual.generaSecuenciaAleatoriaFase2(tamSecuencia);
  if(fase==3)   actual.generaSecuenciaAleatoriaFase3(tamSecuencia);
  mejor=actual;
  int pegatinas;
  if(fase==0) pegatinas=12;
  if(fase==1) pegatinas=24;
  if(fase==2) pegatinas=47;
  if(fase==3) pegatinas=48;
  int iteracion=0;
  int pegatinasBien=pegatinasBienSecuencia(c,mejor,fase);
  while(pegatinasBien!=pegatinas and iteracion<itArranque){
    vecina=busquedaLocal(c,itBL,actual,fase);
    if(pegatinasBienSecuencia(c,vecina,fase)>pegatinasBienSecuencia(c,mejor,fase)){
      mejor=vecina;
      pegatinasBien=pegatinasBienSecuencia(c,mejor,fase);
    }
    if(fase==0)   actual.generaSecuenciaAleatoria(tamSecuencia);
    if(fase==1)   actual.generaSecuenciaAleatoriaFase1(tamSecuencia);
    if(fase==2)   actual.generaSecuenciaAleatoriaFase2(tamSecuencia);
    if(fase==3)   actual.generaSecuenciaAleatoriaFase3(tamSecuencia);
    iteracion++;
  }
  if(iteracion==itArranque){
    Secuencia s;
    return s;
  }
  else{
    return mejor;
  }

}
