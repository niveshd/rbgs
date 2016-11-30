#include <vector>
#include <iostream>
#include "Timer.h"
#include <sstream>
#include "grid.h"
#include <math.h>
#include "misc.h"

#define pi 3.1415926535897932

void solver(Grid &, Grid &, int);

int main(int argc, char *argv[]){
  
  std::stringstream str;
  
  str << argv[1] << " " << argv[2] <<" " << argv[3];
  int n_x=0, n_y=0, c=0;
  
  str >> n_x >> n_y >> c;  
  std::cout << "No of Arguments " << argc << std::endl;
  //std::cout << "n_x = " << n_x << ", n_y = " << n_y << ", iterations = " << c << std::endl;
  
  Grid u(n_x,n_y);
  Grid f(n_x,n_y);
  
  
  
  
//setboundaryconditions function
  set_boundary(u); 
  set_rhs(f);
  
//RBGS
  //set timer
  
  solver(u,f,c);
  
//write grid
  write(u, "solution1.txt");
  //write(f,"force.txt");

}

