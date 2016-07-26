/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/

#include <math.h>
#include <stdlib.h>

#include "interpolObj.h"
#include "utility.h"

/* Prototype code */
void set_cos_val_proto(void *fir, void *cur, void *las, void *graph_v){
  struct Graph_Node *first = (struct Graph_Node*)fir;
  struct Graph_Node *current = (struct Graph_Node*)cur;
  struct Graph_Node *last = (struct Graph_Node*)las;
  struct Graph_Node *gUnit = (struct Graph_Node*)graph_v;/* Prototype code */

  int i;
  double x = -1.0; // Temporary value of x to run through sine function        
  
  for(i=0;x < 1;i++){
    
    // Dynamic allocation of each node
    current = (struct Graph_Node *) malloc(sizeof(struct Graph_Node));
    
    if (first == NULL)
      first = current;
    if (last != NULL)
      last->next = current;

    current->value = cos(x * M_PI); // insert sin value into node for linked list
    current->next = NULL; // set next to null
    last=current; // set last to current
    
    gUnit[i].x = x * M_PI; /* Prototype code */
    gUnit[i].value = cos(x * M_PI); /* Prototype code */

    x+=INCR; // increment value of x
  }  
}

void set_cos_val(void *f, void *c, void *l, void *v, void *xv){
  struct Graph_Node *first = (struct Graph_Node*)f;
  struct Graph_Node *current = (struct Graph_Node*)c;
  struct Graph_Node *last = (struct Graph_Node*)l;
  double *graph_values = (double *)v;
  double *x_values = (double *)xv;
  int i;
  double x = -1.0; // Temporary value of x to run through sine function        
  
  for(i=0;x < 1;i++){
    
    // Dynamic allocation of each node
    current = (struct Graph_Node *) malloc(sizeof(struct Graph_Node));
    
    if (first == NULL)
      first = current;
    if (last != NULL)
      last->next = current;

    current->value = cos(x * M_PI); // insert sin value into node for linked list
    current->next = NULL; // set next to null
    last=current; // set last to current
    
    graph_values[i]=cos(x * M_PI); // insert values into table array
    x_values[i]=x*M_PI;
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


double get_rand_num(double min_num, double max_num){ return (double) rand()/RAND_MAX * (max_num - min_num) + min_num; }
double get_x_val_number(double entry){ return (double)(entry*((2*M_PI)/MAX_ELEM)-M_PI); } /* Function that returns the x coordinate to check accuracy of cosine table */


