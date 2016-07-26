/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/

#include <math.h>
#include <stdlib.h>

#include "interpolObj.h"
#include "utility.h"

double get_pi_value(double value);

void set_array_cos_val( void *v, void *xv){
  
  double *graph_values = (double *)v;
  double *x_values = (double *)xv;
  int i;
  double temp, x;
  x = -1.0; // Temporary value of x to run through sine function        
  
  for(i=0;x < 1;i++){

    temp = get_pi_value(x); // assigning x * PI value
    
    x_values[i]=temp;
    graph_values[i]=cos(temp); // insert values into table array
    
    x+=INCR; // increment value of x
  }  
}

void set_link_list_cos_val(void *f, void *c, void *l){

  struct Graph_Node *first = (struct Graph_Node*)f;
  struct Graph_Node *current = (struct Graph_Node*)c;
  struct Graph_Node *last = (struct Graph_Node*)l;

  int i;
  double temp, x;
  x = -1.0; // Temporary value of x to run through sine function        
  
  for(i=0;x < 1;i++){

    temp = get_pi_value(x); // assigning x * PI value

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
    
    x+=INCR; // increment value of x
  }  
}

/* Prototype code
   Function sets the cosine values and corresponding x values in a struct.
   Accepts a single pointer as an input and doesn't return anything at this time
*/
void set_st_array_cos_val(void *graph_v){
  
  struct Graph_Node *gUnit = (struct Graph_Node*)graph_v;
  
  int i;
  double temp, x;
  x = -1.0; // Temporary value of x to run through graph setting

  for(i=0;x < 1;i++){
    
    temp = get_pi_value(x); // assigning x * PI value

    gUnit[i].x = temp; // set x value for corresponding cosine value
    gUnit[i].value = cos(temp); // set struct cosine value
  
    x+=INCR; // increment value of x
  }  
}

void get_sin_val(struct Graph_Node *first, struct Graph_Node *curr, struct Graph_Node *last, double *values){
  int i;
  double x = -1.0; // Temporary value of x to run through sine function        

  for(i=0;x < 1;i++){
    
    // Dynamic allocation of each node
    curr = (struct Graph_Node *) malloc(sizeof(struct Graph_Node));
    
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

double get_pi_value(double value){ return value * M_PI; }
double get_rand_num(double min_num, double max_num){ return (double) rand()/RAND_MAX * (max_num - min_num) + min_num; }
double get_x_val_number(double entry){ return (double)(entry*((2*M_PI)/MAX_ELEM)-M_PI); } /* Function that returns the x coordinate to check accuracy of cosine table */


