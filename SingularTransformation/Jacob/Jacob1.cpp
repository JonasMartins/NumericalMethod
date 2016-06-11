#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Jacob.h"

Jacob::Jacob(matriz *m, FILE *file){
  setMatriz(m);
  arq=file;
  fscanf(arq,"%hu",&m->rows);//pegando primeira linha
  m->columns=m->rows;
  m->data = aloca(m->rows,m->columns);//alocando a matriz
  getMatrixFromFile();

}
void Jacob::setMatriz(matriz *mm){
  m = mm;
}
matriz * Jacob::getMatriz(){
  return m;
}

double ** Jacob::aloca( int lin, int col ){
    if( lin ==0 || col ==0 ){
      printf( "Impossivel alocar espaco\n" );
      exit( 3 );
    }
    ret =(double **)malloc( sizeof(double*) * lin );
    if( ret == NULL  ){
      printf( "2Impossivel alocar espaco" );
      exit( 3 );
    }
    ret[0] =(double *)malloc( sizeof(double) * ( lin * col ) );
    if( ret[0] == NULL  ){
      printf( "1Impossivel alocar espaco" );
      exit( 3 );
    }
    for( k=1; k<lin; k++ )
      ret[k] = ret[k-1] + col;
   return ret;
}

matriz * Jacob::timesTwoVectors(matriz *m,matriz *n){
  //Critério
  if(m->columns!=n->rows){
    printf( "Impossivel multiplicar! Parâmetros incorretos.\n" );
    exit(0);
  }
  unsigned short q;// outro int
  double buffer=0;
  matriz *product;
  product = (matriz*)malloc(sizeof(matriz));
  product->rows=m->rows;
  product->columns=n->columns;
  product->data=aloca(product->rows,product->columns);
  for(i=0;i<m->rows;i++){
    for(j=0;j<n->columns;j++){
      buffer=m->data[i][0]*n->data[0][j];
      product->data[i][j]=buffer;
    }
  }
  return product;
}

matriz * Jacob::times(matriz *m,matriz *n){
  //Critério
  if(m->columns!=n->rows){
    printf( "Impossivel multiplicar! Parâmetros incorretos.\n" );
    exit(0);
  }
  unsigned short q;// outro int
  double buffer=0;
  matriz *product;
  product = (matriz*)malloc(sizeof(matriz));
  //linhas de m e colunas de n
  product->rows=m->rows;
  product->columns=n->columns;
  product->data=aloca(product->rows,product->columns);
  for(q=0;q<m->rows;q++){
    for(i=0;i<m->columns;i++){
      for(j=0;j<n->rows;j++){
        buffer+=(m->data[q][j]*n->data[j][i]);
        product->data[q][i]=buffer;
      }
      buffer=0;
    }
  }
  return product;
}
matriz * Jacob::timesEscalar(double e,matriz *m){
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      m->data[j][i]*=e;
  return m;
}
// ++++++++++++++++++++++++++++++++++
void Jacob::setTetaValues(int i, int j, double teta){
  identity->data[j][j]=identity->data[i][i]=cos(teta*RAD);
  identity->data[i][j]=identity->data[j][i]=sin(teta*RAD);
  identity->data[j][i]*=(-1);

}
matriz * Jacob::buildMatrixJ(int i, int j){
  auxTeta = 2*backup->data[i][j]/backup->data[j][j]-backup->data[i][i];
  teta = atan(2*auxTeta);
  identityMatriz(identity);
  identityMatriz(jacob);
  setTetaValues(i,j,teta);
  igualaMatrizes(jacob,times(jacob,identity));
  igualaMatrizes(m,(times(transposta(jacob),times(jacob,m))));
  return identity;
}
matriz * Jacob::runJacob(){

  for(k=0;k<m->rows-2;k++){
    for(l=k+1;l<m->rows-2;l++){
      buildMatrixJ(k,l);
    }
  }
  return m;
}

// ++++++++++++++++++++++++++++++++++
void Jacob::run(){

  //rad = PI/180; //:)

  backupM(); //keep m
  printf("\n\n");
  printf("%s\n\n","MTRIZ A DADA:" );
  showMatriz(backup);
  generateIdentity(); // aloca matriz identidade, also jacob.
  identityMatriz(jacob);
  printf("============ INICIO ===========\n");
        //showMatriz(buildMatrixJ(1,2));

          buildMatrixJ(0,1);
          buildMatrixJ(0,2);
          buildMatrixJ(0,3);
          showMatriz(m);
      //  buildMatrixJ(0,3);
        //  showMatriz(runJacob());
        //showMatriz(jacob);
        //showMatriz(transposta(jacob));
  printf("============  FIM  ===========\n");
}
