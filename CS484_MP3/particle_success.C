#include <stdlib.h>
#include <vector>
#include <assert.h>
#include "pup_stl.h"
#include "particle.h"
#include "ParticlesNoSDAG.decl.h"

#define REP_INTERVAL 10
#define LB_INTERVAL 20
#define BOXSIZE 100
#define INVALIDCOORDINATE -1

/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ CProxy_Cell cellProxy;
/*readonly*/ int particleMultiplier;
/*readonly*/ int charesPerDim;
/*readonly*/ int totalIter;

using namespace std;

class Main: public CBase_Main 
{
    private:
        int iteration;
        int sum;
        int max;

    public:
       
        Main(CkArgMsg* m) 
        {        
            if(m->argc < 3)
            {
                CkAbort("USAGE: ./charmrun +p<number_of_processors> ./particle <Iterations> <particles multiplier> <chares per dimension>");
            }

            mainProxy = thisProxy;
            totalIter = atoi(m->argv[1]);
            particleMultiplier = atoi(m->argv[2]);
            charesPerDim = atoi(m->argv[3]);

            iteration = 1;
            sum = -1;
            max = -1;
        
            // Create the cells and start the simulation by calling run().
            // Total number of chares in one dimension
            CkArrayOptions opts(charesPerDim, charesPerDim);
            cellProxy = CProxy_Cell::ckNew(opts);

            cellProxy.run();
        }

        void sumReduction(int value) {
            sum = value;
            //CkPrintf("ITER %d, Total: %d\n", iteration, sum);
            if(max != -1) printTotal();
        }
        void maxReduction(int value) {
            max = value;
            //CkPrintf("ITER %d, MAX: %d\n", iteration, max);
            if(sum != -1) printTotal();
        }
    
        void iterationEnd()
        {
            CkPrintf("iteration: %d\n", iteration);
            iteration++;
            sum = -1;
            max = -1;
            cellProxy.run();
        }

        void printTotal()
        {
            CkPrintf("ITER %d, MAX: %d, TOTAL: %d\n", iteration, max, sum);
        }

        void done()
        {
            CkPrintf("Simulation Complete\n");
            CkExit();
        }
};

// This class represent the cells of the simulation.
// Each cell contains a vector of particles.
// On each iteration, the cell perturbs the particles that it contains and moves
// them to neighboring cells as necessary.
class Cell: public CBase_Cell 
{
    public:
        int iteration;
        vector<Particle> particles;

        int neighborCount, recvCount, leftIdx, rightIdx, upIdx, downIdx;
        int myX, myY;
	double mySize;

        Cell() 
        {
	    int numInitParticles = (thisIndex.x * thisIndex.y) * particleMultiplier;
            iteration = 0;
            neighborCount = 4;
            recvCount = 0;
	    leftIdx = thisIndex.x == 0 ? charesPerDim - 1 : thisIndex.x - 1;
	    rightIdx = (thisIndex.x + 1) % charesPerDim;
	    upIdx = thisIndex.y == 0 ? charesPerDim - 1 : thisIndex.y - 1;
	    downIdx = (thisIndex.y + 1) % charesPerDim;

            mySize = 100.0/charesPerDim;
            myX = mySize * thisIndex.x;
	    myY = mySize * thisIndex.y;

            #ifdef USE_LB
	    usesAtSync = true;
	    #endif

            populateCell(numInitParticles);
        }
        
        Cell(CkMigrateMessage* m) 
        {
            // No operation.
        }
        
        void pup(PUP::er &p)
        {
	    CBase_Cell::pup(p);
            p|iteration;
            p|recvCount;
	    p|neighborCount;
	    p|particles;
	    p|mySize;
	    p|myX;
	    p|myY;
            p|leftIdx;
            p|rightIdx;
            p|upIdx;
            p|downIdx;
        }

        void iterInit()
        {
            iteration++;
            recvCount = 0;
        }

        void run() 
        {
            iterInit();
            updateParticles();
        }

        // Update the new location for my particles and send them to their belonging chares
        void updateParticles() {

	    vector<Particle> up, left, right, down;

            int index = 0;
            while (index < particles.size()) {
              Particle& p = particles[index];
              perturb(&p);

              bool moved = false;
              if (p.y < myY) {
                up.push_back(p);
                moved = true;
              } 
              else if (p.y > myY + mySize) {
                down.push_back(p);
                moved = true;
              } 
              else {
                if (p.x < myX) { left.push_back(p); moved = true; }
                if (p.x > myX + mySize) { right.push_back(p); moved = true; }
              }
              if (moved) {
                std::swap(particles[index], particles[particles.size() - 1]);
                particles.pop_back();
              } 
              else {
                index++;
              }
            }

            thisProxy(thisIndex.x, upIdx).updateNeighbor(iteration, up);
            thisProxy(thisIndex.x, downIdx).updateNeighbor(iteration, down);
            thisProxy(leftIdx, thisIndex.y).updateNeighbor(iteration, left);
            thisProxy(rightIdx, thisIndex.y).updateNeighbor(iteration, right);
        }

        void updateNeighbor(int inIteration, vector<Particle> incoming)
        {
            if (inIteration == iteration)
            {
                particles.insert(particles.end(), incoming.begin(), incoming.end());
                recvCount++;

                if(recvCount == neighborCount)
                {
                    if(iteration != totalIter) 
		    {
                        if(iteration % REP_INTERVAL == 0)
                        {
			   /* Your code for Part 1 goes here */
                            int value = particles.size();
                            CkCallback ck_sum(CkReductionTarget(Main, sumReduction), mainProxy);
                            contribute(sizeof(int), &value, CkReduction::sum_int, ck_sum);
                            CkCallback ck_max(CkReductionTarget(Main, maxReduction), mainProxy);
                            contribute(sizeof(int), &value, CkReduction::max_int, ck_max);
                            //contribute(sizeof(int), &value, CkReduction::sum_int, CkCallback(CkReductionTarget(Main, sumReduction), mainProxy));
                            //contribute(sizeof(int), &value, CkReduction::max_int, CkCallback(CkReductionTarget(Main, maxReduction), mainProxy));
                        }

                        #ifndef USE_LB
                        contribute(CkCallback(CkReductionTarget(Main, iterationEnd), mainProxy));

			#else

			/* For Part 2 */
                        if(iteration % LB_INTERVAL == 0)
			{

			}
			else
			{

			}
                        #endif

                    } 
                    else
                    {
                        contribute(CkCallback(CkReductionTarget(Main, done), mainProxy));                        
                    }
                }
            }
            else
            {
                thisProxy(thisIndex.x, thisIndex.y).updateNeighbor(inIteration, incoming);
            }
        }

    private:
        void populateCell(int initialElements) 
        {
            // Create random particles and add then to the particles vector.
            for (int i=0; i<initialElements; i++)
            {
                double x = drand48()*mySize + myX;
		double y = drand48()*mySize + myY;

                Particle *particle = new Particle(x, y);

                particles.push_back(*particle);
            }
        }

        void perturb(Particle* particle) 
        {
            double deltax = (drand48()-drand48())*(100.0/charesPerDim);
	    double deltay = (drand48()-drand48())*(100.0/charesPerDim);

	    // Only move in one direction per iteration
      	    if(rand() % 2)
                particle->x += deltax;
            else 
                particle->y += deltay;
        }
};

#include "ParticlesNoSDAG.def.h"
