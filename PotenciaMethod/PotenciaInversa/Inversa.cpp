#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Inversa.h"

Inversa::Inversa(matriz *m){
  setMatriz(m);
  m->data = aloca(m->rows,m->columns);//alocando a matriz
}
void Inversa::setMatriz(matriz *mm){
  m = mm;
}
matriz * Inversa::getMatriz(){
  return m;
}

// recebe um vetor qualquer e retorna o valor normalizado
matriz * Inversa::normaEuclidiana(matriz *m){
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

matriz * Inversa::copyMatriz(matriz *m,matriz *mm){
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      mm->data[j][i]=m->data[j][i];
  return m;
}

void Inversa::savePartialResult(matriz *m){

  buffer = (matriz*)malloc(sizeof(matriz));
  buffer->columns=buffer->rows=m->rows;
  buffer->data=aloca(buffer->rows,buffer->columns);
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      buffer->data[j][i]=m->data[j][i];
}

void Inversa::igualaMatrizes(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        m->data[i][j]=n->data[i][j];
}

void Inversa::identityMatriz(matriz *n){// Matriz identidade
  for(i=0;i<n->rows;i++)
    for(j=0;j<n->columns;j++)
      n->data[i][j]=0;

  for(i=0;i<n->rows;i++)
      n->data[i][i]=1;
}

// flip na matriz para depois dar um gauss novamente..
matriz * Inversa::flipMatrix(matriz *m){

  flip = (matriz*)malloc(sizeof(matriz));
  flip->columns=flip->rows=m->rows;
  flip->data=aloca(flip->rows,flip->columns);
  for(k=0,i=(m->rows-1);k<m->rows;i--,k++)
    for(l=0,j=(m->columns-1);l<m->columns;j--,l++)
      flip->data[k][l] = m->data[i][j];
  return flip;
}

matriz * Inversa::gaussInversa(matriz *m){
  double factor, factorInv,aux,auxInve;
  //matriz *mInve;
  mInve = (matriz*)malloc(sizeof(matriz));
  mInve->columns=mInve->rows=m->rows;
  mInve->data=aloca(mInve->rows,mInve->columns);
  identityMatriz(mInve);
  int z=0;
  i=j=0;
  do{
    for(k=(m->rows-1);k>z;k--){
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
    z++;
    j=i=0;
  }while(z<(m->rows-1));

  /*
  savePartialResult(mInve); //salvei
  cout<<"Before: \n";
  showMatriz(mInve);
  mInve = flipMatrix(mInve); // inverti
  cout<<"After: \n";
  showMatriz(mInve);
  */
  return m;
}
void Inversa::normalizePivots(){
    double aux;
    for(i=0;i<m->rows;i++){
      aux = 1/m->data[i][i];
      m->data[i][i]*= aux;
      mInve->data[i][i]*= aux;
    }
}

void Inversa::run(){
  //showMatriz(m);
  gaussInversa(m);
  //m = flipMatrix(m);
  //mInve = flipMatrix(mInve);

  showMatriz(m);
  showMatriz(mInve);

  /*
  gaussInversa(m);
  m = flipMatrix(m);
  mInve = flipMatrix(mInve);

  normalizePivots();//both;

  showMatriz(m);
  showMatriz(mInve);
  */
  //gaussInversa(m);
  //m = flipMatrix(m);
//  showMatriz(m);
//  showMatriz(mInve);
  //showMatriz(buffer);
  //showMatriz(flipMatrix(buffer));

}


