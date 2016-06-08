#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "sinTest.h"
#define MAX_ELEM 10000
#define INCRM 0.036
#define VERBOSE 0
#define BT 1
void interpolate(struct InterpolationObject* table, double r, double* f, double* df);

int main(void){
  double x = 0.0; // Temporary value of x to run through sine function            
  int i;
  double sinValues [MAX_ELEM];
  //initialization of struct pointers                                             
  struct SineInterPolateObj *first = NULL;
  struct SineInterPolateObj *curr = NULL;
  struct SineInterPolateObj *last = NULL;

  for(i=0;i < MAX_ELEM;i++){
    curr = (struct SineInterPolateObj *) malloc(sizeof(struct SineInterPolateObj ));
    if (first == NULL){
      first = curr;
      if (VERBOSE) fprintf(stderr,"First element in linked list\n");
    }
    if (last != NULL){
      last->next = curr;
    }
    curr->value = sin(x); // insert sin value into node for linked list
    //if (VERBOSE) fprintf(stderr,"value of node: %f\n",curr->value);
    curr->next = NULL; // set next to null
    last=curr;
    sinValues[i]=sin(x); // insert values into table array
    x+=INCRM;
    //if (VERBOSE) printf("value of i: %d\n",i);
  }
  if(VERBOSE) fprintf(stderr, "Table array and linked list compilation complete.\n");
  if(BT){
    i=0;
    curr = first;
    while (curr !=NULL){
      fprintf(stderr,"Node value: %f i:%d \n",curr->value, i++);
      last=curr;
      curr=curr->next;
      free(last);
    }
  }
  return 0;
}


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


