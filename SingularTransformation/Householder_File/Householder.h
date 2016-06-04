#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

typedef struct {
  unsigned short rows;
  unsigned short columns;
  double **data;
}matriz;

class Householder{

public:

  Householder(matriz *m,FILE *);
  matriz * normaEuclidiana(matriz *);
  matriz * times(matriz *,matriz *);
  matriz * transposta(matriz *);
  matriz * timesEscalar(double,matriz *);
  matriz * timesTwoVectors(matriz *, matriz *);
  matriz * subtraction(matriz *, matriz *);
  matriz * sumMatrix(matriz *,matriz *);//subtrai m de n e retorna m
  void multiplyByMinusOne(matriz *);
  void identityMatriz(matriz *);
  double ** aloca(int,int);
  void showMatriz(matriz *);
  void igualaMatrizes(matriz *,matriz *);
  void getMatrixFromFile();
  matriz * getMatriz();
  void stopProgram();
  void backupM();
  void setMatriz(matriz *);
  void triDiagonalize(int, int);
  void householderQH(matriz *,matriz *,int,int);
  void run();
  void generateIdentity();

private:
  unsigned short i;
  unsigned short j;
  unsigned short k;
  unsigned short l;

  FILE *arq;
  double v_comp;
  double **ret;
  matriz *m;
  matriz *cc;
  matriz *qq;
  matriz *backup;
  matriz *qh;
  matriz *h;
  matriz *v;
  matriz *n;
  matriz *vv;
  matriz *difference;

};
