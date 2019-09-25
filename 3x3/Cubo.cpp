#include "Cubo.h"
#include <omp.h>

  Cubo::Cubo(){
    stickers[0]='W';
    stickers[1]='W';
    stickers[2]='W';
    stickers[3]='W';
    stickers[4]='W';
    stickers[5]='W';
    stickers[6]='W';
    stickers[7]='W';
    stickers[8]='G';
    stickers[9]='G';
    stickers[10]='G';
    stickers[11]='G';
    stickers[12]='G';
    stickers[13]='G';
    stickers[14]='G';
    stickers[15]='G';
    stickers[16]='R';
    stickers[17]='R';
    stickers[18]='R';
    stickers[19]='R';
    stickers[20]='R';
    stickers[21]='R';
    stickers[22]='R';
    stickers[23]='R';
    stickers[24]='B';
    stickers[25]='B';
    stickers[26]='B';
    stickers[27]='B';
    stickers[28]='B';
    stickers[29]='B';
    stickers[30]='B';
    stickers[31]='B';
    stickers[32]='O';
    stickers[33]='O';
    stickers[34]='O';
    stickers[35]='O';
    stickers[36]='O';
    stickers[37]='O';
    stickers[38]='O';
    stickers[39]='O';
    stickers[40]='Y';
    stickers[41]='Y';
    stickers[42]='Y';
    stickers[43]='Y';
    stickers[44]='Y';
    stickers[45]='Y';
    stickers[46]='Y';
    stickers[47]='Y';
  }
  int Cubo::pegatinasBien(){
    int num=0;
    int i;

    for(i=0; i<8; i++){
      if(stickers[i]=='W')
        num++;
    }
    for(i=8; i<16; i++){
      if(stickers[i]=='G')
        num++;
    }
    for(i=16; i<24; i++){
      if(stickers[i]=='R')
        num++;
    }
    for(i=24; i<32; i++){
      if(stickers[i]=='B')
        num++;
    }
    for(i=32; i<40; i++){
      if(stickers[i]=='O')
        num++;
    }
    for(i=40; i<48; i++){
      if(stickers[i]=='Y')
        num++;
    }
    return num;
  }
  int Cubo::pegatinasU2D2F2R2B2L2(){
    int num=0;
    int i;
    if(stickers[0]=='W') num++;
    if(stickers[1]=='W' or stickers[1]=='Y')  num++;
    if(stickers[2]=='W') num++;
    if(stickers[3]=='W' or stickers[3]=='Y')  num++;
    if(stickers[4]=='W') num++;
    if(stickers[5]=='W' or stickers[5]=='Y')  num++;
    if(stickers[6]=='W') num++;
    if(stickers[7]=='W' or stickers[7]=='Y')  num++;

    if(stickers[8]=='G') num++;
    if(stickers[9]=='G' or stickers[9]=='B')  num++;
    if(stickers[10]=='G') num++;
    if(stickers[11]=='G' or stickers[11]=='B')  num++;
    if(stickers[12]=='G') num++;
    if(stickers[13]=='G' or stickers[13]=='B')  num++;
    if(stickers[14]=='G') num++;
    if(stickers[15]=='G' or stickers[15]=='B')  num++;

    if(stickers[16]=='R') num++;
    if(stickers[17]=='R' or stickers[17]=='O')  num++;
    if(stickers[18]=='R') num++;
    if(stickers[19]=='R' or stickers[19]=='O')  num++;
    if(stickers[20]=='R') num++;
    if(stickers[21]=='R' or stickers[21]=='O')  num++;
    if(stickers[22]=='R') num++;
    if(stickers[23]=='R' or stickers[23]=='O')  num++;

    if(stickers[24]=='B') num++;
    if(stickers[25]=='G' or stickers[25]=='B')  num++;
    if(stickers[26]=='B') num++;
    if(stickers[27]=='G' or stickers[27]=='B')  num++;
    if(stickers[28]=='B') num++;
    if(stickers[29]=='G' or stickers[29]=='B')  num++;
    if(stickers[30]=='B') num++;
    if(stickers[31]=='G' or stickers[31]=='B')  num++;

    if(stickers[32]=='0') num++;
    if(stickers[33]=='R' or stickers[33]=='O')  num++;
    if(stickers[34]=='O') num++;
    if(stickers[35]=='R' or stickers[35]=='O')  num++;
    if(stickers[36]=='O') num++;
    if(stickers[37]=='R' or stickers[37]=='O')  num++;
    if(stickers[38]=='O') num++;
    if(stickers[39]=='R' or stickers[39]=='O')  num++;

    if(stickers[40]=='Y') num++;
    if(stickers[41]=='W' or stickers[41]=='Y')  num++;
    if(stickers[42]=='Y') num++;
    if(stickers[43]=='W' or stickers[43]=='Y')  num++;
    if(stickers[44]=='Y') num++;
    if(stickers[45]=='W' or stickers[45]=='Y')  num++;
    if(stickers[46]=='Y') num++;
    if(stickers[47]=='W' or stickers[47]=='Y')  num++;

    return num;
  }
  int Cubo::pegatinasF2R2B2L2(){

    int num=0;
    int i;
    for(i=0; i<8; i++){
      if(stickers[i]=='W' or stickers[i]=='Y')
        num++;
    }
    if(stickers[15]=='B' or stickers[15]=='G'){
      num++;
    }
    if(stickers[11]=='B' or stickers[11]=='G'){
      num++;
    }
    if(stickers[31]=='B' or stickers[31]=='G'){
      num++;
    }
    if(stickers[27]=='B' or stickers[27]=='G'){
      num++;
    }
    if(stickers[23]=='R' or stickers[23]=='O'){
      num++;
    }
    if(stickers[19]=='R' or stickers[19]=='O'){
      num++;
    }
    if(stickers[39]=='R' or stickers[39]=='O'){
      num++;
    }
    if(stickers[35]=='R' or stickers[35]=='O'){
      num++;
    }
    for(i=40; i<48; i++){
      if(stickers[i]=='Y' or stickers[i]=='W')
        num++;
    }
    return num;
  }
  int Cubo::pegatinasF2B2(){
    int numWY=0;
    int numGB=0;
    int num;
    int i;
    int pegatinas[]={1,3,5,7,11,15,27,31,41,43,45,47};
    for(i=0; i<12; i++){
      if(stickers[pegatinas[i]]=='W' or stickers[pegatinas[i]]=='Y'){
        numWY++;
      }
      if(stickers[pegatinas[i]]=='B' or stickers[pegatinas[i]]=='G'){
        numGB++;
      }
    }
    if(numWY!=8){
      num=numWY+4;
    }
    else{
      num=numWY+numGB;
    }
    return num;
  }
  int Cubo::pegatinasLD(){
    int num=0;
    if(stickers[37]=='O' and stickers[47]=='Y')  num=2;
    return num;
  }
  void Cubo::rotacionCara(char &a, char &b, char &c, char &d){
    char aux=a;
    a=b;
    b=c;
    c=d;
    d=aux;
  }
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
  void Cubo::intercambioCara(char &a, char &b, char &c, char &d){
    char aux=a;
    a=c;
    c=aux;
    aux=b;
    b=d;
    d=aux;
  }
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
  void Cubo::mostrar(){
    cout << "            -------------"<< endl;
    cout << "            | "<<stickers[0]<<" - "<<stickers[1]<<" - "<<stickers[2]<<" |"<<endl;
    cout << "            | "<<stickers[7]<<" -(W)- "<<stickers[3]<<" |"<<endl;
    cout << "            | "<<stickers[6]<<" - "<<stickers[5]<<" - "<<stickers[4]<<" |"<<endl;
    cout << "-------------------------------------------------"<<endl;
    cout << "| "<<stickers[32]<<" - "<<stickers[33]<<" - "<<stickers[34]<<" | ";
    cout << stickers[8]<<" - "<<stickers[9]<<" - "<<stickers[10]<<" | ";
    cout << stickers[16]<<" - "<<stickers[17]<<" - "<<stickers[18]<<" | ";
    cout << stickers[24]<<" - "<<stickers[25]<<" - "<<stickers[26]<<" | "<<endl;
    cout << "| "<<stickers[39]<<" -(O)- "<<stickers[35]<<" | ";
    cout << stickers[15]<<" -(G)- "<<stickers[11]<<" | ";
    cout << stickers[23]<<" -(R)- "<<stickers[19]<<" | ";
    cout << stickers[31]<<" -(B)- "<<stickers[27]<<" | " << endl;
    cout << "| "<<stickers[38]<<" - "<<stickers[37]<<" - "<<stickers[36]<<" | ";
    cout << stickers[14]<<" - "<<stickers[13]<<" - "<<stickers[12]<<" | ";
    cout << stickers[22]<<" - "<<stickers[21]<<" - "<<stickers[20]<<" | ";
    cout << stickers[30]<<" - "<<stickers[29]<<" - "<<stickers[28]<<" | "<<endl;
    cout << "-------------------------------------------------"<<endl;
    cout << "            | "<<stickers[40]<<" - "<<stickers[41]<<" - "<<stickers[42]<<" |"<<endl;
    cout << "            | "<<stickers[47]<<" -(Y)- "<<stickers[43]<<" |"<<endl;
    cout << "            | "<<stickers[46]<<" - "<<stickers[45]<<" - "<<stickers[44]<<" |"<<endl;
    cout << "            -------------"<< endl;

  }
  void Cubo::cambiarPegatina(int num, char color){
    stickers[num]=color;
  }
  void Cubo::U(){
    rotacionLaterales(stickers[7],stickers[6],stickers[5],stickers[4],stickers[3],stickers[2],stickers[1],stickers[0]);
    rotacionLaterales(stickers[32],stickers[34],stickers[8],stickers[10],stickers[16],stickers[18],stickers[24],stickers[26]);
    rotacionCara(stickers[33],stickers[9],stickers[17],stickers[25]);
  }
  void Cubo::Up(){
    rotacionLaterales(stickers[0],stickers[1],stickers[2],stickers[3],stickers[4],stickers[5],stickers[6],stickers[7]);
    rotacionLaterales(stickers[26],stickers[24],stickers[18],stickers[16],stickers[10],stickers[8],stickers[34],stickers[32]);
    rotacionCara(stickers[25],stickers[17],stickers[9],stickers[33]);
  }
  void Cubo::U2(){
    intercambioLaterales(stickers[0],stickers[1],stickers[2],stickers[3],stickers[4],stickers[5],stickers[6],stickers[7]);
    intercambioLaterales(stickers[26],stickers[24],stickers[18],stickers[16],stickers[10],stickers[8],stickers[34],stickers[32]);
    intercambioCara(stickers[25],stickers[17],stickers[9],stickers[33]);
  }
  void Cubo::F(){
    rotacionLaterales(stickers[15],stickers[14],stickers[13],stickers[12],stickers[11],stickers[10],stickers[9],stickers[8]);
    rotacionLaterales(stickers[34],stickers[36],stickers[40],stickers[42],stickers[22],stickers[16],stickers[4],stickers[6]);
    rotacionCara(stickers[35],stickers[41],stickers[23],stickers[5]);
  }
  void Cubo::Fp(){
    rotacionLaterales(stickers[8],stickers[9],stickers[10],stickers[11],stickers[12],stickers[13],stickers[14],stickers[15]);
    rotacionLaterales(stickers[6],stickers[4],stickers[16],stickers[22],stickers[42],stickers[40],stickers[36],stickers[34]);
    rotacionCara(stickers[5],stickers[23],stickers[41],stickers[35]);
  }
  void Cubo::F2(){
    intercambioLaterales(stickers[8],stickers[9],stickers[10],stickers[11],stickers[12],stickers[13],stickers[14],stickers[15]);
    intercambioLaterales(stickers[6],stickers[4],stickers[16],stickers[22],stickers[42],stickers[40],stickers[36],stickers[34]);
    intercambioCara(stickers[5],stickers[23],stickers[41],stickers[35]);
  }
  void Cubo::R(){
    rotacionLaterales(stickers[23],stickers[22],stickers[21],stickers[20],stickers[19],stickers[18],stickers[17],stickers[16]);
    rotacionLaterales(stickers[10],stickers[12],stickers[42],stickers[44],stickers[30],stickers[24],stickers[2],stickers[4]);
    rotacionCara(stickers[11],stickers[43],stickers[31],stickers[3]);
  }
  void Cubo::Rp(){
    rotacionLaterales(stickers[16],stickers[17],stickers[18],stickers[19],stickers[20],stickers[21],stickers[22],stickers[23]);
    rotacionLaterales(stickers[4],stickers[2],stickers[24],stickers[30],stickers[44],stickers[42],stickers[12],stickers[10]);
    rotacionCara(stickers[3],stickers[31],stickers[43],stickers[11]);
  }
  void Cubo::R2(){
    intercambioLaterales(stickers[16],stickers[17],stickers[18],stickers[19],stickers[20],stickers[21],stickers[22],stickers[23]);
    intercambioLaterales(stickers[4],stickers[2],stickers[24],stickers[30],stickers[44],stickers[42],stickers[12],stickers[10]);
    intercambioCara(stickers[3],stickers[31],stickers[43],stickers[11]);
  }
  void Cubo::B(){
    rotacionLaterales(stickers[31],stickers[30],stickers[29],stickers[28],stickers[27],stickers[26],stickers[25],stickers[24]);
    rotacionLaterales(stickers[18],stickers[20],stickers[44],stickers[46],stickers[38],stickers[32],stickers[0],stickers[2]);
    rotacionCara(stickers[19],stickers[45],stickers[39],stickers[1]);
  }
  void Cubo::Bp(){
    rotacionLaterales(stickers[24],stickers[25],stickers[26],stickers[27],stickers[28],stickers[29],stickers[30],stickers[31]);
    rotacionLaterales(stickers[2],stickers[0],stickers[32],stickers[38],stickers[46],stickers[44],stickers[20],stickers[18]);
    rotacionCara(stickers[1],stickers[39],stickers[45],stickers[19]);
  }
  void Cubo::B2(){
    intercambioLaterales(stickers[24],stickers[25],stickers[26],stickers[27],stickers[28],stickers[29],stickers[30],stickers[31]);
    intercambioLaterales(stickers[2],stickers[0],stickers[32],stickers[38],stickers[46],stickers[44],stickers[20],stickers[18]);
    intercambioCara(stickers[1],stickers[39],stickers[45],stickers[19]);
  }
  void Cubo::L(){
    rotacionLaterales(stickers[39],stickers[38],stickers[37],stickers[36],stickers[35],stickers[34],stickers[33],stickers[32]);
    rotacionLaterales(stickers[26],stickers[28],stickers[46],stickers[40],stickers[14],stickers[8],stickers[6],stickers[0]);
    rotacionCara(stickers[27],stickers[47],stickers[15],stickers[7]);
  }
  void Cubo::Lp(){
    rotacionLaterales(stickers[32],stickers[33],stickers[34],stickers[35],stickers[36],stickers[37],stickers[38],stickers[39]);
    rotacionLaterales(stickers[0],stickers[6],stickers[8],stickers[14],stickers[40],stickers[46],stickers[28],stickers[26]);
    rotacionCara(stickers[7],stickers[15],stickers[47],stickers[27]);
  }
  void Cubo::L2(){
    intercambioLaterales(stickers[32],stickers[33],stickers[34],stickers[35],stickers[36],stickers[37],stickers[38],stickers[39]);
    intercambioLaterales(stickers[0],stickers[6],stickers[8],stickers[14],stickers[40],stickers[46],stickers[28],stickers[26]);
    intercambioCara(stickers[7],stickers[15],stickers[47],stickers[27]);
  }
  void Cubo::D(){
    rotacionLaterales(stickers[47],stickers[46],stickers[45],stickers[44],stickers[43],stickers[42],stickers[41],stickers[40]);
    rotacionLaterales(stickers[36],stickers[38],stickers[28],stickers[30],stickers[20],stickers[22],stickers[12],stickers[14]);
    rotacionCara(stickers[37],stickers[29],stickers[21],stickers[13]);
  }
  void Cubo::Dp(){
    rotacionLaterales(stickers[40],stickers[41],stickers[42],stickers[43],stickers[44],stickers[45],stickers[46],stickers[47]);
    rotacionLaterales(stickers[14],stickers[12],stickers[22],stickers[20],stickers[30],stickers[28],stickers[38],stickers[36]);
    rotacionCara(stickers[13],stickers[21],stickers[29],stickers[37]);
  }
  void Cubo::D2(){
    intercambioLaterales(stickers[40],stickers[41],stickers[42],stickers[43],stickers[44],stickers[45],stickers[46],stickers[47]);
    intercambioLaterales(stickers[14],stickers[12],stickers[22],stickers[20],stickers[30],stickers[28],stickers[38],stickers[36]);
    intercambioCara(stickers[13],stickers[21],stickers[29],stickers[37]);
  }
  void Cubo::mezclaSecuencia(Secuencia s){
    string aux;
    for(int i=0; i<s.tamSecuencia(); i++){
      aux=s.mostrarMovimiento(i);
      if(aux[0]=='U'){
        if(aux[1]=='2')  U2();
        else if(aux.size()==1) U();
        else  Up();

      }
      if(aux[0]=='F'){
        if(aux[1]=='2')  F2();
        else if(aux.size()==1) F();
        else  Fp();

      }
      if(aux[0]=='R'){
        if(aux[1]=='2')  R2();
        else if(aux.size()==1) R();
        else  Rp();

      }
      if(aux[0]=='B'){
        if(aux[1]=='2')  B2();
        else if(aux.size()==1) B();
        else  Bp();

      }
      if(aux[0]=='L'){
        if(aux[1]=='2')  L2();
        else if(aux.size()==1) L();
        else  Lp();

      }
      if(aux[0]=='D'){
        if(aux[1]=='2')  D2();
        else if(aux.size()==1) D();
        else  Dp();
      }
    }
  }
  void Cubo::mezclaSecuencia(string s){
    if(s[0]=='U'){
      if(s.size()==2){
        if(s[1]=='2') U2();
        else Up();
      }
      else{
        U();
      }
    }
    if(s[0]=='F'){
      if(s.size()==2){
        if(s[1]=='2') F2();
        else Fp();
      }
      else{
        F();
      }
    }
    if(s[0]=='R'){
      if(s.size()==2){
        if(s[1]=='2') R2();
        else Rp();
      }
      else{
        R();
      }
    }
    if(s[0]=='B'){
      if(s.size()==2){
        if(s[1]=='2') B2();
        else Bp();
      }
      else{
        B();
      }
    }
    if(s[0]=='L'){
      if(s.size()==2){
        if(s[1]=='2') L2();
        else Lp();
      }
      else{
        L();
      }
    }
    if(s[0]=='D'){
      if(s.size()==2){
        if(s[1]=='2') D2();
        else Dp();
      }
      else{
        D();
      }
    }

  }
