#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
  unsigned short rows;
  unsigned short columns;
  double **data;
}matriz;

unsigned short i,j,k;
double **ret;


// alocando a amatriz dinamicamente
double ** aloca( int lin, int col ){

    if( lin ==0 || col ==0 ){
      printf( "Impossivel alocar espaco\n" );
      exit( 3 );
    }
    ret =(double **)malloc( sizeof(double*) * lin );
    if( ret == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
    ret[0] =(double *)malloc( sizeof(double) * ( lin * col ) );
    if( ret[0] == NULL  ){
      printf( "Impossivel alocar espaco" );
      exit( 3 );
    }
    for( k=1; k<lin; k++ )
      ret[k] = ret[k-1] + col;
   return ret;
}

// multiplicando duas matrizes
matriz * times(matriz *m,matriz *n){
  //Critério
  if(m->columns!=n->rows){
    printf( "Impossivel multiplicar! Parâmetros incorretos.\n" );
    exit(0);
  }
  unsigned short q;// outro int
  double buffer=0;
  matriz *product;
  product = (matriz*)malloc(sizeof(matriz));
  //linhas de m e colunas de n
  product->rows=m->rows;
  product->columns=n->columns;
  product->data=aloca(product->rows,product->columns);
  for(q=0;q<m->rows;q++){
    for(i=0;i<m->columns;i++){
      for(j=0;j<n->rows;j++){
        buffer+=(m->data[q][j]*n->data[j][i]);
        product->data[q][i]=buffer;
      }
      buffer=0;
    }
  }
  return product;
}
// recebe um vetor qualquer e retorna o valor normalizado
matriz * normaEuclidiana(matriz *m){
  double norma=0;
  for(i=0;i<m->rows;i++){
    norma+=pow(m->data[0][i],2);
  }
  norma = sqrt(norma);

  for(i=0;i<m->rows;i++){
    m->data[0][i]/=norma;
  }
  return m;
}

void showMatriz(matriz *m){

  for(i=0;i<m->rows;i++){
    for(j=0;j<m->columns;j++){
        printf("%6s"," ");
        printf("%07.4f",m->data[i][j]);
      }
      printf("\n");
    }
  printf("\n");
}
void igualaMatrizes(matriz *m,matriz *n){
  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        m->data[i][j]=n->data[i][j];
}
// dada uma matriz retorna sua transposta
matriz * transposta(matriz *m){
  matriz *transposta;
  transposta = (matriz*)malloc(sizeof(matriz));
  transposta->rows=m->columns;
  transposta->columns=m->rows;
  transposta->data=aloca(transposta->rows,transposta->columns);

  for(i=0;i<m->rows;i++)
    for(j=0;j<m->columns;j++)
        transposta->data[j][i]=m->data[i][j];
  return transposta;
}
void stopProgram(){
  printf("k = 20, PROVAVELMENTE NÃO CONVERGE, TENTE OUTRO VETOR INICIAL V, OU UMA TOLERANCIA MENOR.\n");
  exit(0);
}
void potenciaRegular(matriz *m, matriz *v, double tolerance){
  double lambda=0;
  double lambdaK;
  double aux;
  int h=0;
  matriz *vk;
  vk=(matriz*)malloc(sizeof(matriz));
  vk->rows=v->rows;
  vk->columns=v->columns;
  vk->data=aloca(vk->rows,vk->columns);

  do{
    printf("loop: k = %d.\n",h+1);
    igualaMatrizes(vk,normaEuclidiana(v)); // normalizando v, e vk <- v normalizado "psi"k
    igualaMatrizes(v,times(m,vk));  // v+1
    printf("autovetor:\n");
    showMatriz(v);
    printf("autovetor normalizado:\n");
    showMatriz(normaEuclidiana(v));
    lambdaK = times(transposta(vk),v)->data[0][0]; // retorna uma matriz 1x1, ou um escalar
    printf("autovalor:\n");
    printf("%f\n",lambdaK);
    aux=fabs(lambdaK-lambda)/fabs(lambdaK);
    printf("tolerancia: %f\n",aux);
    lambda = lambdaK;
    h++;
    printf("==========================\n");
    if(h==20)
      stopProgram();
  }while(aux>tolerance);
}



// run: gcc PotenciaRegular.c -o potencia -lm
//      ./potencia


int main(int argc,char **argv){

  matriz *m;
  matriz *v;
  m = (matriz*)malloc(sizeof(matriz));
  v = (matriz*)malloc(sizeof(matriz));

  //Matriz A
  m->rows = 3;
  m->columns = 3;

  //Vetor v
  v->rows = 3;
  v->columns =1;

  m->data = aloca(m->rows,m->columns);
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
  potenciaRegular(m,v,0.01);
  printf("============  FIM  ===========\n");

  return EXIT_SUCCESS;
}

/*
  #versão comentada de potenciaRegular

void potenciaRegular(matriz *m, matriz *v, double tolerance){
  double lambda=0;
  double lambdaK;
  double aux;
  int h=0;
  matriz *vk;
  vk=(matriz*)malloc(sizeof(matriz));
  vk->rows=v->rows;
  vk->columns=v->columns;
  vk->data=aloca(vk->rows,vk->columns);

  do{
    //showMatriz(v);
    printf("lambda: %.4f\n", lambda);
    igualaMatrizes(vk,normaEuclidiana(v)); // normalizando v, e vk <- v normalizado "psi"k
    //showMatriz(vk);
    igualaMatrizes(v,times(m,vk));  // v+1
    lambdaK = times(transposta(vk),v)->data[0][0]; // retorna uma matriz 1x1, ou um escalar
    printf("lambdaK: %f\n", lambdaK);
    printf("\n");
    showMatriz(v);
    printf("vetor normalizado:\n");
    showMatriz(normaEuclidiana(v));
    aux=fabs(lambdaK-lambda)/fabs(lambdaK);
    printf("e: %f\n",aux);
    lambda = lambdaK;
    h++;
  }while(h<3);//abs(lambdaK-lambda)/abs(lambdaK)>tolerance);
}



*/