#include "Genetico.h"
#include <omp.h>
  Genetico::Genetico(Cubo c, int tam, int tamSec,int fase){
    cubo=c;
    tamPoblacion=tam;
    tamSecuencia=tamSec;
    for(int i=0; i<tam;i++){
      Secuencia s;
      if(fase==0) s.generaSecuenciaAleatoria(tamSec);
      if(fase==1) s.generaSecuenciaAleatoriaFase1(tamSec);
      if(fase==2) s.generaSecuenciaAleatoriaFase2(tamSec);
      if(fase==3) s.generaSecuenciaAleatoriaFase3(tamSec);
      Cubo aux=c;
      aux.mezclaSecuencia(s);
      int pegatinas;
      if(fase==0)   pegatinas=aux.pegatinasF2B2();
      if(fase==1)   pegatinas=aux.pegatinasF2R2B2L2();
      if(fase==2)   pegatinas=aux.pegatinasU2D2F2R2B2L2();
      if(fase==3)   pegatinas=aux.pegatinasBien();
      poblacion.insert(pair<int,Secuencia>(pegatinas,s));

    }
  }
  void Genetico::mostrarPoblacion(){
    multimap<int,Secuencia>::iterator it;
    for(it=poblacion.begin(); it!=poblacion.end();++it ){
      cout << (*it).first << " ";
      (*it).second.mostrar();
    }
  }
  void Genetico::cruzar(Secuencia p1, Secuencia p2, Secuencia &h1, Secuencia &h2){
    int mitad=p1.tamSecuencia()/2;
    for(int i=0; i<mitad; i++){
      h1.aniadirMovimiento(p1.mostrarMovimiento(i));
      h2.aniadirMovimiento(p2.mostrarMovimiento(i));
    }
    for(int i=mitad; i<p1.tamSecuencia(); i++){
      h1.aniadirMovimiento(p2.mostrarMovimiento(i));
      h2.aniadirMovimiento(p1.mostrarMovimiento(i));
    }
  }
  Secuencia Genetico::generacional(int faseIni, int fase, int generaciones,bool memetico, int BLgen, bool BLmejor,int BLit){
    int iteracion=0;
    int pegatasBien=0;
    Secuencia mejor;
    int sticker;
    if(fase==0) sticker=12;
    if(fase==1) sticker=24;
    if(fase==2) sticker=47;
    if(fase==3) sticker=48;
    int gen=0;
    multimap<int,Secuencia> aux;
    Cubo auxCubo,auxCubo1,auxCubo2;
    while(pegatasBien!=sticker && gen<generaciones){
      iteracion++;

      aux=poblacion;
      multimap<int,Secuencia>::iterator it=poblacion.begin();
      //elitismo
      for(int i=0; i<98;i++){
        poblacion.erase(it);
        ++it;
      }
      //Mutaciones

        for(int i=0;i<40;i++){
          Secuencia s;
          if(faseIni<2){
            if(faseIni==0) s.generaSecuenciaAleatoria(tamSecuencia);
            else s.generaSecuenciaAleatoriaFase1(tamSecuencia);
          }
          else{
            if(faseIni==2) s.generaSecuenciaAleatoriaFase2(tamSecuencia);
            else s.generaSecuenciaAleatoriaFase3(tamSecuencia);
          }

          auxCubo=cubo;
          auxCubo.mezclaSecuencia(s);
          int pegatinas;
          if(fase<2){
            if(fase==0)   pegatinas=auxCubo.pegatinasF2B2();
            else   pegatinas=auxCubo.pegatinasF2R2B2L2();
          }
          else{
            if(fase==2)   pegatinas=auxCubo.pegatinasU2D2F2R2B2L2();
            else   pegatinas=auxCubo.pegatinasBien();
          }

          poblacion.insert(pair<int,Secuencia>(pegatinas,s));
        }

      //Emparejamiento de padres
      for(int i=0; i<29;i++){
        multimap<int, Secuencia>padresHijos;
        int rand1=rand()%tamPoblacion;
        int rand2= (rand1+(tamPoblacion/2))%tamPoblacion;
        Secuencia p1,p2,h1,h2;
        it=aux.begin();
        advance(it,rand1);
        padresHijos.insert(pair<int,Secuencia>(it->first,it->second));
        p1=(*it).second;
        it=aux.begin();
        advance(it,rand2);
        padresHijos.insert(pair<int,Secuencia>(it->first,it->second));
        p2=(*it).second;
        cruzar(p1,p2,h1,h2);
        auxCubo1=cubo;
        auxCubo1.mezclaSecuencia(h1);
        int pegatinas1;
        if(fase<2){
          if(fase==0)   pegatinas1=auxCubo1.pegatinasF2B2();
          else   pegatinas1=auxCubo1.pegatinasF2R2B2L2();
        }
        else{
          if(fase==2)   pegatinas1=auxCubo1.pegatinasU2D2F2R2B2L2();
          else   pegatinas1=auxCubo1.pegatinasBien();
        }

        auxCubo2=cubo;
        auxCubo2.mezclaSecuencia(h2);
        int pegatinas2;
        if(fase<2){
          if(fase==0)   pegatinas2=auxCubo2.pegatinasF2B2();
          else   pegatinas2=auxCubo2.pegatinasF2R2B2L2();
        }
        else{
          if(fase==2)   pegatinas2=auxCubo2.pegatinasU2D2F2R2B2L2();
          else   pegatinas2=auxCubo2.pegatinasBien();
        }

        padresHijos.insert(pair<int,Secuencia>(pegatinas1,h1));
        padresHijos.insert(pair<int,Secuencia>(pegatinas2,h2));
        it=padresHijos.end();
        --it;
        poblacion.insert(pair<int,Secuencia>(it->first,it->second));
        --it;
        poblacion.insert(pair<int,Secuencia>(it->first,it->second));
      }
      it=poblacion.end();
      --it;
      pegatasBien=it->first;
      if(memetico){
        if(iteracion%BLgen==0){
          multimap<int,Secuencia> poblacionCopia;
          multimap<int,Secuencia>::iterator it;
          poblacionCopia=poblacion;
          poblacion.clear();
          it=poblacionCopia.end();
          --it;
          for(int i=0; i<poblacionCopia.size(); i++){
            mejor=it->second;
            BusquedaLocal b;
            Secuencia mejorada;
            if(!BLmejor)    mejorada=b.busquedaLocal(cubo,BLit,mejor,fase);
            else            mejorada=b.busquedaLocalMejor(cubo,mejor,fase);
            Cubo auxiliarCubo=cubo;
            auxiliarCubo.mezclaSecuencia(mejorada);
            int pegatinasBien;
            if(fase<2){
              if(fase==0)   pegatinasBien=auxiliarCubo.pegatinasF2B2();
              else   pegatinasBien=auxiliarCubo.pegatinasF2R2B2L2();
            }
            else{
              if(fase==2)   pegatinasBien=auxiliarCubo.pegatinasU2D2F2R2B2L2();
              else   pegatinasBien=auxiliarCubo.pegatinasBien();
            }


            poblacion.insert(pair<int,Secuencia>(pegatinasBien,mejorada));
            it--;
          }
        }
      }

      gen++;
    }

    multimap<int,Secuencia>::iterator iter=poblacion.end();
    --iter;
    Secuencia auxiliar;
    if(iter->first==sticker)   return iter->second;
    else                       return auxiliar;
  }
