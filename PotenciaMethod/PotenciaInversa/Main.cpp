#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Inversa.h"


int main(int argc,char **argv){

  /*
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

