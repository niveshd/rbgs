#include <vector>
#include <iostream>
#include "Timer.h"
#include <sstream>
#include "grid.h"
#include <math.h>
#include "misc.h"

#define pi 3.1415926535897932
  
int print_only_time=1;

void solver(Grid &, Grid &, int);

int main(int argc, char *argv[]){
  

  if (argc==5)
    print_only_time=0;
  
  std::stringstream str;  
  int n_x=0, n_y=0, c=0;
  
  str << argv[1] << " " << argv[2] <<" " << argv[3];
  str >> n_x >> n_y >> c;  
  
//default initialization   
  Grid u(n_x,n_y);
  Grid f(n_x,n_y);  

//setboundaryconditions function
  set_boundary(u); 
  set_rhs(f);
  
//RBGS
  solver(u,f,c);
  
//write grid
  write(u, "solution.txt");

}

