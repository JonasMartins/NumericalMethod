#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Holseholder.h"

Holseholder::Holseholder(matriz *m){
  setMatriz(m);
  m->data = aloca(m->rows,m->columns);//alocando a matriz
}

void Holseholder::setMatriz(matriz *mm){
  m = mm;
}
matriz * Holseholder::getMatriz(){
  return m;
}
// recebe um vetor qualquer e retorna o valor normalizado
matriz * Holseholder::normaEuclidiana(matriz *m){
  double norma=0;
  for(i=0;i<m->rows;i++){
    norma+=pow(m->data[0][i],2);
  }
  norma = sqrt(norma);

  for(i=0;i<m->rows;i++){
    m->data[0][i]/=norma;
  }
  return m;
}

void Holseholder::savePartialResult(matriz *m){

  buffer = (matriz*)malloc(sizeof(matriz));
  buffer->columns=buffer->rows=m->rows;
  buffer->data=aloca(buffer->rows,buffer->columns);
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      buffer->data[j][i]=m->data[j][i];
}
void Holseholder::run(){

  backupM(); //keep m
  printf("\n\n");
  printf("%s\n\n","MTRIZ A DADA:" );
  showMatriz(backup);
  printf("============ INICIO ===========\n");
  triDiagonalize();
  //triDiagonalize();
  printf("============  FIM  ===========\n");

}
void Holseholder::igualaMatrizes(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        m->data[i][j]=n->data[i][j];
}

void Holseholder::backupM(){
  //beckup;
  backup = (matriz*)malloc(sizeof(matriz));
  backup->columns=backup->rows=m->rows;
  backup->data=aloca(backup->rows,backup->columns);
  igualaMatrizes(backup,m);

}
void Holseholder::generateIdentity(){// keep I in memory
  identidade = (matriz*)malloc(sizeof(matriz));
  identidade->rows=identidade->columns=m->rows;
  identidade->data=aloca(identidade->rows,identidade->columns);
  identityMatriz(identidade);
  qh = (matriz*)malloc(sizeof(matriz));//qh
  qh->rows=qh->columns=m->rows;
  qh->data=aloca(qh->rows,qh->columns);
  h = (matriz*)malloc(sizeof(matriz));//h
  h->rows=m->rows;
  h->columns=m->columns;
  h->data=aloca(h->rows,h->columns);
  v = (matriz*)malloc(sizeof(matriz)); //v
  v->rows=m->rows;
  v->columns=1;
  v->data=aloca(v->rows,v->columns);
  n = (matriz*)malloc(sizeof(matriz));//n
  n->rows=m->rows;
  n->columns=1;
  n->data=aloca(n->rows,n->columns);
}

matriz * Holseholder::triDiagonalize(){

  savePartialResult(getMatriz());// salvando A em buffer.
  generateIdentity();// initialize identity, and anothers
  identityMatriz(h);// h inicia com a identidade
  l=k=1;
  for(i=0;i<v->rows;i++){
    v->data[i][0]=n->data[i][0]=0;}
  for(i=l+1;i<v->rows;i++){
    v->data[i][0]=n->data[i][0]=m->data[i][0];}
  do{
     holseholderQH(v,n,l);// getting qh
     //igualaMatrizes(h,times(h,qh));
     showMatriz(qh);
     //igualaMatrizes(times(m,qh),m);
     //igualaMatrizes(m,times(m,qh));
     k++;
  }while(k<2);
}
void Holseholder::holseholderQH(matriz *v,matriz *n,int h){

  double v_comp=0;
  for(i=0;i<v->rows;i++)
    v_comp+=pow(v->data[i][0],2);

  v_comp = sqrt(v_comp);// comprimento de v
  n->data[h+1][0]=v->data[h+1][0]-v_comp;
  n->data[h+1][0]*=(-1);
  n=normaEuclidiana(n);
  //showMatriz(n);
  //showMatriz(transposta(n));
  //showMatriz(timesTwoVectors(n,transposta(n)));
  igualaMatrizes(qh,subtraction(identidade,timesEscalar(2,timesTwoVectors(n,transposta(n)))));
  //showMatriz(qh);
  //return qh;
}


/*

matriz * Holseholder::copyMatriz(matriz *m,matriz *mm){
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      mm->data[j][i]=m->data[j][i];
  return m;
}
44 23 23 11 20
23 -38 16 18 -12
23 16 13 45 -10
11 18 45 22 -14
20 -12 -10 -14 45


1 0 0 0 0
0 -0 -0.7098 -0.35395 -0.6172
0 -0.7098 0.4962 -0.2410 -0.4381
0 -0.35395 -0.2410 0.8884 -0.2095
0 -0.6172 -0.4381 -0.2095 0.6190


void Holseholder::igualaMatrizes(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        m->data[i][j]=n->data[i][j];
}



// flip na matriz para depois dar um gauss novamente..
matriz * Holseholder::flipMatrix(matriz *m){

  flip = (matriz*)malloc(sizeof(matriz));
  flip->columns=flip->rows=m->rows;
  flip->data=aloca(flip->rows,flip->columns);
  for(k=0,i=(m->rows-1);k<m->rows;i--,k++)
    for(l=0,j=(m->columns-1);l<m->columns;j--,l++)
      flip->data[k][l] = m->data[i][j];
  return flip;
}

void Holseholder::backupM(){

  backup = (matriz*)malloc(sizeof(matriz));
  backup->columns=backup->rows=m->rows;
  backup->data=aloca(backup->rows,backup->columns);
  igualaMatrizes(backup,m);

}

void Holseholder::initInve(){
  mInve = (matriz*)malloc(sizeof(matriz));
  mInve->columns=mInve->rows=m->rows;
  mInve->data=aloca(mInve->rows,mInve->columns);
  identityMatriz(mInve);
}


matriz * Holseholder::gaussInversa(matriz *m){
  double factor, factorInv,aux,auxInve;
  int z=0;
  i=jHolseholder0;
  do{
    for(k=(m->rows-1);k>z;k--){
      factor=m->data[k][z]/m->data[z][z];
      for(;j<m->columns;j++){
          aux = factor * m->data[z][j];
          auxInve = factor * mInve->data[z][j];
          aux*=-1;
          m->data[k][j]+=aux;
          nve->data[k::][j]+=auxInve;
      }
      j=i;
    }
    z++;
    j=i=0;
  }while(z<(m->rows-1));

  return gaussBaixo(Holseholder);
}

matriz * Holseholder::gaussBaixo(matriz *m){
  double factor, factorInv,aux,auxInve;
  int z=(m->rows-1);
  i=j=0;
  do{ //(m->rows-1)
    for(k=0;k<z;k++){
      factor=m->data[k][z]/m->data[z][z];
      for(;j<m->columns;j++){
          aux = factor * m->data[z][j];
          auxInve = factor * mInve->data[z][j];
          aux*=-1;
          m->data[k][j]+=aux;
          mInve->data[k][j]+=auxInve;
      }
      j=i;
    }
    z--;
    j=i=0;
  }Holseholderhile(z>=0);

  return m;
}

void Inversa::normalizePivots(){
    double aux;
    for(i=0;i<m->rows;i++){
      aux = 1/m->data[i][i];
      m->data[i][i]*= aux;
      mInve->data[i][i]*= aux; // também normaliza os pivos da inversa.
    }
}

void Inversa::run(){
  //showMatriz(m);

  matriz *v;
  v = (matriz*)malloc(sizeof(matriz));
  v->rows=3;v->columns=1;
  v->data = aloca(3,1);
  v->data[0][0]=1;v->data[1][0]=-2;v->data[2][0]=2;

  backupM(); //keep m
  initInve();



  gaussInversa(m);

  normalizePivots();
  printf("\n\n");
  printf("%s\n\n","MTRIZ A DADA:" );
  showMatriz(backup);
  printf("%s\n\n","SUA INVERSA A¹ APROX:" );
  showMatriz(mInve);
  printf("DEVERIA SER I:\n");
  printf("%s\n\n","APROX: A¹ x A:" );
  savePartialResult(times(mInve,backup));
  showMatriz(buffer);
  printf("%s\n","APLICANDO POTENCIA NESSA MATRIZ APROX INVERSA:\n\n" );
  printf("vetor inicial aleatório:\n");
  showMatriz(v);
  printf("============ INICIO ===========\n");
  potenciaRegular(buffer,v,0.01);
  printf("============  FIM  ===========\n");

}
*/
