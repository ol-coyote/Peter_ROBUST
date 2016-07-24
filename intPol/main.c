/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "calculate.h"
#include "interpolObj.h"
#include "utility.h"


int main(int argc, char **argv){

  int count, i, rVal;
  double complete, s, total_time;
  double *df, *f;
  double graph_values[MAX_ELEM], x_val[MAX_ELEM];
  struct InterpolationObject *test;
  struct InterpolationObjectProto *g_test; /* Prototype code */
  struct Graph_Node *first, *current, *last, *g_unit;
  struct timespec start, stop;

  count = 0; //used to count how many times calculation ran
  complete = (argc > 1)? atof(argv[1]) : 0.5; // used to compute how long the kernel should run
  total_time=0.0; // used to hold value of current runtime
  g_unit = (struct Graph_Node *)malloc(MAX_ELEM * sizeof(struct Graph_Node)); /* Prototype code */
  g_test = (struct InterpolationObjectProto *) malloc (sizeof(struct InterpolationObjectProto ));
  test = (struct InterpolationObject *) malloc (sizeof(struct InterpolationObject ));
  first = NULL, current = NULL, last = NULL;
  
  setCOS_Val_proto(&first,&current, &last, g_unit); /* Prototype code */
  setCOS_Val(&first, &current, &last,graph_values,x_val); // setting up table and nodes with values

  // Initializing InterpolObj struct
  test->n=MAX_ELEM;
  test->x0=X_LOW;
  test->invDx=INVDX;
  test->values = graph_values;

  /* Prototype code */
  g_test->n=MAX_ELEM;
  g_test->x0=X_LOW;
  g_test->invDx=INVDX;
  g_test->values = g_unit;
  /* 
     FYI: The timer is off right now. I dont have an exact value, but at 25s it took approximately 28s to complete. I think I have a way to fix/test it, but I'd much rather eat tacos right now. 
   */
  for(; total_time < complete; count++){ // run while totatTime is less than complete time
    clock_gettime(CLOCK_REALTIME, &start); // start the timer
    
    f=(double *) malloc (sizeof(double *));
    df=(double *) malloc (sizeof(double *));
    
    s=getRandNum(1,10000); //generate a random number
    rVal=(int)floor(s); // grab floor value of random number
    
    interpolate(test, x_val[rVal], f,df); // run calculation
    interpolate_proto(g_test, x_val[rVal], f,df); /* Prototype code */
    
    free(f); // free function result pointer
    free(df);// free derv. function result pointer

    clock_gettime(CLOCK_REALTIME, &stop);// stop the timer.
    total_time += ((double)(stop.tv_sec - start.tv_sec)) + ((double)(stop.tv_nsec - start.tv_nsec)) / BIL; // calculate current runtime
    
  }
  printf("Calculations ran: %d times for at %f seconds\n", count, total_time);

  // free pointers
  while (current !=NULL){
      last=current;
      current=current->next;
      free(last);
  }
  free(first);
  free(current);
  free(g_unit);
  free(g_test);
  free(test);

  return 0;
}

