#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Holseholder.h"

double ** Holseholder::aloca( int lin, int col ){

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

void Holseholder::identityMatriz(matriz *n){// Matriz identidade
  for(i=0;i<n->rows;i++)
    for(j=0;j<n->columns;j++)
      n->data[i][j]=0;

  for(i=0;i<n->rows;i++)
      n->data[i][i]=1;
}
void Holseholder::showMatriz(matriz *m){

  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);
      }
      printf("\n");
    }
  printf("\n");
}
matriz * Holseholder::timesTwoVectors(matriz *m,matriz *n){
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

matriz * Holseholder::times(matriz *m,matriz *n){
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
matriz * Holseholder::timesEscalar(double e,matriz *m){
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      m->data[j][i]*=e;
  return m;
}

// dada uma matriz retorna sua transposta
matriz * Holseholder::transposta(matriz *m){
  matriz *transposta;
  transposta = (matriz*)malloc(sizeof(matriz));
  transposta->rows=m->columns;
  transposta->columns=m->rows;
  transposta->data=aloca(transposta->rows,transposta->columns);

  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        transposta->data[j][i]=m->data[i][j];
  return transposta;
}
void Holseholder::stopProgram(){
  printf("k = 20, PROVAVELMENTE NÃO CONVERGE, TENTE OUTRO VETOR INICIAL V, OU UMA TOLERANCIA MENOR.\n");
  exit(0);
}
matriz * Holseholder::subtraction(matriz *m,matriz *n){
  difference = (matriz*)malloc(sizeof(matriz));
  difference->rows=difference->columns=m->rows;
  difference->data=aloca(difference->rows,difference->columns);
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      difference->data[i][j]=m->data[i][j]-n->data[i][j];
  return difference;
}

void Holseholder::setValues_Default(){

  double mat_u[4][4] = {
    {4,2,2,1},{2,-3,1,1},{2,1,3,1},{1,1,1,2}
    /*
    {44,23,23,11,20},
    {23,-38,16,18,-12},
    {23,16,13,45,-10},
    {11,18,45,22,-14},
    {20,-12,-10,-14,45}
    */
  };
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j] = mat_u[i][j];
}
/*
void Inversa::potenciaRegular(matriz *m, matriz *v, double tolerance){
  double lambda=0;
  double lambdaK;
  double aux;
  int h=0;
  matriz *vk;
  vk=(matriz*)malloc(sizeof(matriz));
  vk->rows=v->rows;
  vk->columns=v->columns;
  vk->data=aloca(vk->rows,vk->columns);

  do{
    printf("loop: k = %d.\n",h+1);
    igualaMatrizes(vk,normaEuclidiana(v)); // normalizando v, e vk <- v normalizado "psi"k
    igualaMatrizes(v,times(m,vk));  // v+1
    printf("autovetor:\n");
    showMatriz(v);
    printf("autovetor normalizado:\n");
    showMatriz(normaEuclidiana(v));
    lambdaK = times(transposta(vk),v)->data[0][0]; // retorna uma matriz 1x1, ou um escalar
    printf("autovalor:\n");
    printf("%f\n",lambdaK);
    aux=fabs(lambdaK-lambda)/fabs(lambdaK);
    printf("tolerancia: %f\n",aux);
    lambda = lambdaK;
    h++;
    printf("==========================\n");
    if(h==20)
      stopProgram();
  }while(aux>tolerance);
}


// alocando a amatriz dinamicamente
// multiplicando duas matrizes
*/
