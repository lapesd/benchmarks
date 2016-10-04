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
