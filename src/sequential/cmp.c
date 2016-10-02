#include <stdio.h>
#include <stdlib.h>

#define MAGICNUMBER 26

int menor(int *a, int *b, int inicio, int fim){
    int num, i;
    num = 0;
    for (i = inicio; i < fim; i++){
        if (a[i] < b[i]){
            num++;
        }
    }
    return num;
}

int main(int argc, char **argv)
{
  int n, i;
  int inicio, fim;
  int resultado;
  int *A, *B;

  if(argc<2){
    printf("uso ./comparacao <numero natural maior do que zero>\n");
    exit(1);
  }
  n = atoi(argv[1]);
  if(n <= 0){
    printf("Erro! Numero de entrada nao e' grande o bastante\n");
    exit(1);
  }

  A = (int *) malloc(n*sizeof(int));
  B = (int *) malloc(n*sizeof(int));
  srand(MAGICNUMBER);
  for(i = 0; i < n; i++){
      A[i] = rand()%100;
      B[i] = rand()%100;
  }
   
  printf("Comparando os vetores A e B sem OpenMP\n");

  inicio = 0;
  fim = n;
  resultado = menor(A,B,inicio,fim);

  printf("A[i] é menor do que B[i] %d vezes\n", resultado);

  return 0;
}

