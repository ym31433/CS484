#include "mp2-helper.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Sequential solver using red-black method
void sequential_solver(int asize) {

  int p_asize = asize+2;
  float *A;
  init_array(asize,&A);
  int it, i, j;

  for(it = 0; it < MAXIT; ++it) {
    reset_peak_seq(asize, &A);
    // Red
    bool alt = false;
    for (i = 1; i < p_asize-1; i++) {
      for (j = !alt ? 1 : 2; j < p_asize-1; j+=2) {
        A[IND(i,j,p_asize)] = 0.20*(
        A[IND(i,j,p_asize)] +
        A[IND(i-1,j,p_asize)] +
        A[IND(i+1,j,p_asize)] +
        A[IND(i,j-1,p_asize)] +
        A[IND(i,j+1,p_asize)]);
      }
      alt = !alt;
    }
    
    // Black
    alt = true;
    for (i = 1; i < p_asize-1; i++) {
      for (j = !alt ? 1 : 2; j < p_asize-1; j+=2) {
        A[IND(i,j,p_asize)] = 0.20*(
	A[IND(i,j,p_asize)] +
        A[IND(i-1,j,p_asize)] +
        A[IND(i+1,j,p_asize)] +
        A[IND(i,j-1,p_asize)] +
        A[IND(i,j+1,p_asize)]);
      }
      alt = !alt;
    }

    float iteration_sum = 0.0f;

    #ifdef REPORT_SUM
    for(i = 1; i < p_asize-1; i++)
      for(j = 1; j < p_asize-1; j++)
        iteration_sum += A[IND(i,j,p_asize)];
    #endif

    report_iteration(-1, it, iteration_sum, &A);
  }

  clean_arrays(&A);
}

// Parallel solver using MPI and red-black method
void parallel_solver(int asize, int tileSizeX, int tileSizeY) {
  int myRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

  // Subarray initialization with padding
  // Use A for the output array
  float *A;
  init_subarrays(myRank, tileSizeX, tileSizeY, &A);

  int it;
  for(it = 0; it < MAXIT; it++)
  {
    // Reset peak at the beginning of each iteration
    reset_peak(myRank, tileSizeX, &A);

    /*
     * YOUR PARALLEL CODE GOES HERE
     *
     *
     *
     *
     *
     *
     */

    /* INSTRUCTION: Add code below that will aggregate sum of all processes'
     *              subarrays into the variable iter_sum
     */
    float iter_sum = 0.0f;

    #ifdef REPORT_SUM
      /*
       *  Sum all cells in all processes and
       *  store it to Rank 0's iter_sum
       */
    #endif

    // Report on iteration: DO NOT REMOVE THIS LINE
    report_iteration(myRank, it, iter_sum, &A);
  }
  
  clean_arrays(&A);
}

int main(int argc, char** argv) {

  int asize = 8;
  int tile_size_x = 4;
  int tile_size_y = 4;
  
  int nProcs;
  int myRank;
  MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &nProcs);
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

  if (argc < 4) {
    if(!myRank) {
      printf("USAGE: mpirun -np <Number of Processes> ./mp2 <Matrix Dimension> <Tile Size X> <Tile Size Y>\n");
      MPI_Finalize();
      return -1;
    }
  }

  if (argc == 4) {
    asize = atoi(argv[1]);
    tile_size_x = atoi(argv[2]);
    tile_size_y = atoi(argv[3]);
  }

  // Run and time the sequential version
 
  #ifdef RUN_SEQ
  if(!myRank) {
    time_seqn(asize);
  }

  // Let sequential finish
  MPI_Barrier(MPI_COMM_WORLD);
  #endif

  // Run and time the parallel version
  time_parallel(myRank, asize, tile_size_x, tile_size_y);

  MPI_Finalize();
  return 0;
}
