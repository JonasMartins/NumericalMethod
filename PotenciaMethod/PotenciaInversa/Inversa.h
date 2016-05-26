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


class Inversa{

public:

  Inversa(matriz *m);


  matriz * times(matriz *,matriz *);//multiplica duas matrizes
  matriz * copyMatriz(matriz *,matriz *);
  matriz * normaEuclidiana(matriz *);
  matriz * flipMatrix(matriz *);
  matriz * transposta(matriz *);
  matriz * gaussInversa(matriz *);
  matriz * gaussBaixo(matriz *);

  double ** aloca(int,int);//Famigerada Aloca...
  void showMatriz(matriz *);
  void igualaMatrizes(matriz *,matriz *);
  void stopProgram();
  void identityMatriz(matriz *);
  void potenciaRegular(matriz *, matriz *, double);
  void setValues_Default();
  void run();


  void savePartialResult(matriz *);
  void normalizePivots();
  void setMatriz(matriz *);
  void initInve();
  void backupM();
  matriz * getMatriz();

private:
  unsigned short i;
  unsigned short j;
  unsigned short k; // add o k e tirei a criação do
  unsigned short l;

  double **ret;
  matriz *m;
  matriz *backup;
  matriz *buffer;
  matriz *mInve;
  matriz *flip;

};