#include "Menu.h"
#include <time.h>
void Menu::MenuPrincipal(){

  string respuesta="0";
  while(respuesta!="1" and respuesta!="2" and respuesta!="3" and respuesta!="4"){
    system("clear");
    cout <<"MENU PRINCIPAL"<< endl << endl;
    cout <<"1 - Generando una mezcla aleatoria " << endl;
    cout <<"2 - Partiendo de un cubo resuelto e intercambiando las pegatinas " << endl;
    cin >> respuesta;
    if(respuesta=="1"){
      GeneraMezcla();
    }
    if(respuesta=="2"){
      CambiandoPegatinas();
    }
  }

}
void Menu::GeneraMezcla(){
  string respuesta="0";
  while(respuesta!="1" and respuesta!="2"){
    system("clear");
    cout << "Generando mezcla aleatoria" << endl;
    Secuencia s;
    s.generaSecuenciaAleatoria(25);
    cout << "Mezcla:" <<endl;
    s.mostrar();
    cout <<"RESOLUCION DEL CUBO"<< endl << endl;
    cout <<"Memetico:"<<endl;
    cout <<"1 - Resolucion en 4 etapas " << endl;
    cout <<"2 - Resolucion en 3 etapas " << endl;
    cout <<"Genetico:"<<endl;
    cout <<"3 - Resolucion en 4 etapas " << endl;
    cout <<"Busqueda Multiarranque:"<<endl;
    cout <<"4 - Resolucion en 4 etapas " << endl;
    cout <<"0 - Ir atras" << endl;
    cin >> respuesta;
    if(respuesta=="1"){
      Resolver4etapas(s,0);
    }
    if(respuesta=="2"){
      Resolver3etapas(s,0);
    }
    if(respuesta=="3"){
      Resolver4etapas(s,1);
    }
    if(respuesta=="4"){
      ResolverBLM(s);
    }
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }

}
void Menu::Resolver4etapas(Secuencia s, int algoritmo){
  system("clear");
  cout << "RESOLUCION EN 4 ETAPAS" << endl;
  Cubo c;
  cout << "Mezcla: "<<endl;
  c.mezclaSecuencia(s);
  s.mostrar();
  c.mostrar();
  int tam=2;
  Secuencia sol1;
  clock_t tStart = clock();
  if(c.pegatinasF2B2()!=12){
    while(sol1.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,0,3000,true,10,false,100);
        tam++;
      }
      if(algoritmo==1){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,0,3000,false,10,false,100);
        tam++;
      }
    }
  }
  cout << "Fase 0: "<< sol1.tamSecuencia() <<" movimientos"<< endl;
  c.mezclaSecuencia(sol1);

  Secuencia sol2;
  tam=6;
  if(c.pegatinasF2R2B2L2()!=24){
    while(sol2.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g1(c,100,tam,1);
        sol2=g1.generacional(1,1,6000,true,10,false,100);
        tam++;
      }
      if(algoritmo==1){
        Genetico g1(c,100,tam,1);
        sol2=g1.generacional(1,1,15000,false,10,false,100);
        tam++;
      }
    }
  }
  cout << "Fase 1: "<< sol2.tamSecuencia() <<" movimientos"<< endl;
  c.mezclaSecuencia(sol2);
  Secuencia sol3;
  tam=9;
  while(sol3.tamSecuencia()==0){
    if(algoritmo==0){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,8000,true,10,false,100);
      tam++;
    }
    if(algoritmo==1){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,20000,false,10,false,100);
      tam++;
    }

  }
  cout << "Fase 2: " << sol3.tamSecuencia() <<" movimientos"<< endl;
  c.mezclaSecuencia(sol3);
  Secuencia sol4;
  tam=8;
  if(c.pegatinasBien()!=48){
    while(sol4.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,5000,true,10,false,100);
        tam++;
      }
      if(algoritmo==1){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,15000,false,10,false,100);
        tam++;
      }
    }
  }
  cout << "Fase 3: " << sol4.tamSecuencia() <<" movimientos"<<  endl;
  c.mezclaSecuencia(sol4);
  Secuencia aux;
  aux.concatenarSecuencia(sol1);
  aux.concatenarSecuencia(sol2);
  aux.concatenarSecuencia(sol3);
  aux.concatenarSecuencia(sol4);
  aux.movimientosParalelos();
  aux.cancelarMovimientos();
  cout << "Solucion: "<<endl;
  aux.mostrar();
  cout << "TAMANIO: "<<aux.tamSecuencia() << endl;
  cout<< "Time taken: " <<(double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
  string respuesta="1";
  while(respuesta!="0"){
    cout << "Pulsa 0 para ir al menu principal"<< endl;
    cin >> respuesta;
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }
}
void Menu::ResolverBLM(Secuencia s){
  system("clear");
  BusquedaLocal b;
  cout << "RESOLUCION EN 4 ETAPAS" << endl;
  Cubo c;
  cout << "Mezcla: "<<endl;
  Secuencia solucion, solucion2, solucion3, solucion4;
  c.mezclaSecuencia(s);
  s.mostrar();
  c.mostrar();
  int movs=2;
  clock_t tStart = clock();
  while(solucion.tamSecuencia()==0){
    solucion=b.busquedaMultiarranque(movs,50000, 50,c,0);
    movs++;
  }

  cout << "Fase 1: " << solucion.tamSecuencia() <<" movimientos" << endl;
  //solucion.mostrar();
  c.mezclaSecuencia(solucion);
  movs=6;
  while(solucion2.tamSecuencia()==0){
    solucion2=b.busquedaMultiarranque(movs,200000,50,c,1);
    movs++;
  }

  cout << "Fase 2: " << solucion2.tamSecuencia() <<" movimientos"<<  endl;
  //solucion2.mostrar();
  c.mezclaSecuencia(solucion2);
  movs=9;
  while(solucion3.tamSecuencia()==0){
    solucion3=b.busquedaMultiarranque(movs,300000,50,c,2);
    movs++;
    //cout << "Movimientos: " << movs << endl;
  }
  cout << "Fase 3: " << solucion3.tamSecuencia() <<" movimientos"<< endl;
  //solucion3.mostrar();
  c.mezclaSecuencia(solucion3);
  movs=8;
  while(solucion4.tamSecuencia()==0){
    solucion4=b.busquedaMultiarranque(movs,300000,50,c,3);
    movs++;
    //cout << "Movimientos: " << movs << endl;
  }
  cout << "Fase 4: " << solucion4.tamSecuencia() <<" movimientos"<< endl;
  //solucion4.mostrar();
  c.mezclaSecuencia(solucion4);

  Secuencia aux;
  aux.concatenarSecuencia(solucion);
  aux.concatenarSecuencia(solucion2);
  aux.concatenarSecuencia(solucion3);
  aux.concatenarSecuencia(solucion4);
  aux.movimientosParalelos();
  aux.cancelarMovimientos();
  aux.mostrar();
  cout << "TAMANIO: "<<aux.tamSecuencia() << endl;
  cout<< "Time taken: " <<(double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
  string respuesta="1";
  while(respuesta!="0"){
    cout << "Pulsa 0 para ir al menu principal"<< endl;
    cin >> respuesta;
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }
}
void Menu::ResolverBLM(Cubo c){
  system("clear");
  BusquedaLocal b;
  cout << "RESOLUCION EN 4 ETAPAS" << endl;
  Secuencia solucion, solucion2, solucion3, solucion4;
  c.mostrar();
  int movs=2;
  clock_t tStart = clock();
  while(solucion.tamSecuencia()==0){
    solucion=b.busquedaMultiarranque(movs,50000,50,c,0);
    movs++;
  }

  cout << "Fase 1: " << solucion.tamSecuencia() <<" movimientos" << endl;
  //solucion.mostrar();
  c.mezclaSecuencia(solucion);
  movs=6;
  while(solucion2.tamSecuencia()==0){
    solucion2=b.busquedaMultiarranque(movs,200000,50,c,1);
    movs++;
  }

  cout << "Fase 2: " << solucion2.tamSecuencia() <<" movimientos" << endl;
  //solucion2.mostrar();
  c.mezclaSecuencia(solucion2);
  movs=9;
  while(solucion3.tamSecuencia()==0){
    solucion3=b.busquedaMultiarranque(movs,300000,50,c,2);
    movs++;
    //cout << "Movimientos: " << movs << endl;
  }
  cout << "Fase 3: " << solucion3.tamSecuencia() <<" movimientos"<< endl;
  //solucion3.mostrar();
  c.mezclaSecuencia(solucion3);
  movs=8;
  while(solucion4.tamSecuencia()==0){
    solucion4=b.busquedaMultiarranque(movs,300000,50,c,3);
    movs++;
    //cout << "Movimientos: " << movs << endl;
  }
  cout << "Fase 4: " << solucion4.tamSecuencia()<<" movimientos" << endl;
  //solucion4.mostrar();
  c.mezclaSecuencia(solucion4);

  Secuencia aux;
  aux.concatenarSecuencia(solucion);
  aux.concatenarSecuencia(solucion2);
  aux.concatenarSecuencia(solucion3);
  aux.concatenarSecuencia(solucion4);
  aux.movimientosParalelos();
  aux.cancelarMovimientos();
  aux.mostrar();
  cout << "TAMANIO: "<<aux.tamSecuencia() << endl;
  cout<< "Time taken: " <<(double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
  string respuesta="1";
  while(respuesta!="0"){
    cout << "Pulsa 0 para ir al menu principal"<< endl;
    cin >> respuesta;
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }
}
void Menu::Resolver4etapas(Cubo c, int algoritmo){
  system("clear");
  cout << "RESOLUCION EN 4 ETAPAS" << endl;
  c.mostrar();
  int tam=2;
  Secuencia sol1;
  clock_t tStart = clock();
  if(c.pegatinasF2B2()!=12){
    while(sol1.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,0,3000,true,10,false,100);
        tam++;
      }
      if(algoritmo==1){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,0,3000,false,10,false,100);
        tam++;
      }

    }
  }
  cout << "Fase 0: "<< sol1.tamSecuencia()<<" movimientos" << endl;
  c.mezclaSecuencia(sol1);

  Secuencia sol2;
  tam=6;
  if(c.pegatinasF2R2B2L2()!=24){
    while(sol2.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g1(c,100,tam,1);
        sol2=g1.generacional(1,1,6000,true,10,false,100);
        tam++;
      }
      if(algoritmo==1){
        Genetico g1(c,100,tam,1);
        sol2=g1.generacional(1,1,15000,false,10,false,100);
        tam++;
      }
    }
  }
  cout << "Fase 1: "<< sol2.tamSecuencia() <<" movimientos"<< endl;
  c.mezclaSecuencia(sol2);
  Secuencia sol3;
  tam=9;
  while(sol3.tamSecuencia()==0){
    if(algoritmo==0){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,8000,true,10,false,100);
      tam++;
    }
    if(algoritmo==1){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,20000,false,10,false,100);
      tam++;
    }

  }
  cout << "Fase 2: " << sol3.tamSecuencia()<<" movimientos" << endl;
  c.mezclaSecuencia(sol3);
  Secuencia sol4;
  tam=8;
  if(c.pegatinasBien()!=48){
    while(sol4.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,5000,true,10,false,100);
        tam++;
      }
      if(algoritmo==1){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,15000,false,10,false,100);
        tam++;
      }
    }
  }
  cout << "Fase 3: " << sol4.tamSecuencia() <<" movimientos"<<  endl;
  c.mezclaSecuencia(sol4);
  Secuencia aux;
  aux.concatenarSecuencia(sol1);
  aux.concatenarSecuencia(sol2);
  aux.concatenarSecuencia(sol3);
  aux.concatenarSecuencia(sol4);
  aux.movimientosParalelos();
  aux.cancelarMovimientos();
  cout << "Solucion: "<<endl;
  aux.mostrar();
  cout << "TAMANIO: "<<aux.tamSecuencia() << endl;
  cout<< "Time taken: " <<(double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
  string respuesta="1";
  while(respuesta!="0"){
    cout << "Pulsa 0 para ir al menu principal"<< endl;
    cin >> respuesta;
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }
}
void Menu::Resolver3etapas(Secuencia s, int algoritmo){
  system("clear");
  cout << "RESOLUCION EN 3 ETAPAS" << endl;
  Cubo c;
  c.mezclaSecuencia(s);
  c.mostrar();
  cout << "Mezcla:"<< endl;
  s.mostrar();
  int tam=9;
  Secuencia sol1;
  clock_t tStart = clock();
  if(c.pegatinasF2R2B2L2()!=24){
    while(sol1.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,1,15000,true,5,false,50);
        tam++;
      }
      if(algoritmo==1){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,1,50000,false,5,false,50);
        tam++;
      }

    }
  }
  cout << "Fase 0: "<< sol1.tamSecuencia() <<" movimientos"<< endl;
  c.mezclaSecuencia(sol1);

  Secuencia sol3;
  tam=9;
  while(sol3.tamSecuencia()==0){
    if(algoritmo==0){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,8000,true,5,false,50);
      tam++;
    }
    if(algoritmo==1){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,10000,false,5,false,50);
      tam++;
    }

  }
  cout << "Fase 1: " << sol3.tamSecuencia() <<" movimientos"<< endl;
  c.mezclaSecuencia(sol3);
  Secuencia sol4;
  tam=8;
  if(c.pegatinasBien()!=48){
    while(sol4.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,5000,true,5,false,50);
        tam++;
      }
      if(algoritmo==1){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,8000,false,5,false,50);
        tam++;
      }
    }
  }
  cout << "Fase 2: " << sol4.tamSecuencia()<<" movimientos" <<  endl;
  c.mezclaSecuencia(sol4);

  Secuencia aux;
  aux.concatenarSecuencia(sol1);
  aux.concatenarSecuencia(sol3);
  aux.concatenarSecuencia(sol4);
  aux.movimientosParalelos();
  aux.cancelarMovimientos();
  cout << "Solucion:"<<endl;
  aux.mostrar();
  cout << "TAMANIO: "<<aux.tamSecuencia() << endl;
  cout<< "Time taken: " <<(double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
  string respuesta="1";
  while(respuesta!="0"){
    cout << "Pulsa 0 para ir al menu principal"<< endl;
    cin >> respuesta;
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }
}
void Menu::Resolver3etapas(Cubo c, int algoritmo){
  system("clear");
  cout << "RESOLUCION EN 3 ETAPAS" << endl;
  c.mostrar();
  int tam=9;
  Secuencia sol1;
  clock_t tStart = clock();
  if(c.pegatinasF2R2B2L2()!=24){
    while(sol1.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,1,15000,true,5,false,50);
        tam++;
      }
      if(algoritmo==1){
        Genetico g(c,100,tam,0);
        sol1=g.generacional(0,1,25000,false,5,false,50);
        tam++;
      }

    }
  }
  cout << "Fase 0: "<< sol1.tamSecuencia() <<" movimientos"<< endl;
  c.mezclaSecuencia(sol1);

  Secuencia sol3;
  tam=9;
  while(sol3.tamSecuencia()==0){
    if(algoritmo==0){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,8000,true,5,false,50);
      tam++;
    }
    if(algoritmo==1){
      Genetico g2(c,100,tam,2);
      sol3=g2.generacional(2,2,10000,false,5,false,50);
      tam++;
    }

  }
  cout << "Fase 1: " << sol3.tamSecuencia()<<" movimientos" << endl;
  c.mezclaSecuencia(sol3);
  Secuencia sol4;
  tam=8;
  if(c.pegatinasBien()!=48){
    while(sol4.tamSecuencia()==0){
      if(algoritmo==0){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,5000,true,5,false,50);
        tam++;
      }
      if(algoritmo==1){
        Genetico g3(c,100,tam,3);
        sol4=g3.generacional(3,3,8000,false,5,false,50);
        tam++;
      }
    }
  }
  cout << "Fase 2: " << sol4.tamSecuencia() <<" movimientos"<<  endl;
  c.mezclaSecuencia(sol4);

  Secuencia aux;
  aux.concatenarSecuencia(sol1);
  aux.concatenarSecuencia(sol3);
  aux.concatenarSecuencia(sol4);
  aux.movimientosParalelos();
  aux.cancelarMovimientos();
  cout << "Solucion:"<<endl;
  aux.mostrar();
  cout << "TAMANIO: "<<aux.tamSecuencia() << endl;
  cout<< "Time taken: " <<(double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
  string respuesta="1";
  while(respuesta!="0"){
    cout << "Pulsa 0 para ir al menu principal"<< endl;
    cin >> respuesta;
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }
}
void Menu::CambiandoPegatinas(){
  char pegatina='Z';
  Cubo c;
  while(pegatina!='S'){
    system("clear");
    c.mostrar();
    cout << "            -------------"<< endl;
    cout << "            | 0 - 1 - 2 |"<<endl;
    cout << "            | 7 -(W)- 3 |"<<endl;
    cout << "            | 6 - 5 - 4 |"<<endl;
    cout << "-------------------------------------------------"<<endl;
    cout << "|32 -33 -34 |";
    cout << " 8 - 9 -10 |";
    cout << "16 -17 -18 |";
    cout << "24 -25 -26 |"<<endl;
    cout << "|39 -(O)-35 |";
    cout << "15 -(G)-11 |";
    cout << "23 -(R)-19 |";
    cout << "31 -(B)-27 |" << endl;
    cout << "|38 -37 -36 |";
    cout << "14 -13 -12 |";
    cout << "22 -21 -20 |";
    cout << "30 -29 -28 |"<<endl;
    cout << "-------------------------------------------------"<<endl;
    cout << "            |40 -41 -42 |"<<endl;
    cout << "            |47 -(Y)-43 |"<<endl;
    cout << "            |46 -45 -44 |"<<endl;
    cout << "            -------------"<< endl;
    pegatina='A';
    cout << "Primero indica el color de la pegatina al que quieres cambiar y despues el número de pegatina que corresponde" << endl;
    while(pegatina!='W' and pegatina!='G' and pegatina!='R' and pegatina!='B' and pegatina!='O' and pegatina!='Y' and pegatina!='S'){

      cout << "Indica color de pegatina a cambiar (W,G,R,B,0,Y) o 'S' para resolver" << endl;
      cin >>pegatina;
    }
    int numPegatina=100;
    if(pegatina!='S'){
      while(numPegatina>47 or numPegatina<0){
        cout << "Indica ahora el numero de la pegatina (del 0 al 47)"<<endl;
        cin>>numPegatina;
      }
      c.cambiarPegatina(numPegatina,pegatina);
    }


  }
  system("clear");
  string respuesta="0";
  while(respuesta!="1" and respuesta!="2"){
    system("clear");
    c.mostrar();
    cout <<"RESOLUCION DEL CUBO"<< endl << endl;
    cout <<"Memetico" << endl;
    cout <<"1 - Resolucion en 4 etapas " << endl;
    cout <<"2 - Resolucion en 3 etapas " << endl;
    cout <<"Genetico:"<<endl;
    cout <<"3 - Resolucion en 4 etapas " << endl;
    cout <<"Busqueda Multiarranque:"<<endl;
    cout <<"4 - Resolucion en 4 etapas " << endl;
    cout <<"0 - Ir atras" << endl;
    cin >> respuesta;
    if(respuesta=="1"){
      Resolver4etapas(c,0);
    }
    if(respuesta=="2"){
      Resolver3etapas(c,0);
    }
    if(respuesta=="3"){
      Resolver4etapas(c,1);
    }
    if(respuesta=="4"){
      ResolverBLM(c);
    }
    if(respuesta=="0"){
      MenuPrincipal();
    }
  }
}
