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
  int *test_values; // used to temporarly store random values for computations
  double run_time, s, total_time;
  double *df, *f;
  double graph_values[MAX_ELEM], x_val[MAX_ELEM];
  struct Interpolation_Object *test;
  struct Interpolation_Object_Proto *g_test; /* Prototype code */
  struct Graph_Node *first, *current, *last, *g_unit;
  struct timespec start, stop;
  
  count = 0; //used to count how many times calculation ran
  run_time = (argc > START)? atof(argv[1]) : HALF_SEC; // used to compute how long the kernel should run
  i=0;
  test_values=(int *)malloc(MAX_ELEM*sizeof(int));
  total_time=0.0; // used to hold value of current runtime
  g_unit = (struct Graph_Node *)malloc(MAX_ELEM * sizeof(struct Graph_Node)); /* Prototype code */
  g_test = (struct Interpolation_Object_Proto *) malloc (sizeof(struct Interpolation_Object_Proto ));
  test = (struct Interpolation_Object *) malloc (sizeof(struct Interpolation_Object ));
  first = NULL, current = NULL, last = NULL;
  
  set_cos_val_proto(&first,&current, &last, g_unit); /* Prototype code */
  set_cos_val(&first, &current, &last,graph_values,x_val); // setting up table and nodes with values

  // Initializing InterpolObj struct
  test->n=MAX_ELEM;
  test->x0=X_LOW;
  test->invDx=INV_DX;
  test->values = graph_values;

  /* Prototype code */
  g_test->n=MAX_ELEM;
  g_test->x0=X_LOW;
  g_test->invDx=INV_DX;
  g_test->values = g_unit;
  /* 
     FYI: The timer is off right now. I dont have an exact value, but at 25s it took approximately 28s to complete. I think I have a way to fix/test it, but I'd much rather eat tacos right now. 
   */
  while(i++ < MAX_ELEM) test_values[i] = (int) floor (get_rand_num(START, MAX_ELEM)); // generate random values for computation purposes

  for(; total_time < run_time; count++){ // run while totatTime is less than run_time time

    i=0;
    
    f = (double *) malloc (sizeof(double ));
    df = (double *) malloc (sizeof(double ));

    clock_gettime(CLOCK_REALTIME, &start); // start the timer
    
    while(i++ < MAX_ELEM){
      interpolate(test, x_val[test_values[i]], f, df); // run calculation
      interpolate_proto(g_test, x_val[test_values[i]], f, df); /* Prototype code */
    }
    
    clock_gettime(CLOCK_REALTIME, &stop);// stop the timer.
    total_time += ((double)(stop.tv_sec - start.tv_sec)) + ((double)(stop.tv_nsec - start.tv_nsec)) / BIL; // calculate current runtime

    free(f); // free function result pointer
    free(df);// free derivative function result pointer

  }

  printf("Calculations ran: %d times for at %f seconds\n", count*MAX_ELEM, total_time);

  /* Repeat after me: I AM FREE! */
  while (current != NULL){
      last = current;
      current = current->next;
      free(last);
  }
  free(first);
  free(current);
  free(g_unit);
  free(g_test);
  free(test);
  free(test_values);
 
  return 0;
}

