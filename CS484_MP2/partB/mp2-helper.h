#ifndef MP2_HELPER_H
#define MP2_HELPER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mpi.h>
#include "sys/time.h"

#define DPRINT
#define REPORT_SUM
//#define RUN_SEQ
#define MAXIT  1000       // Maxinum number of iterations to allow

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define IND(i,j,size) ((i)*(size)+(j))

void sequential_solver(int asize);
void parallel_solver(int asize, int tileSizeX, int tileSizeY); 

// Get the current time
double get_time();

// Record the execution time of one of the Gauss-Jacobi functions
void time_seqn(int asize);

// Record the execution time of one of the Gauss-Jacobi functions
void time_parallel(int myRank, int asize, int tileSizeX, int tileSizeY);

// Allocate memory for the entire (single) array
void init_array(int asize, float **A);

// Reset peak for sequential
void reset_peak_seq(int asize, float **A);

// Allocate memory for each subarray with padding
void init_subarrays(int rank, int tileSizeX, int tileSizeY, float **A); 

// Reset peak for parallel
void reset_peak(int rank, int tileSizeX, float **A);

// Report on each iteration
void report_iteration(int rank, int iter, float iteration_sum, float **A);

// Deallocate memory for arrays
void clean_arrays(float **A);

#endif //#MP2_HELPER_H
