#include "cubo222.h"
#include <stdlib.h>
#include <time.h>
//Aplica la metaheuristica de la Búsqueda Local Multiarranque
//puntos: cantidad de "soluciones" desde las que inicia para aproximarse a la solución
//it: iteraciones de cada "solución" antigua para ir escalando hacia una solución
//c: cubo del que partimos, ya mezclado, para encontrar la solución
//tamSol: tamaño de la solución desde la que queremos que empiece
int BL(int puntos, int it, Cubo c, int tamSol){
  bool parar=false;
  while(!parar){ //mientras haya soluciones de más de 0 movimientos las irá buscando
    int puntoDeIntercambio=0; //Al intercambiar dos movimientos consecutivos, este será el primero
    int maximoTodos=0; //Contador de pegatinas que están en su cara

    Secuencia mejorSolucion; //Aquí almacenaremos la mejor solución de "tamSol" movimientos
    Secuencia cadMejor; //Esta es la solución de la que partimos en cada iteración (la mejor hasta ahora)
    Secuencia cadNueva; //Se usa para explorar las soluciones de vecinas de cadMejor
    for(int j=0; j<puntos; j++){
      cadMejor.borrar();
      //int n=solucion(c,cadMejor, tamSol); //generamos una solucion aleatoria de la que partir en la busqueda local
      cadMejor.generaMezcla(tamSol);
      Cubo aux=c;
      aux.mezclaSecuencia(cadMejor);
      int n=aux.pegatinasBien();
      int maximo = n; //almacenamos en maximo el número de pegatians bien que tenemos en esta solucion

      for( int i=0; i<it; i++){ //para "it" iteraciones, intentamos escalar hacia una mejor solucion
        int random = rand() % 10; //Dependiendo de este random, hacemos una mutación u otra
        if(random<4){
          Secuencia cadAux1=cadMejor;
          cadAux1.modificarMov();
          cadNueva=cadAux1;
        }   //cambiar un movimiento de una capa por otro que actua sobre la misma capa
        else {
          Secuencia cadAux2=cadMejor;
          cadAux2.intercambioMovs(puntoDeIntercambio);
          cadNueva=cadAux2;
        }          //interacambiar dos movimientos consecutivos

        Cubo aux2=c;
        aux2.mezclaSecuencia(cadNueva);
        int tam= aux2.pegatinasBien(); //en tam el número de pegatinas que están bien
        //si mejora a la anterior solución, se sustituye
        if(tam>maximo){
          cadMejor.borrar();
          cadMejor=cadNueva;
          maximo = tam;

        }
      }
      //si maximoTodos es menor que maximo, actualizamos
      if(maximoTodos<maximo){
        maximoTodos=maximo;
        mejorSolucion=cadMejor;
        if(maximoTodos==24){ //Si maximoTodos=24 (cubo resuelto) paramos la búsqueda para este número
          j+=100000000;
        }
      }
      if(j==puntos-1){
        parar=true;
      }

    }
    cout << endl;
    //Si ha conseguido encontrar una solución, la muestra
    if(maximoTodos==24){

      cout << "SOLUCIÓN de "<<tamSol <<" movimientos: " << endl;
      mejorSolucion.mostrar();
      //Cubo fin=moverMezcla(c,mejorSolucion);
    }
    else{
      break;
    }

    tamSol--;
  }
  return tamSol+1;
}

int main(){
    srand (time(NULL));
    Cubo c; //Creamos una instancia de la clase
    Secuencia s;
    s.generaMezcla(20);
    c.mezclaSecuencia(s);
    //mostramos la mezcla
    cout << "MEZCLA: " << endl;;
    c.mostrar();
    s.mostrar();
    //Realizamos la busqueda local multiarranque
    clock_t tStart = clock();
    int a=BL(100000,100,c,11);
    double tiempo=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<< "Time taken: " << tiempo<< endl;




}
