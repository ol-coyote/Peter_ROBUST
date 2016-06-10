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
   double *values; //!< the abscissa values                                       
} ;

void interpolate(struct InterpolationObject* table, double r, double* f, double* df) {
   const double* tt = &table->values; // alias                                     

   if ( r < table->x0 ) r = table->x0;

   r = (r-table->x0)*(table->invDx) ;
   int ii = (int)floor(r);

   if (ii > table->n) {
      ii = table->n;
      r = table->n / table->invDx;
   }

   r = r - floor(r); // reset r to fractional distance                            
   double g1 = tt[ii+1] - tt[ii-1];

   double g2 = tt[ii+2] - tt[ii];
   *f = tt[ii] + 0.5*r*(g1 + r*(tt[ii+1] + tt[ii-1] - 2.0*tt[ii]) );
   *df = 0.5*(g1 + r*(g2-g1))*table->invDx;
}