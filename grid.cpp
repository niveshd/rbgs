#include"grid.h"


Grid::Grid(int size_x,int size_y): n_x(size_x),n_y(size_y)
{
    h_x = 2/n_x;
    h_y = 1/n_y;
    uapp((n_x+1)*(n_y+1),0);
} 

Grid::double get(int i,int j){
    return u_app[(j*n_x + i)];
}