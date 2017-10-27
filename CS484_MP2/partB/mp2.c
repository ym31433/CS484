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
    //debug
    //printAsequential(&A, asize);
    
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
void parallel_solver(int asize, int tileSizeY, int tileSizeX) {
  int myRank;
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

  // Subarray initialization with padding
  // Use A for the output array
  float *A;
  init_subarrays(myRank, tileSizeY, tileSizeX, &A);

  //prepare variables for calculation
  int numTilesX = asize / tileSizeX;
  int numTilesY = asize / tileSizeY;
  int rankX = myRank / numTilesY;
  int rankY = myRank % numTilesY;
  int up = IND(rankX-1, rankY, numTilesY);
  int down = IND(rankX+1, rankY, numTilesY);
  int left = IND(rankX, rankY-1, numTilesY);
  int right = IND(rankX, rankY+1, numTilesY);
  //debug
  /*
  if(up == 16 || down == 16 || right == 16 || left == 16) {
    printf("myRank = %d\n", myRank);
    printf("numTilesX = %d\n", numTilesX);
    printf("numTilesY = %d\n", numTilesY);
    printf("rankX = %d\n", rankX);
    printf("rankY = %d\n", rankY);
    printf("up    = %d\n", up);
    printf("down  = %d\n", down);
    printf("right = %d\n", right);
    printf("left  = %d\n", left);
  }*/
  int alt = 0;
  float* sendAup   =  (float*)malloc(tileSizeY*sizeof(float));
  float* sendAdown =  (float*)malloc(tileSizeY*sizeof(float));
  float* sendAleft =  (float*)malloc(tileSizeX*sizeof(float));
  float* sendAright = (float*)malloc(tileSizeX*sizeof(float));
  float* recvAup   =  (float*)malloc(tileSizeY*sizeof(float));
  float* recvAdown =  (float*)malloc(tileSizeY*sizeof(float));
  float* recvAleft =  (float*)malloc(tileSizeX*sizeof(float));
  float* recvAright = (float*)malloc(tileSizeX*sizeof(float));
  int i, j;
  MPI_Request reqUp, reqDown, reqLeft, reqRight;

  int it;
  for(it = 0; it < MAXIT; it++)
  {
    // Reset peak at the beginning of each iteration
    reset_peak(myRank, tileSizeY, &A);
    //debug
    //printA(myRank, &A, tileSizeX, tileSizeY);

    /* YOUR PARALLEL CODE GOES HERE */
    /*************RED****************/
    //sending ghost cells
    
    if(rankX-1 >= 0) {
      for(j = 0; j != tileSizeY; ++j) {
        sendAup[j] = A[IND(1, j+1, tileSizeY+2)];
      }
      MPI_Isend(sendAup, tileSizeY, MPI_FLOAT, up, 0, MPI_COMM_WORLD, &reqUp);
    }
    if(rankX+1 < numTilesX) {
      //debug
      //printf("down, myRank = %d\n", myRank);
      for(j = 0; j != tileSizeY; ++j) {
        sendAdown[j] = A[IND(tileSizeX, j+1, tileSizeY+2)];
      }
      MPI_Isend(sendAdown, tileSizeY, MPI_FLOAT, down, 1, MPI_COMM_WORLD, &reqDown);
    }
    if(rankY-1 >= 0) {
      //debug
      //printf("left, myRank = %d\n", myRank);
      for(i = 0; i != tileSizeX; ++i) {
        sendAleft[i] = A[IND(i+1, 1, tileSizeY+2)];
      }
      MPI_Isend(sendAleft, tileSizeX, MPI_FLOAT, left, 2, MPI_COMM_WORLD, &reqLeft);
    }
    if(rankY+1 < numTilesY) {
      for(i = 0; i != tileSizeX; ++i) {
        sendAright[i] = A[IND(i+1, tileSizeY, tileSizeY+2)];
      }
      MPI_Isend(sendAright, tileSizeX, MPI_FLOAT, right, 3, MPI_COMM_WORLD, &reqRight);
    }
    //receiving ghost cells
    if(rankX+1 < numTilesX) {
      MPI_Recv(recvAdown, tileSizeY, MPI_FLOAT, down, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(j = 0; j != tileSizeY; ++j) {
        A[IND(tileSizeX+1, j+1, tileSizeY+2)] = recvAdown[j];
      }
    }
    if(rankX-1 >= 0) {
      MPI_Recv(recvAup, tileSizeY, MPI_FLOAT, up, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(j = 0; j != tileSizeY; ++j) {
        A[IND(0, j+1, tileSizeY+2)] = recvAup[j];
      }
    }
    if(rankY+1 < numTilesY) {
      MPI_Recv(recvAright, tileSizeX, MPI_FLOAT, right, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(i = 0; i != tileSizeX; ++i) {
        A[IND(i+1, tileSizeY+1, tileSizeY+2)] = recvAright[i];
      }
    }
    if(rankY-1 >= 0) {
      MPI_Recv(recvAleft, tileSizeX, MPI_FLOAT, left, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(i = 0; i != tileSizeX; ++i) {
        A[IND(i+1, 0, tileSizeY+2)] = recvAleft[i];
      }
    }
 
    //debug
    //printA(myRank, &A, tileSizeX, tileSizeY);
    //calculation
    alt = 0;
    for(i = 1; i != tileSizeX+1; ++i) {
      for(j = !((alt^(tileSizeX&rankX)^(tileSizeY&rankY))&1) ? 1: 2; j < tileSizeY+1; j+=2) {
        /*debug
	if(myRank == 0) {
          printf("i, j = %d, %d\n", i, j);
	}*/
        A[IND(i,j,tileSizeY+2)] = 0.20*(
        A[IND(i,j,tileSizeY+2)] +
        A[IND(i-1,j,tileSizeY+2)] +
        A[IND(i+1,j,tileSizeY+2)] +
        A[IND(i,j-1,tileSizeY+2)] +
        A[IND(i,j+1,tileSizeY+2)]);
      }
      alt = !alt;
    }
    
    //debug
    //printA(myRank, &A, tileSizeX, tileSizeY);
    //synchronization
    if(rankX-1 >= 0) {
      MPI_Wait(&reqUp, MPI_STATUS_IGNORE);
    }
    if(rankX+1 < numTilesX) {
      MPI_Wait(&reqDown, MPI_STATUS_IGNORE);
    }
    if(rankY-1 >= 0) {
      MPI_Wait(&reqLeft, MPI_STATUS_IGNORE);
    }
    if(rankY+1 < numTilesY) {
      MPI_Wait(&reqRight, MPI_STATUS_IGNORE);
    }
    /*************BLACK****************/
    
    //sending ghost cells
    if(rankX-1 >= 0) {
      for(j = 0; j != tileSizeY; ++j) {
        sendAup[j] = A[IND(1, j+1, tileSizeY+2)];
      }
      MPI_Isend(sendAup, tileSizeY, MPI_FLOAT, up, 0, MPI_COMM_WORLD, &reqUp);
    }
    if(rankX+1 < numTilesX) {
      for(j = 0; j != tileSizeY; ++j) {
        sendAdown[j] = A[IND(tileSizeX, j+1, tileSizeY+2)];
      }
      MPI_Isend(sendAdown, tileSizeY, MPI_FLOAT, down, 1, MPI_COMM_WORLD, &reqDown);
    }
    if(rankY-1 >= 0) {
      for(i = 0; i != tileSizeX; ++i) {
        sendAleft[i] = A[IND(i+1, 1, tileSizeY+2)];
      }
      MPI_Isend(sendAleft, tileSizeX, MPI_FLOAT, left, 2, MPI_COMM_WORLD, &reqLeft);
    }
    if(rankY+1 < numTilesY) {
      for(i = 0; i != tileSizeX; ++i) {
        sendAright[i] = A[IND(i+1, tileSizeY, tileSizeY+2)];
      }
      MPI_Isend(sendAright, tileSizeX, MPI_FLOAT, right, 3, MPI_COMM_WORLD, &reqRight);
    }
    //receiving ghost cells
    if(rankX+1 < numTilesX) {
      MPI_Recv(recvAdown, tileSizeY, MPI_FLOAT, down, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(j = 0; j != tileSizeY; ++j) {
        A[IND(tileSizeX+1, j+1, tileSizeY+2)] = recvAdown[j];
      }
    }
    if(rankX-1 >= 0) {
      MPI_Recv(recvAup, tileSizeY, MPI_FLOAT, up, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(j = 0; j != tileSizeY; ++j) {
        A[IND(0, j+1, tileSizeY+2)] = recvAup[j];
      }
    }
    if(rankY+1 < numTilesY) {
      MPI_Recv(recvAright, tileSizeX, MPI_FLOAT, right, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(i = 0; i != tileSizeX; ++i) {
        A[IND(i+1, tileSizeY+1, tileSizeY+2)] = recvAright[i];
      }
    }
    if(rankY-1 >= 0) {
      MPI_Recv(recvAleft, tileSizeX, MPI_FLOAT, left, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      for(i = 0; i != tileSizeX; ++i) {
        A[IND(i+1, 0, tileSizeY+2)] = recvAleft[i];
      }
    }
 
    //calculation
    alt = 1;
    for(i = 1; i != tileSizeX+1; ++i) {
      for(j = !((alt^(tileSizeX&rankX)^(tileSizeY&rankY))&1) ? 1: 2; j < tileSizeY+1; j+=2) {
        A[IND(i,j,tileSizeY+2)] = 0.20*(
        A[IND(i,j,tileSizeY+2)] +
        A[IND(i-1,j,tileSizeY+2)] +
        A[IND(i+1,j,tileSizeY+2)] +
        A[IND(i,j-1,tileSizeY+2)] +
        A[IND(i,j+1,tileSizeY+2)]);
      }
      alt = !alt;
    }
    
    //synchronization
    if(rankX-1 >= 0) {
      MPI_Wait(&reqUp, MPI_STATUS_IGNORE);
    }
    if(rankX+1 < numTilesX) {
      MPI_Wait(&reqDown, MPI_STATUS_IGNORE);
    }
    if(rankY-1 >= 0) {
      MPI_Wait(&reqLeft, MPI_STATUS_IGNORE);
    }
    if(rankY+1 < numTilesY) {
      MPI_Wait(&reqRight, MPI_STATUS_IGNORE);
    }
    /* INSTRUCTION: Add code below that will aggregate sum of all processes'
     *              subarrays into the variable iter_sum
     */
    float iter_sum = 0.0f;

    #ifdef REPORT_SUM
      /*
       *  Sum all cells in all processes and
       *  store it to Rank 0's iter_sum
       */
    float local_sum = 0.0f;
    for(i = 1; i != tileSizeX+1; ++i) {
      for(j = 1; j != tileSizeY+1; ++j) {
        local_sum += A[IND(i, j, tileSizeY+2)];
      }
    }
    MPI_Reduce(&local_sum, &iter_sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
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
