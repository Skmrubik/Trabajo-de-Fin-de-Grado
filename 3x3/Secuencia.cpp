#include "Secuencia.h"
  Secuencia::Secuencia(){}
  void Secuencia::aniadirMovimiento(string s){
    secuencia.push_back(s);
  }
  void Secuencia::eliminarUltMovimiento(){
    secuencia.pop_back();
  }
  int Secuencia::tamSecuencia(){
    return secuencia.size();
  }
  void Secuencia::borrarSecuencia(){
    secuencia.clear();
  }
  void Secuencia::concatenarSecuencia(Secuencia s){
    for(int i=0; i<s.tamSecuencia();i++){
      aniadirMovimiento(s.mostrarMovimiento(i));
    }
  }
  string Secuencia::generaMov(char id){
    string movimiento;
    movimiento+=id;
    int num = rand() % 3;
    if(num==0){
    }
    else if(num==1){
      movimiento+="p";
    }
    else{
      movimiento+="2";
    }
    return movimiento;
  }
  void Secuencia::generaSecuenciaAleatoria(int tam){
    borrarSecuencia();
    string s;
    int num = rand() %6;
    for(int i=0; i<tam; i++){
      int aux = rand() % 5 + 1;
      num=(num+aux)%6;
      if(num<2){
        if(num==0){
          s=generaMov('U');
          aniadirMovimiento(s);
        }
        else{
          s=generaMov('F');
          aniadirMovimiento(s);
        }
      }
      else if(num>3){
        if(num==4){
          s=generaMov('R');
          aniadirMovimiento(s);
        }
        else{
          s=generaMov('B');
          aniadirMovimiento(s);
        }
      }
      else{
        if(num==2){
          s=generaMov('L');
          aniadirMovimiento(s);
        }
        else{
          s=generaMov('D');
          aniadirMovimiento(s);
        }
      }
    }
  }
  void Secuencia::generaSecuenciaAleatoriaFase1(int tam){
    borrarSecuencia();
    string s;
    int num = rand() %6;
    for(int i=0; i<tam; i++){
      int aux = rand() % 5 + 1;
      num=(num+aux)%6;
      if(num<2){
        if(num==0){
          s=generaMov('U');
          aniadirMovimiento(s);
        }
        else{
          aniadirMovimiento("F2");
        }
      }
      else if(num>3){
        if(num==4){
          s=generaMov('L');
          aniadirMovimiento(s);
        }
        else{
          s=generaMov('D');
          aniadirMovimiento(s);
        }
      }
      else{
        if(num==2){
          s=generaMov('R');
          aniadirMovimiento(s);
        }
        else{
          aniadirMovimiento("B2");

        }
      }
    }
  }
  void Secuencia::generaSecuenciaAleatoriaFase2(int tam){
    borrarSecuencia();
    string s;
    int num = rand() %6;
    for(int i=0; i<tam; i++){
      int aux = rand() % 5 + 1;
      num=(num+aux)%6;
      if(num<2){
        if(num==0){
          s=generaMov('U');
          aniadirMovimiento(s);
        }
        else{
          aniadirMovimiento("F2");
        }
      }
      else if(num>3){
        if(num==4){
          aniadirMovimiento("L2");
        }
        else{
          s=generaMov('D');
          aniadirMovimiento(s);
        }
      }
      else{
        if(num==2){
          aniadirMovimiento("R2");
        }
        else{
          aniadirMovimiento("B2");
        }
      }

    }
  }
  void Secuencia::generaSecuenciaAleatoriaFase3(int tam){
    borrarSecuencia();
    string s;
    int num = rand() %6;
    for(int i=0; i<tam; i++){
      int aux = rand() % 5 + 1;
      num=(num+aux)%6;
      if(num<2){
        if(num==0){
          aniadirMovimiento("U2");
        }
        else{
          aniadirMovimiento("F2");
        }
      }
      else if(num>3){
        if(num==4){
          aniadirMovimiento("R2");
        }
        else{
          aniadirMovimiento("B2");
        }
      }
      else{
        if(num==2){
          aniadirMovimiento("L2");
        }
        else{
          aniadirMovimiento("D2");
        }
      }
    }
  }
  void Secuencia::mostrar(){
    for(int i=0; i<secuencia.size();i++){
      cout << secuencia[i] << " ";
    }
    cout << endl;
  }
  void Secuencia::intercambioMovimientos(int &i){
    if(i==secuencia.size()-1)   i=0;

    string aux=secuencia[i];
    secuencia[i]=secuencia[i+1];
    secuencia[i+1]=aux;
    i++;
  }
  void Secuencia::intercambioMovimientos(){
    int i= rand()%(secuencia.size()-2);

    string aux=secuencia[i];
    secuencia[i]=secuencia[i+1];
    secuencia[i+1]=aux;
  }
  void Secuencia::cambiarMovimiento(){
    int i= rand() % (secuencia.size());
    if(secuencia[i][0]>'G'){
      if(secuencia[i][0]=='U')  secuencia[i][0]=='F';
      else if(secuencia[i][0]=='R')  secuencia[i][0]=='B';
      else  secuencia[i][0]=='D';
    }
    else{
      if(secuencia[i][0]=='F')  secuencia[i][0]=='R';
      else if(secuencia[i][0]=='B')  secuencia[i][0]=='L';
      else secuencia[i][0]=='U';
    }

  }
  void Secuencia::modificarMovimiento(){
    int i= rand() % (secuencia.size());
    if(secuencia[i].size()==1){
      secuencia[i]+='p';
    }
    else if(secuencia[i][1]=='p'){
      secuencia[i][1]='2';
    }
    else{
      secuencia[i].erase(secuencia[i].size()-1);
    }
  }
  void Secuencia::modificarMovimiento(int i){
    if(secuencia[i].size()==1){
      secuencia[i]+='p';
    }
    else if(secuencia[i][1]=='p'){
      secuencia[i][1]='2';
    }
    else if(secuencia[i][1]=='2'){
      secuencia[i].erase(secuencia[i].size()-1);
    }
  }
  void Secuencia::modificarMovimientoFase1(){
    int i= rand() % (secuencia.size());
    if(secuencia[i][0]!='B' and secuencia[i][0]!='F'){
      if(secuencia[i].size()==1){
        secuencia[i]+='p';
      }
      else if(secuencia[i][1]=='p'){
        secuencia[i][1]='2';
      }
      else{
        secuencia[i].erase(secuencia[i].size()-1);
      }
    }
  }
  void Secuencia::modificarMovimientoFase1(int i){
    if(secuencia[i][0]!='B' and secuencia[i][0]!='F'){
      if(secuencia[i].size()==1){
        secuencia[i]+='p';
      }
      else if(secuencia[i][1]=='p'){
        secuencia[i][1]='2';
      }
      else{
        secuencia[i].erase(secuencia[i].size()-1);
      }
    }
  }
  void Secuencia::modificarMovimientoFase2(){
    int i= rand() % (secuencia.size());
    if(secuencia[i][0]!='B' and secuencia[i][0]!='F' and secuencia[i][0]!='L' and secuencia[i][0]!='R'){
      if(secuencia[i].size()==1){
        secuencia[i]+='p';
      }
      else if(secuencia[i][1]=='p'){
        secuencia[i][1]='2';
      }
      else{
        secuencia[i].erase(secuencia[i].size()-1);
      }
    }
  }
  void Secuencia::modificarMovimientoFase2(int i){
    if(secuencia[i][0]!='B' and secuencia[i][0]!='F' and secuencia[i][0]!='L' and secuencia[i][0]!='R'){
      if(secuencia[i].size()==1){
        secuencia[i]+='p';
      }
      else if(secuencia[i][1]=='p'){
        secuencia[i][1]='2';
      }
      else{
        secuencia[i].erase(secuencia[i].size()-1);
      }
    }
  }
  string Secuencia::mostrarMovimiento(int i){
    return secuencia[i];
  }
  void Secuencia::insertarMovimiento(string s,int i){
    secuencia.insert(secuencia.begin()+i,s);
  }
  void Secuencia::eliminarMovimiento(int i){
    secuencia.erase(secuencia.begin()+i);
  }
  void Secuencia::cancelarMovimientos(){
    string primero;
    string segundo;
    int numCancelaciones=-1;
    while(numCancelaciones!=0){
      numCancelaciones=0;
      for(int i=0; i<tamSecuencia()-1;i++){
        primero=mostrarMovimiento(i);
        segundo=mostrarMovimiento(i+1);

        if(primero[0]==segundo[0]){
          numCancelaciones++;
          if(primero.size()==1){
            if(segundo.size()==1){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
              string aux="";
              aux+=primero[0];
              aux+="2";
              insertarMovimiento(aux, i);
            }
            else if(segundo[1]=='2'){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
              string aux="";
              aux+=primero[0];
              aux+="p";
              insertarMovimiento(aux,i);
            }
            else if(segundo[1]=='p'){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
            }
          }
          if(primero[1]=='2'){
            if(segundo.size()==1){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
              string aux="";
              aux+=primero[0];
              aux+="p";
              insertarMovimiento(aux, i);
            }
            else if(segundo[1]=='p'){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
              string aux="";
              aux+=primero[0];
              insertarMovimiento(aux,i);
            }
            else if(segundo[1]=='2'){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
            }
          }
          if(primero[1]=='p'){
            if(segundo[1]=='p'){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
              string aux="";
              aux+=primero[0];
              aux+="2";
              insertarMovimiento(aux, i);
            }
            else if(segundo[1]=='2'){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
              string aux="";
              aux+=primero[0];
              insertarMovimiento(aux,i);
            }
            else if(segundo.size()==1){
              eliminarMovimiento(i);
              eliminarMovimiento(i);
            }
          }
        }
      }

    }
  }
  void Secuencia::movimientosParalelos(){
    int numMovsParalelos=-1;
    while(numMovsParalelos!=0){
      numMovsParalelos=0;
      for(int i=0; i<tamSecuencia()-2;i++){
        string primero=mostrarMovimiento(i);
        string segundo=mostrarMovimiento(i+1);
        string tercero=mostrarMovimiento(i+2);
        if(primero[0]=='U' && segundo[0]=='D' && tercero[0]=='U'){
          numMovsParalelos++;
          int aux=i+1;
          intercambioMovimientos(aux);
        }
        if(primero[0]=='D' && segundo[0]=='U' && tercero[0]=='D'){
          numMovsParalelos++;
          int aux=i+1;
          intercambioMovimientos(aux);
        }
        if(primero[0]=='F' && segundo[0]=='B' && tercero[0]=='F'){
          numMovsParalelos++;
          int aux=i+1;
          intercambioMovimientos(aux);
        }
        if(primero[0]=='B' && segundo[0]=='F' && tercero[0]=='B'){
          numMovsParalelos++;
          int aux=i+1;
          intercambioMovimientos(aux);
        }
        if(primero[0]=='L' && segundo[0]=='R' && tercero[0]=='L'){
          numMovsParalelos++;
          int aux=i+1;
          intercambioMovimientos(aux);
        }
        if(primero[0]=='R' && segundo[0]=='L' && tercero[0]=='R'){
          numMovsParalelos++;
          int aux=i+1;
          intercambioMovimientos(aux);
        }
      }
    }

  }
