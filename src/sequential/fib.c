#include <stdio.h>
#include <stdlib.h>

long fib(int n)
{
  // Algoritmo: f(n) = f(n-1) + f(n-2)
  long f1, f2, fn;
  if ( n == 0 || n == 1 ) return(n);

  f1 = fib(n-1);
  f2 = fib(n-2);
  fn = f1 + f2;
  return fn;
}

int main(int argc, char **argv)
{
  int n;
  long resultado;
  if(argc<2){
    printf("uso ./fibonacci <numero natural>\n");
    exit(1);
  }
  n = atoi(argv[1]);
  if(n < 0){
    printf("Erro! Numero de entrada nao e' natural\n");
    exit(1);
  }

  printf("Calculando fibonacci de %d sem OpenMP\n",n);

  resultado = fib(n);
  printf("finonacci(%d) = %ld\n", n, resultado);

  return 0;
}
