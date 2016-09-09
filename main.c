/*
 * Copyright(C) 2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
 * 
 * This file is part of the LaPeSD Benchmarks Suite.
 * 
 * LaPeSD Benchmarks Suite is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * LaPeSD Benchmarks Suite is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with CAP Benchmarks. If not, see <http://www.gnu.org/licenses/>.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NITERATIONS 5

/**
 * @param Sparse factor.
 */
#define SPARSE_FACTOR 80

#define MATRIX(m, i, j) m[(i)*n + (j)]

/*
 * @brief Matrix size.
 */
static int n = 0;

static double *a;
static double *b;
static double *c;

void mult1(void)
{
	#pragma omp parallel for
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				MATRIX(c, i, j) += MATRIX(a, i, k)*MATRIX(b, k, j);
		}
	}
}

void mult2(void)
{
	for (int i = 0; i < n; i++)
	{
		#pragma omp parallel for
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
				MATRIX(c, i, j) += MATRIX(a, i, k)*MATRIX(b, k, j);
		}
	}
}

/**
 * @brief Performs a sparse matrix multiplication.
 *
 * @param c Resulting matrix matrix.
 * @param a Sparse matrix.
 * @param b Dense matrix.
 */
static void sparsematrix_mult(restrict double *c, restrict const double *a, restrict const double *b)
{
	#pragma omp parallel for schedule(dynamic, 1)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (MATRIX(a, i, k) != 0)
					MATRIX(c, i, j) += MATRIX(a, i, k)*MATRIX(b, k, j);
			}
		}
	}
}

/**
 * @brief Prints program usage and exits.
 */
static void usage(void)
{
	printf("usage: mm <matrix size>\n");

	exit(EXIT_SUCCESS);
}

/**
 * @brief Initializes a matrix.
 *
 * @param m Target matrix.
 */
static void matrix_init(double *m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			MATRIX(m, i, j) = rand()/10.0;
	}
}

/**
 * @brief Initializes a sparse matrix.
 *
 * @param m Target matrix.
 */
static void sparsematrix(double *m)
{	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int zero;

			zero = (rand()%100 <= SPARSE_FACTOR) ? 0 : 1;
			
			MATRIX(m, i, j) = (zero) ? 0.0 : rand()/10.0;
		}
	}
}

int main(int argc, char **argv)
{
	double start, end;

	if (argc < 2)
		usage();
	
	/* Read command line arguments. */
	n = atoi(argv[1]);

	/* Sanity check. */
	assert(n > 0);

	/* Create matrices. */
	assert((a = malloc(n*n*sizeof(double))) != NULL);
	assert((b = malloc(n*n*sizeof(double))) != NULL);
	assert((c = malloc(n*n*sizeof(double))) != NULL);

	matrix_init(a);
	matrix_init(b);
	matrix_init(c);
	
	/* Benchmark 1. */
	for (int it = 0; it <= NITERATIONS; it++)
	{
		start = omp_get_wtime();
		mult1();
		end = omp_get_wtime();
		if (it)
			printf("mult1: %lf\n", end - start);
	}
	
	/* Benchmark 2. */
	for (int it = 0; it <= NITERATIONS; it++)
	{
		start = omp_get_wtime();
		mult2();
		end = omp_get_wtime();
		if (it)
			printf("mult2: %lf\n", end - start);
	}
	
	return (EXIT_FAILURE);
}
