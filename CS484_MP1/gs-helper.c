#include "gs-helper.h"

// Get the current time
double get_time() {
  struct timeval tv;
  gettimeofday(&tv,0);
  return (tv.tv_sec*1.0+tv.tv_usec*1e-6);
}

// Record the execution time of one of the Gauss-Jacobi functions
void time_seqn(int asize) {
  double start = get_time();
  gauss_jacobi_sequential(asize);
  double end = get_time();
  printf("----Sequential, %ix%i matrix",asize,asize);
  printf("\tTook %lf seconds\n\n",end-start);
}

// Record the execution time of one of the Gauss-Jacobi functions
void time_pipe(int threads, int asize, int tileSizeX, int tileSizeY) {
  double start = get_time();
  gauss_jacobi_pipelined(threads,asize,tileSizeX,tileSizeY);
  double end = get_time();
  printf("----Pipelined, %i threads, %ix%i matrix, tilesize %ix%i",threads,asize,asize,tileSizeX,tileSizeY);
  printf("\tTook %lf seconds\n\n",end-start);
}

// Allocate memory for and initiallize arrays
void init_arrays(int seed, int p_asize, float **A) {
  // Allocate memory
  *A = (float *)malloc(sizeof(float*)*p_asize*p_asize);

  // Initialize the contents of A (just putting something a small non-0 vlaue)
  int i, j;
  for(i = 0; i < p_asize; ++i) {
    for(j = 0; j < p_asize; ++j) {
      (*A)[IND(i,j,p_asize)] = 0.001;
    }
  }

  for(i = 0; i < p_asize; ++i) {
    (*A)[IND(i,0,p_asize)] = 0.5f*(float)i/(float)p_asize;
    (*A)[IND(i,p_asize-1,p_asize)] = 0.5f+0.5f*(float)i/(float)p_asize;
  }

  for(j = 0; j < p_asize; ++j) {
    (*A)[IND(0,j,p_asize)] = 0.5f*(float)j/(float)p_asize;
    (*A)[IND(p_asize-1,j,p_asize)] = 0.5f+0.5f*(float)j/(float)p_asize;
  }
}

// Deallocate memory for arrays
void clean_arrays(float **A) {
  free(*A);
}