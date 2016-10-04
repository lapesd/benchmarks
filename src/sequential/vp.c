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
