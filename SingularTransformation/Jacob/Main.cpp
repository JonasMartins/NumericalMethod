#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include "./Jacob.h"


int main(int argc,char **argv){

  /*

    c++ Jacob1.cpp -o Jacob1 Jacob2.cpp -o Jacob2 Main.cpp -o Main
    ./Main Matrix.txt

  */
  double tolerance;

  if(argc<2){
    printf("NÚMERO DE PARÂMETROS INVÁLIDOS, POR FAVOR ENTRE COM O NOME DO ARQUIVO COM A MATRIX\n");
    printf("%s\n", "EX: ./Main Matrix.txt");
    printf("%s\n%s\n%s\n", "PARA RODAR O PROGRAMA CORRETAMENTE:",
    "c++ Jacob1.cpp -o Jacob1 Jacob2.cpp -o Jacob2 Main.cpp -o Main",
    "./Main Matrix.txt");
    exit(0);
  }
  FILE *arq;
  arq = fopen(argv[1],"r");

  matriz *m;
  m = (matriz*)malloc(sizeof(matriz));
  printf("\n\n\t%s\n","DIGITE A TOLERÂNCIA PARA DECLARAR A MATRIZ COMO DIAGONAL: ");
  cin >> tolerance;

  Jacob matriz(m,arq,tolerance);
  matriz.run();
  fclose(arq);

  return EXIT_SUCCESS;
}
