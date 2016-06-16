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

#define PI 3.141592653
#define RAD PI/180

class Jacob{

public:

  Jacob(matriz *m,FILE *);

  matriz * times(matriz *,matriz *);
  matriz * transposta(matriz *);
  matriz * timesEscalar(double,matriz *);
  matriz * timesTwoVectors(matriz *, matriz *);
  matriz * subtraction(matriz *, matriz *);
  matriz * sumMatrix(matriz *,matriz *);//subtrai m de n e retorna m
  double ** aloca(int,int);
  void setMatriz(matriz *);
  void igualaMatrizes(matriz *,matriz *);
  void multiplyByMinusOne(matriz *);
  void showMatriz(matriz *);
  void getMatrixFromFile();
  void backupM();
  matriz * getMatriz();
  void generateIdentity();
  double finMaxOffDiagonal(matriz *);
  void identityMatriz(matriz *);
  void setTetaValues(int, int,double);
  matriz * runJacob();
  matriz * buildMatrixJ(int,int);
  void run();

private:
  unsigned short i;
  unsigned short j;
  unsigned short k;
  unsigned short l;
  double teta;
  double auxTeta;
  //static double rad = PI/180;


  FILE *arq;
  double **ret;
  matriz *m;
  matriz *backup;
  matriz *identity;
  matriz *difference;
  matriz *jacob;

  double gamma;
  double t;
  double cosseno;
  double seno;

};
