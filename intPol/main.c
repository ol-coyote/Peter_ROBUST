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

  int count, i, j, rVal;
  int *test_values; // used to temporarly store random values for computations
  double run_time, s, total_time;
  double *df, *f;
  double graph_values[MAX_ELEM], x_val[MAX_ELEM];
  struct Interpolation_Object *test;
  struct Interpolation_Object_Proto *g_test; /* Prototype code */
  struct Graph_Node *first=NULL;
  struct Graph_Node  *current =NULL;
  struct Graph_Node  *last =NULL;
  struct Graph_Node  *g_unit=NULL;
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

  
  double temp, x;
  x = -1.0; // Temporary value of x to run through sine function        
  
  for(;x < 1;){

    temp = x * M_PI; // assigning x * PI value

    // Dynamic allocation of each node
    current = (struct Graph_Node *) malloc(sizeof(struct Graph_Node));
    
    if (first == NULL)
      first = current;
    if (last != NULL)
      last->next = current;
    
    current->value = cos(temp); // insert sin value into node for linked lis
    current->x = temp;
    
    current->next = NULL; // set next to null
    last=current; // set last to current
    
    x+=0.0002; // increment value of x
  }  
  while (current != NULL){
    printf("current->x: %f current->values: %f\n",current->x,current->value);
    last = current;
    current =current->next;
    free(last);
  }
  return 0;
}


