#ifndef PARTICLE_H
#define PARTICLE_H
#include "sys/time.h"
// Get the current time
double get_time() {
  struct timeval tv;
  gettimeofday(&tv,0);
  return (tv.tv_sec*1.0+tv.tv_usec*1e-6);
}
/*
*Particle object with x&y coordinate components
*/

class Particle {
public:
    double x;
    double y;

    Particle() { }
    Particle(double a, double b) { 
      x=a; y=b; 
    }

    void pup(PUP::er &p){
      p|x;
      p|y;
    }
};

#endif
