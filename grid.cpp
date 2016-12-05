#include"grid.h"
#include<iostream>


Grid::Grid(int size_x,int size_y): n_x(size_x),n_y(size_y)
{
    h_x = 2/n_x;
    h_y = 1/n_y;
    int n=(n_x+1)*(n_y+1);
    vec = new double[n];
    for (int i=0; i!=(n_x+1)*(n_y+1); ++i)
      vec[i]=0;
} 

double& Grid::operator ()(int x, int y){
  return vec[(int)(y*(n_x+1) + x)];
}