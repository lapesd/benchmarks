#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int stop = 20;

long fib(int n)
{
  // Algoritmo: f(n) = f(n-1) + f(n-2)
  long f1, f2, fn;
  if ( n == 0 || n == 1 ) return(n);

  if(n < stop){
    return fib(n-1)+fib(n-2);
  }
  else{

#pragma omp task shared(f1)
    f1 = fib(n-1);

#pragma omp task shared(f2)
    f2 = fib(n-2);

#pragma omp taskwait
    fn = f1 + f2;

    return fn;
  }
}

int main(int argc, char **argv)
{
  int n;
  unsigned long int resultado;
  double start, end;

  if(argc<3){
    printf("uso ./fibonacci <numero natural> <n sequencial>\n");
    exit(1);
  }
  n = atoi(argv[1]);
  stop = atoi(argv[2]);

  if(n < 0){
    printf("Erro! Numero de entrada nao e' natural\n");
    exit(1);
  }

  start = omp_get_wtime();

  #pragma omp parallel
  {
    #pragma omp single nowait
    {
      //printf("Calculando fibonacci de %d com %d threads (sequencial a partir de %d)\n", n, omp_get_num_threads(), stop);
      resultado = fib(n);
    }
  }

  end = omp_get_wtime();

  #pragma omp parallel
  #pragma omp single
  printf("%d %d %lu %d %lf\n", n, stop, resultado, omp_get_num_threads(), end - start);
  return 0;
}
