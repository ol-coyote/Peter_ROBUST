#include <math.h>
#include <stdlib.h>
#ifndef SINTEST_H
#define SINTEST_H
#define MAX_ELEM 10000
#define INCRM 0.036
#define VERBOSE 0
#define BT 1
#define BT1 0
#define RANGE 2.0
#define X_LOW -1*M_PI
#define X_HI 1*M_PI
#define INCR (RANGE/MAX_ELEM)
#define INVDX (1/(INCR*M_PI))

/* Node for sin table linked list. */
struct SineInterPolateObj{
  double value;
  struct SineInterPolateObj *next;
};


/* 
Interpolation must be supported on the range
f$[x_0, x_n]\f$, where \f$x_n = n*dx\f$.


param [in] n    number of values in the table.
param [in] x0   minimum ordinate value of the table.
param [in] dx   spacing of the ordinate values. {1.0/dx};
param [in] data abscissa values.  An array of size n. 
*/
struct InterpolationObject{
   int n;          //!< the number of values in the table                       
   double x0;      //!< the starting ordinate range                             
   double invDx;   //!< the inverse of the table spacing                        
   double *values; //!< the abscissa values values=               
};

double getXVal_N(double r){
  return (double)(r*((2*M_PI)/MAX_ELEM)-M_PI);
}


void setCOSINE(struct SineInterPolateObj *first, struct SineInterPolateObj *curr, struct SineInterPolateObj *last, double *sinValues, double *xvals){
   
  int i;
  double x = -1.0; // Temporary value of x to run through sine function        
  
  for(i=0;x < 1;i++){
    
    // Dynamic allocation of each node
    curr = (struct SineInterPolateObj *) malloc(sizeof(struct SineInterPolateObj));
    
    if (first == NULL)
      first = curr;
    if (last != NULL)
      last->next = curr;

    curr->value = cos(x * M_PI); // insert sin value into node for linked list
    curr->next = NULL; // set next to null
    last=curr; // set last to current
    
    sinValues[i]=cos(x * M_PI); // insert values into table array
    xvals[i]=x*M_PI;
    x+=INCR; // increment value of x
  }
  
}


void setSineVal(struct SineInterPolateObj **first, struct SineInterPolateObj *curr, struct SineInterPolateObj *last, double *values){
  int i;
  double x = -1.0; // Temporary value of x to run through sine function        

  for(i=0;x < 1;i++){
    
    // Dynamic allocation of each node
    curr = (struct SineInterPolateObj *) malloc(sizeof(struct SineInterPolateObj));
    
    if (first == NULL)
      first = curr;
    if (last != NULL)
      last->next = curr;

    curr->value = sin(x * M_PI); // insert sin value into node for linked list
    curr->next = NULL; // set next to null
    last=curr; // set last to current

    values[i]=sin(x * M_PI); // insert values into table array
    x+=INCR; // increment value of x
  }
  
}

void interpolate(struct InterpolationObject* table, double r, double* f, double* df) {
   const double* tt = table->values; // alias
   
   if(BT) fprintf(stderr, "r passed in: %f \n",r);

   if(BT) printf("r < table->x0 : %s\n",(r < table->x0)?"true":"false");
   if ( r < table->x0 ){ r = table->x0;}

   r = (r-table->x0)*(table->invDx);
   printf("r= (r-table->x0)*(table->invDx): %f\n",(r-table->x0)*(table->invDx));
   
   int ii;
   ii = (int)floor((int)r);
   if(BT1) printf("intitial ii val: %d\n",ii);
   if(BT){
     fprintf(stderr,"r: %f\n",r);
     fprintf(stderr,"ii: %d\n",ii);
   }
   if (ii > table->n) {
     ii = table->n;
     r = table->n / table->invDx;
   }
   
   r = r - floor(r); // reset r to fractional distance
   printf("r reset to fractional dist: %f\n",r - floor(r));
   if(BT){
     fprintf(stderr,"After bounds checking\n");
     fprintf(stderr,"r: %f\n",r);
     fprintf(stderr,"ii: %d\n",ii);
   }
   
   double g1 = tt[ii+1] - tt[ii-1];
   double g2 = tt[ii+2] - tt[ii];

   if(BT){
     printf("g1:%f = tt[%d]:%f - tt[%d]:%f\n",g1,ii+1,tt[ii+1],ii-1,tt[ii-1]);
     printf("g2:%f = tt[%d]:%f - tt[%d]:%f\n",g2,ii+2,tt[ii+2],ii,tt[ii]);
   }
   *f = tt[ii] + 0.5*r*(g1 + r*(tt[ii+1] + tt[ii-1] - 2.0*tt[ii]) );
   *df = 0.5*(g1 + r*(g2-g1))*table->invDx;
   if(BT){
     fprintf(stderr,"f(x): %f\n",f);
     fprintf(stderr,"df(x): %df\n",df);
   }
}

double setRandNum(double minN, double maxN){
  return (double) rand()/RAND_MAX * (maxN - minN) + minN;
}

#endif
