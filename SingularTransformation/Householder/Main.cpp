#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Holseholder.h"


int main(int argc,char **argv){

  /*
    c++ Holseholder1.cpp -o Holseholder1 Holseholder2.cpp -o Holseholder2 Main.cpp -o Main
  */


  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  m->rows = 5;
  m->columns = 5;
  Holseholder matriz(m);

  matriz.setValues_Default();
  matriz.run();


  return EXIT_SUCCESS;
}
