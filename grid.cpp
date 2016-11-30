#include"grid.h"
#include<iostream>


Grid::Grid(int size_x,int size_y): n_x(size_x),n_y(size_y)
{
    h_x = 2/n_x;
    h_y = 1/n_y;
    std::cout<< h_x << " " << h_y << std::endl;
    int size = (n_x+1)*(n_y+1);
    int black_size = size*0.5;
    int red_size = size - black_size;
    red.resize(red_size,0);
    black.resize(black_size,0);
} 

double& Grid::operator ()(int x, int y){
  global=x+y*(n_x+1);
  if (global&1)
    return red[(global-1)*0.5];
  else
    return black[global*0.5];
}