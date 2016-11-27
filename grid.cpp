#include"grid.h"
#include<iostream>


Grid::Grid(int size_x,int size_y): n_x(size_x),n_y(size_y)
{
    h_x = 2/n_x;
    h_y = 1/n_y;
    std::cout<< h_x << " " << h_y << std::endl;
    vec.resize((n_x+1)*(n_y+1),0);
} 

double& Grid::operator ()(int x, int y){
  return vec[y*(n_x+1) + x];
}