#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Inversa.h"


// run: gcc PotenciaRegular.c -o potencia -lm
//      ./potencia


int main(int argc,char **argv){

  /*
  int i,j;
  matriz *m;
  matriz *v;
  //matriz *auxm;
  m = (matriz*)malloc(sizeof(matriz));
  v = (matriz*)malloc(sizeof(matriz));
  //auxm = (matriz*)malloc(sizeof(matriz));

  //Matriz A
  m->rows = 3;
  m->columns = 3;

  //auxm->rows = 3;
  //auxm->columns = 3;
  matriz *mInve;
  mInve = (matriz*)malloc(sizeof(matriz));
  mInve->columns=mInve->rows=m->rows;
  mInve->data=aloca(mInve->rows,mInve->columns);
  identityMatriz(mInve);

  matriz *ii;
  ii = (matriz*)malloc(sizeof(matriz));
  ii->columns=ii->rows=mInve->rows;
  ii->data=aloca(ii->rows,ii->columns);

  //Vetor v
  v->rows = 3;
  v->columns =1;

  m->data = aloca(m->rows,m->columns);
  //auxm->data = aloca(m->rows,m->columns); //keep m
  v->data = aloca(v->rows,v->columns);

  v->data[0][0]=1;v->data[1][0]=-2;v->data[2][0]=2; // exemplo de vetor v qualquer


  //exemplo de valores da matriz A

  unsigned short mat_u[3][3] = {
    {20,7,9},{7,30,8},{9,8,30}
  };
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
      m->data[i][j] = mat_u[i][j];




  printf("Matriz dada:\n");
  showMatriz(m);
  printf("vetor inicial aleatório:\n");
  showMatriz(v);
  printf("============ INICIO ===========\n");

  //aqui auxm tem m trianular superior
  //copyMatriz(gaussInversa(m),auxm); //retorna auxm
  //gaussInversa(m,mInve);//save
  //showMatriz(gaussInversa(flipMatrix(m))); // m vira triang supe

  //showMatriz(gaussInversa(flipMatrix(m)));
  //showMatriz(gaussInversa(m));
  //potenciaRegular(m,v,0.01);
  printf("============  FIM  ===========\n");



  c++ Inversa.cpp -o Inversa Potencia.cpp -o Potencia Main.cpp -o Main


  */
  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  m->rows = 3;
  m->columns = 3;// incialmente 3x3, para o caso base mas pode alterar posteriormente
  Inversa matriz(m); // instanciando...

  matriz.setValues_Default();
  matriz.run();

  //matriz.intro();
  //matriz.run();

  return EXIT_SUCCESS;
}

