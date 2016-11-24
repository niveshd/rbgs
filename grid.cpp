#include"grid.h"


Grid::Grid(int size_x,int size_y): n_x(size_x),n_y(size_y)
{
    h_x = 2/n_x;
    h_y = 1/n_y;
    frc.resize((n_x+1)*(n_y+1));
    uapp.resize((n_x+1)*(n_y+1));
    res.resize((n_x+1)*(n_y+1));
} 

Grid::double get(int i,int j){
    return (j*n_x + i);
}