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

#include <omp.h>

/**
 * @brief Maximum number of threads to profile at once.
 */
#define MAX_THREADS 1024

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
}


/**
 * @brief Start profiling.
 */
void profile_start(void)
{

}

/**
 * @brief End profiling.
 */
void profile_end(void)
{

}

/**
 * @brief Dump profiling statistics.
 */
void profile_dump(void)
{

}
