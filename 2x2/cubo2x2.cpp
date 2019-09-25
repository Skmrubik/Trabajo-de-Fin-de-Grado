#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <queue>
#include <string>
using namespace std;


class Cubo{
private:
  short perm[8];
  char ori[8];

public:
  Cubo(){
    for(int i=0; i<8; i++){
      perm[i]=i;
    }
    for(int i=0; i<8; i++){
      ori[i]='Y';
    }
  }


  bool resuelto(){
    bool resuelto=true;
    for(short i=0; i<8 and resuelto; i++){
      if(perm[i]!=i)  resuelto=false;
    }
    if(resuelto){
      for(int i=0; i<8 and resuelto; i++){
        if(ori[i]!='Y')   resuelto=false;
      }
    }
    return resuelto;
  }
  void mostrar(){
    cout << "Permutacion:" << endl;
    for(int i=0; i<8; i++){
      cout << perm[i] << " ";
    }
    cout << endl;
    cout << "Orientacion:" << endl;
    for(int i=0; i<8; i++){
      cout << ori[i] << " ";
    }
    cout << endl;
  }

  void U(){
    int aux=perm[0];
    perm[0]=perm[2];
    perm[2]=perm[3];
    perm[3]=perm[1];
    perm[1]=aux;

    for(int i=0; i<4;i++){
      if(ori[perm[i]]=='Z')  ori[perm[i]]='X';
      else if(ori[perm[i]]=='X')  ori[perm[i]]='Z';
    }
  }
  void Up(){
    int aux=perm[0];
    perm[0]=perm[1];
    perm[1]=perm[3];
    perm[3]=perm[2];
    perm[2]=aux;

    for(int i=0; i<4;i++){
      if(ori[perm[i]]=='Z')  ori[perm[i]]='X';
      else if(ori[perm[i]]=='X')  ori[perm[i]]='Z';
    }
  }
  void U2(){
    int aux=perm[0];
    perm[0]=perm[3];
    perm[3]=aux;
    aux=perm[1];
    perm[1]=perm[2];
    perm[2]=aux;
  }
  void R(){
    int aux=perm[1];
    perm[1]=perm[3];
    perm[3]=perm[7];
    perm[7]=perm[5];
    perm[5]=aux;

    for(int i=1; i<8;i+=2){
      if(ori[perm[i]]=='Y')   ori[perm[i]]='Z';
      else if(ori[perm[i]]=='Z')  ori[perm[i]]='Y';
    }
  }

  void Rp(){
    int aux=perm[1];
    perm[1]=perm[5];
    perm[5]=perm[7];
    perm[7]=perm[3];
    perm[3]=aux;

    for(int i=1; i<8;i+=2){
      if(ori[perm[i]]=='Y')   ori[perm[i]]='Z';
      else if(ori[perm[i]]=='Z')  ori[perm[i]]='Y';
    }
  }

  void R2(){
    int aux=perm[1];
    perm[1]=perm[7];
    perm[7]=aux;
    aux=perm[3];
    perm[3]=perm[5];
    perm[5]=aux;
  }

  void F(){
    int aux=perm[2];
    perm[2]=perm[6];
    perm[6]=perm[7];
    perm[7]=perm[3];
    perm[3]=aux;

    if(ori[perm[2]]=='Y')   ori[perm[2]]='X';
    else if(ori[perm[2]]=='X')  ori[perm[2]]='Y';

    if(ori[perm[3]]=='Y')   ori[perm[3]]='X';
    else if(ori[perm[3]]=='X')  ori[perm[3]]='Y';

    if(ori[perm[6]]=='Y')   ori[perm[6]]='X';
    else if(ori[perm[6]]=='X')  ori[perm[6]]='Y';

    if(ori[perm[7]]=='Y')   ori[perm[7]]='X';
    else if(ori[perm[7]]=='X')  ori[perm[7]]='Y';
  }

  void Fp(){
    int aux=perm[2];
    perm[2]=perm[3];
    perm[3]=perm[7];
    perm[7]=perm[6];
    perm[6]=aux;

    if(ori[perm[2]]=='Y')   ori[perm[2]]='X';
    else if(ori[perm[2]]=='X')  ori[perm[2]]='Y';

    if(ori[perm[3]]=='Y')   ori[perm[3]]='X';
    else if(ori[perm[3]]=='X')  ori[perm[3]]='Y';

    if(ori[perm[6]]=='Y')   ori[perm[6]]='X';
    else if(ori[perm[6]]=='X')  ori[perm[6]]='Y';

    if(ori[perm[7]]=='Y')   ori[perm[7]]='X';
    else if(ori[perm[7]]=='X')  ori[perm[7]]='Y';
  }

  void F2(){
    int aux=perm[2];
    perm[2]=perm[7];
    perm[7]=aux;
    aux=perm[3];
    perm[3]=perm[6];
    perm[6]=aux;
  }
};

struct Nodo{
  Cubo c;
  char ultMov;
  string movs;
};
string mezclaAleatoria(Cubo &c, int tam){
  string cadena="";
  int num=rand()%9;
  for(int i=0; i<tam; i++){
    int suma=rand()%6+2;
    num=(num+suma)%9;
    if(num==0){
      c.U();
      cadena+="U ";
    }
    if(num==1){
      c.Up();
      cadena+="U' ";
    }
    if(num==2){
      c.U2();
      cadena+="U2 ";
    }
    if(num==3){
      c.R();
      cadena+="R ";
    }
    if(num==4){
      c.Rp();
      cadena+="R' ";
    }
    if(num==5){
      c.R2();
      cadena+="R2 ";
    }
    if(num==6){
      c.F();
      cadena+="F ";
    }
    if(num==7){
      c.Fp();
      cadena+="F' ";
    }
    if(num==8){
      c.F2();
      cadena+="F2 ";
    }
  }
  return cadena;
}
int main(){
    srand(time(NULL));
    Cubo cubo;
    string mezcla=mezclaAleatoria(cubo,30);
    cout << mezcla << endl;
    queue<Nodo> cola;
    Nodo raiz;
    raiz.c=cubo;
    raiz.ultMov='-';
    cola.push(raiz);
    bool res=false;
    string solucion;

    clock_t tStart = clock();

    while(!res){
      Nodo aux= cola.front();
      Cubo c1=aux.c;
      char m=aux.ultMov;
      if(m=='-'){
        Nodo nuevo;
        Cubo cAlterado;
        cAlterado= c1;
        cAlterado.U();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);

        cAlterado= c1;
        cAlterado.Up();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.U2();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.R();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Rp();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.R2();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.F();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Fp();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.F2();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);
      }
      if(m=='R'){
        Nodo nuevo;
        Cubo cAlterado;
        cAlterado= c1;
        cAlterado.U();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Up();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.U2();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.F();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Fp();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.F2();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);
      }
      if(m=='U'){
        Nodo nuevo;
        Cubo cAlterado;
        cAlterado= c1;
        cAlterado.R();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Rp();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.R2();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.F();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Fp();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.F2();
        nuevo.ultMov='F';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"F2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);
      }
      if(m=='F'){
        Nodo nuevo;
        Cubo cAlterado;
        cAlterado= c1;
        cAlterado.U();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Up();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.U2();
        nuevo.ultMov='U';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"U2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.R();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.Rp();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R' ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);


        cAlterado= c1;
        cAlterado.R2();
        nuevo.ultMov='R';
        nuevo.c=cAlterado;
        nuevo.movs=aux.movs+"R2 ";
        if(cAlterado.resuelto()){
          solucion=nuevo.movs;
          res=true;
        }
        cola.push(nuevo);
      }
      cola.pop();
    }
    double tiempo=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    cout<< "Time taken: " << tiempo<< endl;
    int tamanio=0;
    for(int j=0; j<solucion.size(); j++){
      if(solucion[j]==' ')  tamanio++;
    }

    cout << solucion << endl;
    cout << "TAMANIO: " << tamanio << endl;
    cout << cola.size() << endl;



}
