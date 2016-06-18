#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Jacob.h"

Jacob::Jacob(matriz *m, FILE *file, double tolerance){
  setMatriz(m);
  tolerancia=tolerance;// limite
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
  /*
  //Critério
  if(m->columns!=n->rows){
    printf( "Impossivel multiplicar! Parâmetros incorretos.\n" );
    exit(0);
  }*/
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
  if(j%2==0)
    igualaMatrizes(identity,times(jacob,times(m,transposta(jacob))));
  else
    igualaMatrizes(identity,times(transposta(jacob),times(m,jacob)));
  igualaMatrizes(m,identity);
  igualaMatrizes(jacob_final,times(jacob_final,jacob));
  identityMatriz(jacob);
  return m;
}
//Retorna o erro fora da diagonal... para comparar com a tolerancia
double Jacob::getError(){
  unsigned short r,s;
  errorBuffer=0;
  for(r=1;r<m->rows;r++){
    for(s=0;s<r;s++){
      errorBuffer+=fabs(m->data[r][s]);
    }
  }
  return errorBuffer*2;
}
matriz * Jacob::runJacob(){
  unsigned short p,q;
  for(p=0;p<m->rows-1;p++){
    for(q=p+1;q<m->rows;q++){
      buildMatrixJ(p,q);
    }
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
  identityMatriz(jacob_final);
  printf("============ INICIO ===========\n");
  unsigned short iterator=0;
  do{
    runJacob();
    iterator++;
  }while(getError()>tolerancia);

  printf("Iterações: %d\n", iterator);
  printf("Acumulo de erro fora da diagonal: %lf\n",getError());
  printf("%s\n","Matriz diagonal:");
  showMatriz(m);
  printf("%s\n","Matriz de Jacob:");
  showMatriz(jacob_final);

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

4
8 -1 3 -1
-1 6 2 0
3 2 9 1
-1 0 1 7


5
5 1 2 2 4
1 1 2 1 0
2 2 0 2 1
2 1 2 1 2
4 0 1 2 4

*/
