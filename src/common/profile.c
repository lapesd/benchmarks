/*
 * Copyright(C) 2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
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

#include <assert.h>
#include <stdio.h>

#include <papi.h>
#include <omp.h>

/**
 * @brief Number of events to profile.
 */
#define NR_EVENTS 4

/**
 * @brief Maximum number of threads to profile at once.
 */
#define MAX_THREADS 1024

/**
 * @brief Events to profile.
 */
static int events[NR_EVENTS] = {
	PAPI_L1_DCM, /* L1 data cache misses.   */
	PAPI_L2_DCM, /* L2 data cache misses.   */
	PAPI_L2_DCA, /* L2 data cache misses.   */
	PAPI_L3_DCA  /* L3 data cache accesses. */
};

/**
 * @brief Hardware counters.
 */
static long long hwcounters[MAX_THREADS][NR_EVENTS];

/**
 * @brief Number of threads being profiled.
 */
static int nthreads;

/**
 * @brief Setups profiler.
 *
 * @param _nthreads Number of threads to profile.
 */
void profile_setup(int _nthreads)
{
	/* Sanity check. */
	assert(_nthreads > 0);
	assert(_nthreads <= MAX_THREADS);

	nthreads = _nthreads;

	assert(PAPI_thread_init((long unsigned (*)(void))omp_get_thread_num) == PAPI_OK);
}


/**
 * @brief Start profiling.
 */
void profile_start(void)
{
	assert(PAPI_start_counters(events, NR_EVENTS) == PAPI_OK);
}

/**
 * @brief End profiling.
 */
void profile_end(void)
{
	int tid;

	tid = omp_get_thread_num();

	assert(tid < nthreads);

	assert(PAPI_stop_counters(&hwcounters[tid][0], sizeof(events)) == PAPI_OK);
}

/**
 * @brief Dump profiling statistics.
 */
void profile_dump(void)
{
	long long total[NR_EVENTS] = {0, };

	/* Compute total statistics. */
	for (int i = 0; i < nthreads; i++)
	{
		for (int j = 0; j < NR_EVENTS; j++)
			total[j] += hwcounters[i][j];
	}

	fprintf(stderr, "L1 Misses: %lld\n", total[0]);
	fprintf(stderr, "L2 Misses: %lld\n", total[1]);
	fprintf(stderr, "L2 Accesses: %lld\n", total[2]);
	fprintf(stderr, "L3 Accesses: %lld\n", total[3]);
}
