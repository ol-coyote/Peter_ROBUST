#include <math.h>
#include <stdlib.h>

#include "interpolObj.h"
#include "utility.h"


/// Interpolate a table to determine f(r) and its derivative f'(r).
///
/// The forces on the particle are much more sensitive to the derivative
/// of the potential than on the potential itself.  It is therefore
/// absolutely essential that the interpolated derivatives are smooth
/// and continuous.  This function uses simple quadratic interpolation
/// to find f(r).  Since quadric interpolants don't have smooth
/// derivatives, f'(r) is computed using a 4 point finite difference
/// stencil.
///
/// Interpolation is used heavily by the EAM force routine so this
/// function is a potential performance hot spot.  Feel free to
/// reimplement this function (and initInterpolationObject if necessay)
/// with any higher performing implementation of interpolation, as long
/// as the alternate implmentation that has the required smoothness
/// properties.  Cubic splines are one common alternate choice.
///
/// \param [in] table Interpolation table.
/// \param [in] r Point where function value is needed.
/// \param [out] f The interpolated value of f(r).
/// \param [out] df The interpolated value of df(r)/dr.

void interpolate(struct InterpolationObject* table, double r, double* f, double* df) {
   const double* tt = table->values; // alias

   if ( r < table->x0 ){ r = table->x0;}

   r = (r-table->x0)*(table->invDx);
   
   int ii;
   ii = (int)floor((int)r);

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
