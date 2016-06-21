#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Householder.h"

double ** Householder::aloca( int lin, int col ){

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

void Householder::identityMatriz(matriz *n){// Matriz identidade
  for(i=0;i<n->rows;i++)
    for(j=0;j<n->columns;j++)
      n->data[i][j]=0;

  for(i=0;i<n->rows;i++)
      n->data[i][i]=1;
}
void Householder::showMatriz(matriz *m){

  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);
      }
      printf("\n");
    }
  printf("\n");
}
matriz * Householder::timesTwoVectors(matriz *m,matriz *n){
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

matriz * Householder::times(matriz *m,matriz *n){
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
matriz * Householder::timesEscalar(double e,matriz *m){
  for(j=0;j<m->rows;j++)
    for(i=0;i<m->columns;i++)
      m->data[j][i]*=e;
  return m;
}

// dada uma matriz retorna sua transposta
matriz * Householder::transposta(matriz *m){
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
void Householder::multiplyByMinusOne(matriz *m){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j]*=(-1);
}

void Householder::stopProgram(){
  printf("k = 20, PROVAVELMENTE NÃO CONVERGE, TENTE OUTRO VETOR INICIAL V, OU UMA TOLERANCIA MENOR.\n");
  exit(0);
}
// apenas para matrizes vetores!!! ou seja este sempre será o vetor q
matriz * Householder::subtraction(matriz *m,matriz *n){
  difference = (matriz*)malloc(sizeof(matriz));
  difference->rows=m->rows;
  difference->columns=1;
  difference->data=aloca(difference->rows,difference->columns);
  for(i=0;i<m->rows;i++)
      difference->data[i][0]=m->data[i][0]-n->data[i][0];
  return difference;
}
matriz * Householder::sumMatrix(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j]+=n->data[i][j];
  return m;
}

void Householder::getMatrixFromFile(){

  for(i=0;i<m->rows;i++){
		for(j=0;j<m->columns;j++){
		  //fread(&m->data[i][j], sizeof(char), 1, arq); # binary way
      fscanf(arq,"%lf",&m->data[i][j]);
		}
	}
}
/*
void Householder::saveMatrixFile(){
  for(i=0;i<m->rows;i++){
		for(j=0;j<m->columns;j++){
      fprintf(arq_saida,"%lf",m->data[i][j]);
      fprintf(arq_saida,"%s"," ");
    }
  }
}*/
