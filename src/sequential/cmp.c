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

