#include <vector>
#include <iostream>
#include "Timer.h"
#include <sstream>
#include "grid.h"
#include <math.h>
#include <omp.h>

#define pi 3.1415926535897932

void solver(Grid &u,Grid &f,int c){

  int n_x = u.n_x;
  int n_y = u.n_y;
  int ngp_x = n_x+1;
  int ngp_y = n_y+1;
  
  //Grid res(n_x,n_y);
  double numer = ((n_x*n_x)*0.5 + (n_y*n_y)*2 + (4*pi*pi));  
  double denom = 1/numer;           // 1/(2/h_x*h_x  + 2/h_y*h_y + k*k)
  siwir::Timer timer;
  double time1 = 100.0;
  double time2 = 100.0;
  int x=1, y=1;
  timer.reset();
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
  time1 = std::min(time1, timer.elapsed());

  timer.reset();
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
    time2 = std::min(time2, timer.elapsed());
    
    std::cout << "Norm is " << norm << std::endl;
    std::cout << "Time for rbgs " << time1 << " sec" << std::endl;
    std::cout << "Time for residual " << time2*1e6 << " milli-sec" << std::endl;`LL
}

