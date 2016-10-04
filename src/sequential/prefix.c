/*
 * Copyright(C) 2016 Marcio Castro <marcio.castro@ufsc.br>
 * 
 * This file is part of the LaPeSD Benchmarks Suite.
 * 
 * LaPeSD Benchmarks Suite is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * LaPeSD Benchmarks Suite is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with CAP Benchmarks. If not, see
 * <http://www.gnu.org/licenses/>.
 */

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
