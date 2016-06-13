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
  printf("s: %lf, c:%lf, t:%lf\n",seno,cosseno,t);
  identity->data[j][j]=identity->data[i][i]=cosseno;
  identity->data[i][j]=identity->data[j][i]=seno;
  */
  gamma = atan(teta);
  gamma/=2;
  identity->data[j][j]=identity->data[i][i]=cos(gamma);
  identity->data[i][j]=identity->data[j][i]=sin(gamma);
  identity->data[i][j]*=(-1);
  //showMatriz(identity);
}
matriz * Jacob::buildMatrixJ(int i, int j){
  teta =(2*m->data[i][j])/(m->data[j][j]-m->data[i][i]);
  //printf("teta: %lf,",teta);
  identityMatriz(identity);
  //identityMatriz(jacob);
  setTetaValues(i,j,teta);
  //showMatriz(transposta(identity));
  //igualaMatrizes(jacob,times(jacob,identity));
  /*
  showMatriz(identity);
  showMatriz(transposta(identity));
  showMatriz(times(m,identity));
  */
  showMatriz(times(transposta(identity),times(m,identity)));
  //igualaMatrizes(m,(times(transposta(jacob),times(jacob,m))));
  return identity;
}
matriz * Jacob::runJacob(){

  for(k=0,l=1;l<m->rows;k++,l++){
      buildMatrixJ(k,l);
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
  (buildMatrixJ(0,1));
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
test:
3
2 1 1
1 2 1
1 1 2

5
5 1 2 2 4
1 1 2 1 0
2 2 0 2 1
2 1 2 1 2
4 0 1 2 4

*/
