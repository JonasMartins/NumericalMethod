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
  /* old version
  gamma = 1/teta; //1/tg(2 teta);
  t = (gamma/fabs(gamma))/fabs(gamma)+sqrt(1+pow(gamma,2));
  cosseno = 1/sqrt((1+pow(t,2)));
  seno = cosseno*t;
  identity->data[j][j]=identity->data[i][i]=cosseno;
  identity->data[i][j]=identity->data[j][i]=seno;
  */
  teta/=2;
  identity->data[j][j]=identity->data[i][i]=cos(teta);
  identity->data[i][j]=identity->data[j][i]=sin(teta);
  identity->data[i][j]*=(-1);

}
matriz * Jacob::buildMatrixJ(int i, int j){
  if(m->data[i][i]==m->data[j][j]){
    teta = 0.7853981625; //PI/4
  }else{
    // before: teta =(2*m->data[i][j])/(m->data[j][j]-m->data[i][i]);
    teta =(2*finMaxOffDiagonal(m))/(m->data[j][j]-m->data[i][i]);
    teta = atan(teta);
  }
  //printf("teta: %lf,",teta);
  identityMatriz(identity);
  //identityMatriz(jacob);
  setTetaValues(i,j,teta);
  igualaMatrizes(jacob,times(jacob,identity));
  //showMatriz(jacob);
  //sacada perfeita...
  if(j%2==0)
    igualaMatrizes(identity,times(jacob,times(m,transposta(jacob))));
  else
    igualaMatrizes(identity,times(transposta(jacob),times(m,jacob)));
  igualaMatrizes(m,identity);
  identityMatriz(jacob);
  return m;
}
matriz * Jacob::runJacob(){

  for(k=0,l=1;l<m->rows;k++,l++){
      buildMatrixJ(k,l);
  }
  return m;
}
double Jacob::finMaxOffDiagonal(matriz *m){
  double max = m->data[0][1];
  for(i=0;i<m->rows-1;i++){
    for(j=i+1;j<m->rows;j++){
        if(fabs(m->data[i][j])>fabs(max)){
          max=m->data[i][j];
        }
    }
  }
  return fabs(max);
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
  showMatriz(buildMatrixJ(0,1));
  showMatriz(buildMatrixJ(0,2));
  showMatriz(buildMatrixJ(1,2));
  showMatriz(buildMatrixJ(0,1));
  showMatriz(buildMatrixJ(0,2));
  showMatriz(buildMatrixJ(1,2));

  //showMatriz(buildMatrixJ(0,2));
  //showMatriz(buildMatrixJ(0,3));
  //printf("Max: %lf\n",finMaxOffDiagonal(m));


  //showMatriz(buildMatrixJ(0,3));
  //showMatriz(buildMatrixJ(0,4));
    /*
    for(k=0;k<m->rows-1;k++){
      //for(l=k+1;l<m->rows;l++){
          //k=l+1;
          buildMatrixJ(k,l);
        //}
      }
      */
  //showMatriz(m);
  printf("============  FIM  ===========\n");
}
/**
obs:. fazer uma versão para matrizes impres e pares

test:
3
2 1 1
1 2 1
1 1 2

3
2 -4 1
-4 5 1
1 -1 2


4
4 2 2 1
2 -3 1 1
2 1 3 1
1 1 1 2

5
5 1 2 2 4
1 1 2 1 0
2 2 0 2 1
2 1 2 1 2
4 0 1 2 4

*/
