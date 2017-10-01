#include "gs-helper.h"
#include <math.h>

// Comment/uncomment the below line to hide/show arrays
#define DPRINT

// Sequential Gauss-Jacobi solver using the red-black method
void gauss_jacobi_sequential(int asize) {
  int p_asize = asize+2; // Padded array size (+1 padding to each side)
  float *A, maxError, oldValue;
  init_arrays(SEED,p_asize,&A);

  int it, i, j;

  for(it = 1; it <= MAXIT; ++it) { // Repeat the estimation process
    // Red
    bool alt = false;
    for (i = 1; i < p_asize-1; i++) {
      for (j = !alt ? 1 : 2; j < p_asize-1; j+=2) {
        A[IND(i,j,p_asize)] = 0.25*(
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
        A[IND(i,j,p_asize)] = 0.25*(
        A[IND(i-1,j,p_asize)] +
        A[IND(i+1,j,p_asize)] +
        A[IND(i,j-1,p_asize)] +
        A[IND(i,j+1,p_asize)]);
      }
      alt = !alt;
    }
  }

  #ifdef DPRINT
    for(i = 0; i < p_asize; i+=p_asize/5) {
      printf("A[%4d,%4d]=%7.10f\n", i, i, A[IND(i,i,p_asize)]);
    }
  #endif

  clean_arrays(&A);
}

// Parallel Gauss-Jacobi solver using a spinlock (signal wait)
void gauss_jacobi_pipelined(int num_threads, int asize, int tile_size_x, int tile_size_y) {
  float *A;
  int p_asize = asize+2; // Padded array size (+1 padding to each side)
  init_arrays(SEED, p_asize, &A);
  //int i;

  /* ****************** YOUR CODE GOES HERE ****************** */
  //private variables
  int threadID, threadX, threadY, up, down, left, right;
  int idx_start, idy_start, idx_end, idy_end;
  int it, i, j, f_it; //f_it: iterator for flush
  bool alt;
  //public variables
  int num_tile_y = asize/tile_size_y;
  int num_tile_x = asize/tile_size_x;
  int barrier[num_threads];
  int k;
  for(k = 0; k != num_threads; ++k) {
    barrier[k] = 0;
  }

#pragma omp parallel num_threads(num_threads)\
private(threadID, threadX, threadY, up, down, left, right,\
idx_start, idy_start, idx_end, idy_end, it, i, j, f_it)
{
  threadID = omp_get_thread_num();
  threadX = threadID / num_tile_y;
  threadY = threadID % num_tile_y;
  up     = IND(threadX-1, threadY, num_tile_y);
  down   = IND(threadX+1, threadY, num_tile_y);
  left   = IND(threadX, threadY-1, num_tile_y);
  right  = IND(threadX, threadY+1, num_tile_y);
  
  idx_start = 1 + threadX*tile_size_x;
  idy_start = 1 + threadY*tile_size_y;
  idx_end   = 1 + (threadX+1)*tile_size_x;
  idy_end   = 1 + (threadY+1)*tile_size_y;

  for(it = 0; it != MAXIT; ++it) {
    //****RED****//
    //boundary check & spin on barrier
    while( (threadX-1 >= 0 && barrier[up] != it*2) ||
           (threadX+1 < num_tile_x && barrier[down] != it*2) ||
	   (threadY-1 >= 0 && barrier[left] != it*2) ||
	   (threadY+1 < num_tile_y && barrier[right] != it*2)) {
      #pragma omp flush //get newest barrier value
    }
    #pragma omp flush //get newest A value

    //calculation
    alt = false;
    for(i = idx_start; i != idx_end; ++i) {
      for(j = !alt ? idy_start: idy_start+1; j < idy_end; j+=2) {
        A[IND(i,j,p_asize)] = 0.25*(
        A[IND(i-1,j,p_asize)] +
        A[IND(i+1,j,p_asize)] +
        A[IND(i,j-1,p_asize)] +
        A[IND(i,j+1,p_asize)]);
      }
      alt = !alt;
    }
    #pragma omp flush //update A

    //update barrier
    barrier[threadID]++;
    #pragma omp flush



    //****BLACK****//
    //boundary check & spin on barrier
    while( (threadX-1 >= 0 && barrier[up] != it*2+1) ||
           (threadX+1 < num_tile_x && barrier[down] != it*2+1) ||
	   (threadY-1 >= 0 && barrier[left] != it*2+1) ||
	   (threadY+1 < num_tile_y && barrier[right] != it*2+1)) {
      #pragma omp flush //get newest barrier value
    }
    #pragma omp flush //get newest A value

    //calculation
    alt = true;
    for(i = idx_start; i != idx_end; ++i) {
      for(j = !alt ? idy_start: idy_start+1; j < idy_end; j+=2) {
        A[IND(i,j,p_asize)] = 0.25*(
        A[IND(i-1,j,p_asize)] +
        A[IND(i+1,j,p_asize)] +
        A[IND(i,j-1,p_asize)] +
        A[IND(i,j+1,p_asize)]);
      }
      alt = !alt;
    }
    #pragma omp flush //update A

    //update barrier
    barrier[threadID]++;
    #pragma omp flush
  }
}

  #ifdef DPRINT
    for(i = 0; i < p_asize; i+=p_asize/5) {
      printf("A[%4d,%4d]=%7.10f\n", i, i, A[IND(i,i,p_asize)]);
    }
  #endif

  clean_arrays(&A);
}

int main(int argc, char** argv) {
  int ncores = omp_get_max_threads();
  int num_threads = 1;
  int asize = 8;
  int tile_size_x = 4;
  int tile_size_y = 4;

  if (argc == 4) {
    asize = atoi(argv[1]);
    tile_size_x = atoi(argv[2]);
    tile_size_y = atoi(argv[3]);
  }

  num_threads = (asize*asize)/(tile_size_x*tile_size_y);

  // Run and time the sequential version
  time_seqn(asize);

  // Run and time the parallel version
  time_pipe(num_threads, asize, tile_size_x, tile_size_y);

  return 0;
}
