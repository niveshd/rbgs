#include "grid.h"
#define pi 3.1415926535897932
#include <math.h>
#include <fstream>
#include <vector>

void set_boundary(Grid &u){
  int i=0,j=u.n_y;;
  //loop over y= n_y (ngp_y-1)
  for (i=0; i != (u.n_x)+1; ++i){
    //set u
    u(i,j)=sin(2*pi*i*u.h_x)*sinh(2*pi);
    //std::cout<< i*u.h_x << " " << u.n_y << " " << u(i,j) << std::endl;
  }      
}

void set_rhs(Grid &f){
 int i=0,j=0;
  for (j=0; j != f.n_y+1; ++j)
     for(i=0; i!= f.n_x+1; ++i)
        {    
        f(i,j)=4*pi*pi*sin(2*pi*i*f.h_x)*sinh(2*pi*j*f.h_y);
        }   
}

void write(Grid &u,std::string output_file){
int i=0,j=0;
 //initialize output_file
 std::ofstream file(output_file);
 //loop over j ... n_y
 for (j=0; j != u.n_y+1; ++j){
    //loop over i ... n_x
    for (i=0; i != u.n_x+1; ++i)
    {    
      //print x y value
     file << i*u.h_x << " " << j*u.h_y << " " << u(i,j) << std::endl;     
    }         
 } 
 file.close();
}