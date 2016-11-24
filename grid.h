#ifndefine GRID_H
#define GRID_H
class Grid
{

// n_x, n_y = total number of intervals
// h_x, h_y = node spacing in x and y
    
double n_x,n_y,h_x,h_y;
  

public:

///@brief Constructor Declarations
Grid(int size_x,int size_y);

std::vector<double> u_app;

double get(int i,int j);

/// To access private data menbers ///


};



#endif