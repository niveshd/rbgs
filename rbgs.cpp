#include <vector>
#include <iostream>
#define pi 3.1415926535897932
#include "Timer.h"
#include <sstream>

int main(int argc, char *argv[]){
  
  std::stringstream str;
  
  str << argv[1] << " " << argv[2] <<" " << argv[3];
  int n_x=0, n_y=0, c=0;
  
  str >> n_x >> n_y >> c;  
  std::cout << "No of Arguments " << argc << std::endl;
  std::cout << "n_x = " << n_x << ", n_y = " << n_y << ", iterations = " << c << std::endl;
  
//grid object
  //vector of all node values
  //constructor (size_x, size y)
    //vector (size_x*size_y)
  //operator(i,j) to access values
  //data members: size_x, size_y -> h_x = 2/(size_x-1), h_y = 1/(size_y-1);
  //
  
//define pi
//define f = 4*pi*pi*sin(2*pi*h_x*i
//)*sinh(2*pi*j*h_y)
  
//
  
//setboundaryconditions function
   //set non zero dirichlet
   //loop over y=1 boundary
      //set to sin(2*pi*h_x*i)*sinh(2*pi*j*h_y)
  
//RBGS
  //loop over red
    //calculate u based on neighbours
    //need stencil values
  
  //loop over black
    
  
//calculate error norm
  //loop over inner points

}