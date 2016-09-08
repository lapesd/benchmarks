#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NITERATIONS 10

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

int main(int argc, char **argv)
{
	double start, end;

	if (argc != 2)
	{
		printf("Usage: mm <matrix size>\n");
		return (EXIT_SUCCESS);
	}

	n = atoi(argv[1]);

	/* Sanity check. */
	assert(n > 0);

	/* Create matrices. */
	assert((a = malloc(n*n*sizeof(double))) != NULL);
	assert((b = malloc(n*n*sizeof(double))) != NULL);
	assert((c = malloc(n*n*sizeof(double))) != NULL);

	/* Initialize matrices. */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			MATRIX(a, i, j) = 1.0;
			MATRIX(b, i, j) = 2.0;
			MATRIX(c, i, j) = 0.0;
		}
	}
	
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
