#ifndef GRID_H
#define GRID_H
#include<vector>

class Grid
{

// n_x, n_y = total number of intervals
// h_x, h_y = node spacing in x and y
    
double n_x,n_y,h_x,h_y;
std::vector<double> u_app; 

public:

///Constructor Declarations
Grid(int size_x,int size_y);

///u approximation vector


double get(int i,int j);

};

#endif
