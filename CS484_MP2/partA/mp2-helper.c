#include "mp2-helper.h"

// Get the current time
double get_time() {
  struct timeval tv;
  gettimeofday(&tv,0);
  return (tv.tv_sec*1.0+tv.tv_usec*1e-6);
}

// Record the execution time of sequential solver
void time_seqn(int asize) {
  double start = get_time();
  sequential_solver(asize);
  double end = get_time();
  printf("----Sequential, %ix%i matrix",asize,asize);
  printf("\tTook %lf seconds\n\n",end-start);
}

// Record the execution time of one of the Gauss-Jacobi functions
void time_parallel(int myRank, int asize, int tileSizeX, int tileSizeY) {
  double start = get_time();
  parallel_solver(asize,tileSizeX,tileSizeY);
  double end = get_time();
  if(!myRank) {
    printf("----Parallel, %ix%i matrix, tilesize %ix%i",asize,asize,tileSizeX,tileSizeY);
    printf("\tTook %lf seconds\n\n",end-start);
  }
}

// Whole array with padding
void init_array(int asize, float **A) {
  // Allocate memory
  *A = (float *)malloc(sizeof(float*)*(asize+2)*(asize+2));

  // Initialize the contents of A (just putting something a small non-0 vlaue)
  int i, j;
  for(i = 0; i < asize+2; ++i) {
    for(j = 0; j < asize+2; ++j) {
      (*A)[IND(i,j,asize+2)] = 1.0f;
    }
  }

  for(i = 1; i < asize+1; ++i) {
    for(j = 1; j < asize+1; ++j) {
      (*A)[IND(i,j,asize+2)] = 5.0f;
    }
  }

  (*A)[IND(2,2,asize+2)] = 100.0f;
}

void reset_peak_seq(int asize, float **A) {
  (*A)[IND(2,2,asize+2)] = 100.0f;
}

// Subarray with padding
void init_subarrays(int rank, int tileSizeX, int tileSizeY, float **A)
{
  // Allocate memory
  *A = (float *)malloc(sizeof(float*)*(tileSizeX+2)*(tileSizeY+2));

  // Initialize the contents of A (just putting something a small non-0 vlaue)
  int i, j;
  for(i = 0; i < tileSizeY+2; ++i) {
    for(j = 0; j < tileSizeX+2; ++j) {
      (*A)[IND(i,j,(tileSizeX+2))] = 1.0f;
    }
  }

  for(i = 1; i < tileSizeY+1; ++i) {
    for(j = 1; j < tileSizeX+1; ++j) {
      (*A)[IND(i,j,tileSizeX+2)] = 5.0f;
    }
  }

  if(!rank)
    (*A)[IND(2,2,tileSizeX+2)] = 100.0f;
}

void reset_peak(int rank, int tileSizeX, float **A) {
  if(!rank)
    (*A)[IND(2,2,tileSizeX+2)] = 100.0f;
}

// Reporting on each iteration
void report_iteration(int rank, int iter, float iteration_sum, float **A)
{
  /* 
   * Some outputs that used for grading
   */

  if(!rank || rank == -1)
    if(iter+1 == MAXIT)
      printf("Iter: %d, global sum = %f\n", iter, iteration_sum);
}

// Deallocate memory for arrays
void clean_arrays(float **A) {
  free(*A);
}

//print matrix
void printA(int rank, float** A, int tileSizeX, int tileSizeY) {
  if(rank == 0) {
    int i, j;
    printf("myRank = %d, A = \n", rank);
    for(i = 0; i != tileSizeX+2; ++i) {
      for(j = 0; j != tileSizeY+2; ++j) {
        printf("%f ", (*A)[IND(i, j, tileSizeY+2)]);
      }
      printf("\n");
    }
  }
}

//print A sequential
void printAsequential(float** A, int a_size) {
  int i, j;
  for(i = 0; i != a_size+2; ++i) {
    for(j = 0; j != a_size+2; ++j) {
      printf("%f ", (*A)[IND(i, j, a_size+2)]);
    }
    printf("\n");
  }
}
