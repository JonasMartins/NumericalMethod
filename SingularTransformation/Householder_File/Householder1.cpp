#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Householder.h"

Householder::Householder(matriz *m, FILE *file/*, FILE *saida*/){
  setMatriz(m);
  arq=file;
  //arq_saida=saida;
  fscanf(arq,"%hu",&m->rows);//pegando primeira linha
  m->columns=m->rows;
  m->data = aloca(m->rows,m->columns);//alocando a matriz
  getMatrixFromFile();

}
void Householder::setMatriz(matriz *mm){
  m = mm;
}
matriz * Householder::getMatriz(){
  return m;
}
// recebe um vetor qualquer e retorna o valor normalizado
matriz * Householder::normaEuclidiana(matriz *m){
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

void Householder::run(){
  backupM(); //keep m
  printf("\n\n");
  printf("%s\n\n","MTRIZ A DADA:" );
  showMatriz(m);
  printf("============ INICIO ===========\n");
  generateIdentity();// initialize all matrices
  unsigned short p,q;
  for(q=0,p=1;p<m->rows-1;p++,q++)
    triDiagonalize(p,q); //magic....
  printf("============  FIM  ===========\n");
}
void Householder::igualaMatrizes(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        m->data[i][j]=n->data[i][j];
}

void Householder::backupM(){
  //beckup;
  backup = (matriz*)malloc(sizeof(matriz));
  backup->columns=backup->rows=m->rows;
  backup->data=aloca(backup->rows,backup->columns);
  igualaMatrizes(backup,m);

}

void Householder::triDiagonalize(int l, int k){//coordinates
  for(i=0;i<v->rows;i++){
    v->data[i][0]=n->data[i][0]=0;}
  for(i=l;i<v->rows;i++){
    v->data[i][0]=n->data[i][0]=m->data[i][k];}
   householderQH(v,n,l,k);// getting qh
}
void Householder::householderQH(matriz *v,matriz *n,int l,int k){
  double r; //n é o w
  v_comp=0;
  for(i=0;i<v->rows;i++)
    v_comp+=pow(v->data[i][0],2);
  v_comp = sqrt(v_comp);// comprimento de v
  if(m->data[l][k]<0)
    v_comp*=(-1);
  r = 2*v_comp*(m->data[l][k]+v_comp);//ok?
  r = sqrt(r);
  n->data[0][0]=0;
  n->data[l][0]+=v_comp;
  for(i=0;i<n->rows;i++)
    n->data[i][0]/=r;
  igualaMatrizes(vv,times(m,n));
  cc=times(transposta(n),vv);
  subtraction(vv,timesEscalar(cc->data[0][0],n));
  n = timesEscalar((1/cc->data[0][0]),n); //get back n
  igualaMatrizes(qq,(timesEscalar(2,timesTwoVectors(n,transposta(difference)))));
  igualaMatrizes(h,(timesEscalar(2,timesTwoVectors((difference),transposta(n)))));
  // garnatindo linhas e colunas correspondentes em 0;
  for(i=0;i<qq->rows;i++){
    qq->data[0][i]=0;
    h->data[i][0]=0;
  }
  multiplyByMinusOne(qq);
  multiplyByMinusOne(h);
  igualaMatrizes(m,(sumMatrix(m,sumMatrix(h,qq))));
  showMatriz(m); // m vai sendo moldada no estilo tridiagonal.
}
void Householder::generateIdentity(){// keep I in memory

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

  vv = (matriz*)malloc(sizeof(matriz)); //vv
  vv->rows=m->rows;
  vv->columns=1;
  vv->data=aloca(vv->rows,vv->columns);

  qq = (matriz*)malloc(sizeof(matriz)); //qq
  qq->rows=qq->columns=m->rows;
  qq->data=aloca(qq->rows,qq->columns);

  cc = (matriz*)malloc(sizeof(matriz)); //cc
  cc->rows=cc->columns=1;
  cc->data=aloca(cc->rows,cc->columns);

}
