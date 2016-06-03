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
  matriz * triDiagonalize();
  void holseholderQH(matriz *,matriz *,int);
  void run();
  void generateIdentity();
  /*
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
*/

private:
  unsigned short i;
  unsigned short j;
  unsigned short k;
  unsigned short l;

  double **ret;
  matriz *m;
  matriz *backup;
  matriz *buffer;
  matriz *qh;
  matriz *h;
  matriz *v;
  matriz *n;
  matriz *identidade;
  matriz *difference;

};
