#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGICNUMBER 26

int main(int argc, char **argv)
{
  int n, i;
  long *A, *SOMA, *PRODUTO;
  if(argc<2){
    printf("uso ./prefixo <numero natural maior do que zero>\n");
    exit(1);
  }
  n = atoi(argv[1]);
  if(n <= 0){
    printf("Erro! Numero de entrada nao e' grande o bastante\n");
    exit(1);
  }

  A = (long *) malloc(n*sizeof(long));
  SOMA = (long *) malloc(n*sizeof(long));
  PRODUTO = (long *) malloc(n*sizeof(long));

  srand(MAGICNUMBER);
  for(i = 0; i < n; i++){
      A[i] = rand()%5 + 1;
  }
  SOMA[0] = A[0];
  PRODUTO[0] = A[0];

  for(i = 1; i < n; i++){
      SOMA[i] = SOMA[i-1] + A[i];
  }
  printf("Soma dos prefixos calculado. Valor da ultima posicao = %ld\n", SOMA[n-1]);

  for(i = 1; i < n; i++){
      PRODUTO[i] = PRODUTO[i-1] * A[i];
  }
  printf("Produto dos prefixos calculado. Valor da ultima posicao = %ld\n", PRODUTO[n-1]);

  return 0;
}
