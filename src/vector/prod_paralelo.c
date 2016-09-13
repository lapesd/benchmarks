#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int tamanho_vetores;
  unsigned long int prod = 0.0;

  if(argc<2){
    printf("uso %s <tamanho vetores>\n", argv[0]);
    exit(1);
  }
  
  /* tamanho dos vetores */
  tamanho_vetores = atoi(argv[1]);
  
  
  /* alocacao do vetor A */
  unsigned long int *a = (unsigned long int *) malloc(sizeof(unsigned long int) * tamanho_vetores);
  /* alocacao do vetor B */
  unsigned long int *b = (unsigned long int *) malloc(sizeof(unsigned long int) * tamanho_vetores);
  
  /* Initialização. */
   /* inicializacao dos vetores */
    #pragma omp parallel for
    for (int i=0; i<tamanho_vetores; i++)
      a[i] = i;

    #pragma omp parallel for
    for (int i=0; i<tamanho_vetores; i++)
      b[i] = i;

    /* produto escalar dos vetores */
    #pragma omp parallel for reduction(+:prod)
    for (int i=0; i<tamanho_vetores; i++)
      prod += a[i] * b[i];

  free(a);
  free(b);
}
