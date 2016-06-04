#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Householder.h"


int main(int argc,char **argv){

  /*
    LÓGICA DO ALGORÍTIMO USADO: http://mathfaculty.fullerton.edu/mathews/n2003/HouseholderMod.html

    c++ Householder1.cpp -o Householder1 Householder2.cpp -o Householder2 Main.cpp -o Main
    ./Main Matrix.txt

  */

  if(argc<2){
    printf("NÚMERO DE PARÂMETROS INVÁLIDOS, POR FAVOR ENTRE COM O NOME DO ARQUIVO COM A MATRIX\n");
    printf("%s\n", "EX: ./Main Matrix.txt");
    printf("%s\n%s\n%s\n", "PARA RODAR O PROGRAMA CORRETAMENTE:",
    "c++ Householder1.cpp -o Householder1 Householder2.cpp -o Householder2 Main.cpp -o Main",
    "./Main Matrix.txt");
    exit(0);
  }
  FILE *arq;
  arq = fopen(argv[1],"r");

  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  Householder matriz(m,arq);
  matriz.run();
  fclose(arq);

  return EXIT_SUCCESS;
}
