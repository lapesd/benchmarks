#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int NRA, NCA, NCB;
  int i, j, k;
  int imprimir = 0;

  if(argc<4){
    printf("uso %s <numero linhas A> <numero colunas A> <numero colunas B> [imprimir? 1=sim]\n", argv[0]);
    exit(1);
  }
  
  /* numero de linhas da matriz A */
  NRA = atoi(argv[1]);
  
  /* numero de colunas da matriz A */
  NCA = atoi(argv[2]);
  
  /* numero de colunas da matriz B */
  NCB = atoi(argv[3]);

  if(argc==5 && atoi(argv[4])==1)
    imprimir = 1;

  /* alocacao da matriz A */
  double **a = (double **) malloc(sizeof(double *) * NRA);
  for (i = 0; i < NRA; i ++)
    a[i] = (double *) malloc(sizeof(double) * NCA);

  /* alocacao da matriz B */
  double **b = (double **) malloc(sizeof(double *) * NCA);
  for (i = 0; i < NCA; i ++)
    b[i] = (double *) malloc(sizeof(double) * NCB);

  /* alocacao da matriz C (resultado) */
  double **c = (double **) malloc(sizeof(double *) * NRA);
  for (i = 0; i < NRA; i ++)
    c[i] = (double *) malloc(sizeof(double) * NCB);

  printf("Inicializando matrizes A, B e C...\n");

  /* inicializacao das matrizes */
  for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[i][j]= i+j;

  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[i][j]= i*j;

  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[i][j]= 0;

  printf("Calculando...\n");
  
  /* multiplicacao das matrizes */
  for (i=0; i<NRA; i++)
    for(j=0; j<NCB; j++)
      for (k=0; k<NCA; k++)
        c[i][j] += a[i][k] * b[k][j];

  printf("Terminou!\n");

  if(imprimir)
  {
    /*** imprime os resultados ***/
    printf("******************************************************\n");
    printf("Matriz C:\n");
    for (i=0; i<NRA; i++)
    {
      for (j=0; j<NCB; j++)
        printf("%10.2f  ", c[i][j]);
      printf("\n");
    }
    printf("******************************************************\n");
  }

  for (i = 0; i < NRA; i ++)
    free(a[i]);
  free(a);

  for (i = 0; i < NCA; i ++)
    free(b[i]);
  free(b);

  for (i = 0; i < NRA; i ++)
    free(c[i]);
  free(c);
}
