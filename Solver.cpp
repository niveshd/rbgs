#include <vector>
#include <iostream>
#include "Timer.h"
#include <sstream>
#include "grid.h"
#include <math.h>
#include <omp.h>

#define pi 3.1415926535897932

void solver(Grid &u,Grid &f,int c){

  n_x = u.n_x;
  n_y = u.n_y;
  ngp_x = n_x+1;
  ngp_y = n_y+1;
  
  
  double denom = 1 / ((n_x*n_x)*0.5 + (n_y*n_y)*2 + (4*pi*pi));  // 1/(2/h_x*h_x  + 2/h_y*h_y + k*k)
  
  
  for(unsigned int i=0; i<c; ++i)
  
    
  //Red update
  for(unsigned int x=1; x < ngp_x-2 , ++x)
    for(unsigned int y=1; y< ngp_y-2, ++y)
      u(x,y) = denom*(f(x,y)+ ((n_x*n_x) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1)));
  //Black Update
 for(int x=1; x < (n_x+1), ++x)
    for(int y=1; y<(n_y+1), ++y)
      A.get
  //Residual

  
}

