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

// the name is Householder

class Holseholder{

public:

  Holseholder(matriz *m);
  matriz * normaEuclidiana(matriz *);
  matriz * times(matriz *,matriz *);
  matriz * transposta(matriz *);
  matriz * timesEscalar(double,matriz *);
  matriz * timesTwoVectors(matriz *, matriz *);
  matriz * subtraction(matriz *, matriz *);
  matriz * sumMatrix(matriz *,matriz *);//subtrai m de n e retorna m
  void multiplyByMinusOne(matriz *);
  void savePartialResult(matriz *);
  void identityMatriz(matriz *);
  double ** aloca(int,int);
  void showMatriz(matriz *);
  void igualaMatrizes(matriz *,matriz *);
  void setValues_Default();
  matriz * getMatriz();
  void stopProgram();
  void backupM();
  void setMatriz(matriz *);
  void triDiagonalize(int, int);
  void holseholderQH(matriz *,matriz *,int,int);
  void run();
  void generateIdentity();

private:
  unsigned short i;
  unsigned short j;
  unsigned short k;
  unsigned short l;

  double v_comp;
  double **ret;
  matriz *m;
  matriz *cc;
  matriz *qq;
  matriz *backup;
  matriz *buffer;
  matriz *qh;
  matriz *h;
  matriz *v;
  matriz *n;
  matriz *vv;
  matriz *identidade;
  matriz *difference;

};
