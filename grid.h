#ifndef GRID_H
#define GRID_H
#include<vector>

class Grid
{

// n_x, n_y = total number of intervals
// h_x, h_y = node spacing in x and y
    


public:

double n_x,n_y,h_x,h_y;

///u approximation vector
std::vector<double> vec; 

///Constructor Declarations
Grid(int size_x,int size_y);
double& operator ()(int x, int y);


};

#endif