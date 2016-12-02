#include <vector>
#include <iostream>
#include "Timer.h"
#include <sstream>
#include "grid.h"
#include <math.h>
#include <omp.h>

#define pi 3.1415926535897932

void solver(Grid &u,Grid &f,int c){
  
  extern int print_only_time;

  int n_x = u.n_x;
  int n_y = u.n_y;
  int ngp_x = n_x+1;
  int ngp_y = n_y+1;
  
  //Grid res(n_x,n_y);
  double numer = ((n_x*n_x)*0.5 + (n_y*n_y)*2 + (4*pi*pi));  
  double denom = 1.0/numer;           // 1/(2/h_x*h_x  + 2/h_y*h_y + k*k)
  siwir::Timer timer;
  double time = 100.0;
  int x=1, y=1;
  
  //only solver to be timed
  timer.reset();
  
  //solver part
  for(int i=0; i<c; ++i){
    //Black update
    #pragma omp parallel for private(x)
    for(y=1; y <= ngp_y-2 ;y=y+2)
        for(x=1; x<= ngp_x-2; x=x+2)
	   u(x,y) = denom*(f(x,y)+ ((n_x*n_x*0.25) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1))));
    #pragma omp parallel for private(x)
    for(y=2; y <= ngp_y-2 ;y=y+2)
        for(x=2; x<= ngp_x-2; x=x+2)
	   u(x,y) = denom*(f(x,y)+ ((n_x*n_x*0.25) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1))));
  //Red Update
    #pragma omp parallel for private(x)
    for(y=1; y <= ngp_y-2 ;y=y+2)
        for(x=2; x<= ngp_x-2; x=x+2)
	   u(x,y) = denom*(f(x,y)+ ((n_x*n_x*0.25) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1))));
    #pragma omp parallel for private(x)
    for(y=2; y <= ngp_y-2 ;y=y+2)
        for(x=1; x<= ngp_x-2; x=x+2)
	   u(x,y) = denom*(f(x,y)+ ((n_x*n_x*0.25) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1))));
  }
  
  time = std::min(time, timer.elapsed());
  //end of timing

  //Residual
    double sum =0;
    double res_i_j =0;
    double norm =0;
    //loop over all interior points ngp_x-2 * ngp_y-2
    #pragma omp parallel for private(res_i_j,x) reduction(+:sum)
    for(y=1; y <= ngp_y-2 ; ++y){
        for(x=1; x <= ngp_x-2 ; ++x){
            res_i_j = (f(x,y)+ ((n_x*n_x*0.25) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1)) - (numer*u(x,y))));
            sum+= (res_i_j*res_i_j);
        }
    }
    sum = sum / ((ngp_x-2)*(ngp_y-2));
    norm = sqrt(sum);
    
    if (print_only_time){
    std::cout << "Grid_size " << n_x << " " << n_y << std::endl;
    std::cout << "Iterations " << c << std::endl;
    std::cout << "Time " << time << std::endl;
    std::cout << "Residual_Norm " << norm << std::endl;
    }
    else
      std::cout << time << " ";
    
}

