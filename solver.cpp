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
  int p=0; int q=0; 
  Grid res(n_x,n_y);
  double numer = ((n_x*n_x)*0.5 + (n_y*n_y)*2 + (4*pi*pi));  
  double denom = 1/numer;           // 1/(2/h_x*h_x  + 2/h_y*h_y + k*k)
  
  for(int i=0; i<c; ++i){
    //Red update
    for(int y=1; y < ngp_x-2 ; ++y){
        if (y%2==0){
        p = 2;
        q = ngp_x-1;
                    }
        else{
          p=1;
          q= ngp_x-3;
            } 
        for(int x=p; x< q; x=x+2)
            u(x,y) = denom*(f(x,y)+ ((n_x*n_x) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1))));
      }
  //Black Update
    for(int y=1; y < ngp_x-2 ; ++y){
        if (y%2!=0){
        p = 2;
        q = ngp_x-1;
                    }
        else{
          p=1;
          q= ngp_x-3;
            } 
        for(int x=p; x< q; x=x+2)
            u(x,y) = denom*(f(x,y)+ ((n_x*n_x) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1))));
        }
  }
  
  //Residual
    double sum =0;
    double res_i_j =0;
    double norm =0;
    for(int y=1; y < ngp_x-2 ; ++y){
        for(int x=1; x < ngp_x-2 ; ++x){
            res_i_j = (f(x,y)+ ((n_x*n_x) * (u(x-1,y)+u(x+1,y))) +  ((n_y*n_y) * (u(x,y-1)+u(x,y+1)) - (numer*u(x,y))));
            sum+= res_i_j*res_i_j;
        }
    }
    norm = sqrt(sum/((ngp_x-2) * (ngp_y-2)));
    
    std::cout << "Norm is " << norm << std::endl;  
}

