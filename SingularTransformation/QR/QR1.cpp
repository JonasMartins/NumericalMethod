#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./QR.h"

// apenas para matrizes vetores!!! ou seja este sempre será o vetor q
matriz * Jacob::subtraction(matriz *m,matriz *n){
  difference = (matriz*)malloc(sizeof(matriz));
  difference->rows=m->rows;
  difference->columns=1;
  difference->data=aloca(difference->rows,difference->columns);
  for(i=0;i<m->rows;i++)
      difference->data[i][0]=m->data[i][0]-n->data[i][0];
  return difference;
}
matriz * Jacob::sumMatrix(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j]+=n->data[i][j];
  return m;
}

void Jacob::getMatrixFromFile(){

  for(i=0;i<m->rows;i++){
		for(j=0;j<m->columns;j++){
		  //fread(&m->data[i][j], sizeof(char), 1, arq); # binary way
      fscanf(arq,"%lf",&m->data[i][j]);
		}
	}
}


// dada uma matriz retorna sua transposta
matriz * Jacob::transposta(matriz *m){
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
void Jacob::multiplyByMinusOne(matriz *m){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j]*=(-1);
}

void Jacob::showMatriz(matriz *m){

  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);
      }
      printf("\n");
    }
  printf("\n");
}
void Jacob::backupM(){
  //beckup;
  backup = (matriz*)malloc(sizeof(matriz));
  backup->columns=backup->rows=m->rows;
  backup->data=aloca(backup->rows,backup->columns);
  igualaMatrizes(backup,m);

}
void Jacob::igualaMatrizes(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        m->data[i][j]=n->data[i][j];
}
void Jacob::generateIdentity(){
  identity = (matriz*)malloc(sizeof(matriz));
  identity->columns=identity->rows=m->rows;
  identity->data=aloca(identity->rows,identity->columns);
  //identityMatriz(identity);

  jacob = (matriz*)malloc(sizeof(matriz));
  jacob->columns=jacob->rows=m->rows;
  jacob->data=aloca(jacob->rows,jacob->columns);

  jacob_final = (matriz*)malloc(sizeof(matriz));
  jacob_final->columns=jacob_final->rows=m->rows;
  jacob_final->data=aloca(jacob_final->rows,jacob_final->columns);

}
void Jacob::identityMatriz(matriz *n){
  for(i=0;i<n->rows;i++)
    for(j=0;j<n->columns;j++)
      n->data[i][j]=0;

  for(i=0;i<n->rows;i++)
      n->data[i][i]=1;
}
