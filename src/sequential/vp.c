#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int tamanho_vetores;
  int i;
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

  printf("Inicializando vetores A e B...\n");

  /* inicializacao dos vetores */
  for (i=0; i<tamanho_vetores; i++)
    a[i] = i;

  for (i=0; i<tamanho_vetores; i++)
    b[i] = i;
  
  printf("Calculando...\n");

  /* produto escalar dos vetores */
  for (i=0; i<tamanho_vetores; i++)
    prod += a[i] * b[i];

  printf("Terminou!\n");

  /*** imprime o resultado ***/
  printf("******************************************************\n");
  printf("Produto escalar: %lu\n", prod);
  printf("******************************************************\n");

  free(a);
  free(b);
}
