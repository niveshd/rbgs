#include <vector>
#include <iostream>
#include "Timer.h"
#include <sstream>

#define pi 3.1415926535897932

int main(int argc, char *argv[]){
  
  std::stringstream str;
  
  str << argv[1] << " " << argv[2] <<" " << argv[3];
  int n_x=0, n_y=0, c=0;
  
  str >> n_x >> n_y >> c;  
  std::cout << "No of Arguments " << argc << std::endl;
  std::cout << "n_x = " << n_x << ", n_y = " << n_y << ", iterations = " << c << std::endl;
  
  
  
//grid object
  //vector of all node values

  //operator(i,j) to access values. write a get function as well. eg. A.get(i,j) returning data vector
    //A.get(i,j) = data(j*n_x + i)
  //data members: n_x, n_y
  //data members: h_x = 2/n_x, h_y = 1/n_y;
    //n_x and n_y and no. of intervals. no. of grid points then is n_x+1 and n_y+1
  
  //constructor (size_x, size y)
    //data vector (n_x+1)*(n_y+1)
  
  //need get_f function which evaluates right handside
    //A.get_f(i,j) = 4*pi*pi*sin(2*pi*h_x*i)*sinh(2*pi*j*h_y)

  
  
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