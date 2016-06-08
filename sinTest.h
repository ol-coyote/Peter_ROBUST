struct SineInterPolateObj{
  double value;
  struct SineInterPolateObj *next;
};


/// Handles interpolation of tabular data.
///
/// \see initInterpolationObject
/// \see interpolate

struct InterpolationObject{
   int n;          //!< the number of values in the table                         
   double x0;      //!< the starting ordinate range                               
   double invDx;   //!< the inverse of the table spacing                          
   double values; //!< the abscissa values                                       
} ;