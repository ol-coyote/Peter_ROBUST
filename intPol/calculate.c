/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/

#include <math.h>
#include <stdlib.h>

#include "interpolObj.h"
#include "utility.h"

void interpolate(struct Interpolation_Object* table, double r, double* f, double* df);
/* tighe prototype code */
void compare(struct Graph_Node *head){

  double rel_sine_err = 0.0, rel_cos_err = 0.0;
  double abs_cos_err = 0.0, abs_sine_err = 0.0;
  double angle = 0.0, interpol_cos = 0.0, interpol_sine = 0.0;

  for(struct Graph_Node *temp = head; ; temp=temp->next){
    angle = temp->x;
    rel_cos_err = cos(angle); // these values are already generated
    rel_sine_err = sin(angle); // these values are already generated shouldn't PI be part of the sine and cos functions?
    // interpolate(table, angle, &interpol_cos, &interpol_sine); //where is table passed as an argument?
    abs_cos_err = max(abs_cos_err,abs(interpol_cos - rel_cos_err));
  }
}
/* Prototype code */
void interpolate_proto(struct Interpolation_Object_Proto* test, double r, double* f, double* df) {
  //const double* tt = test->values; // alias
   const struct Graph_Node* tt = test->values; // alias

   if ( r < test->x0 ){ r = test->x0;}

   r = (r-test->x0)*(test->invDx);
   
   int ii;
   ii = (int)floor((int)r);

   if (ii > test->n) {
     ii = test->n;
     r = test->n / test->invDx;
   }
   
   r = r - floor(r); // reset r to fractional distance

   double g1 = tt[ii+1].value - tt[ii-1].value;
   double g2 = tt[ii+2].value - tt[ii].value;

   *f = tt[ii].value + 0.5*r*(g1 + r*(tt[ii+1].value + tt[ii-1].value - 2.0*tt[ii].value) );
   *df = 0.5*(g1 + r*(g2-g1))*test->invDx;

}


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

void interpolate(struct Interpolation_Object* table, double r, double* f, double* df) {
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
