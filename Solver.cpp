#ifndef SOLVER
#define SOLVER

Solver(Grid &u,vector<double> &f),int c){

  n_x = u.n_x;
  n_y = u.n_y;
  ngp_x = n_x+1;
  ngp_y = n_y+1;
  
  for(unsigned int i=0; i<c; ++i)
  
    
  //Red update
  for(int x=1; x < (n_x+1), ++x)
    for(int y=1; y<(n_y+1), ++y)
      A.u(x,y) = 
  //Black Update
 for(int x=1; x < (n_x+1), ++x)
    for(int y=1; y<(n_y+1), ++y)
      A.get
  //Residual

  
}

#endif