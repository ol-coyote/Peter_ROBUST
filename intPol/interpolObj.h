/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/

#ifndef INTERPOLOBJ_H

/* Node for storing graph values. */
struct Graph_Node{
  double value;
  double x;
  struct Graph_Node *next;
};

/* 
Interpolation must be supported on the range
f$[x_0, x_n]\f$, where \f$x_n = n*dx\f$.


param [in] n    number of values in the table.
param [in] x0   minimum ordinate value of the table.
param [in] dx   spacing of the ordinate values. {1.0/dx};
param [in] data abscissa values.  An array of size n. 
*/
struct Interpolation_Object{
   int n;          //!< the number of values in the table                       
   double x0;      //!< the starting ordinate range                             
   double invDx;   //!< the inverse of the table spacing                        
   double *values; //!< the abscissa values values=               
};

/* Prototype code */
struct Interpolation_Object_Proto{
   int n;          //!< the number of values in the table                       
   double x0;      //!< the starting ordinate range                             
   double invDx;   //!< the inverse of the table spacing                        
   struct Graph_Node *values; //!< the abscissa values values=               
};


#endif
