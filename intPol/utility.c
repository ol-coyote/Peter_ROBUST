#include <math.h>
#include <stdlib.h>
#include "interpolObj.h"
#include "utility.h"

void setCOS_Val(struct Graph_Node *first, struct Graph_Node *curr, struct Graph_Node *last, double *sinValues, double *xvals){
   
  int i;
  double x = -1.0; // Temporary value of x to run through sine function        
  
  for(i=0;x < 1;i++){
    
    // Dynamic allocation of each node
    curr = (struct Graph_Node *) malloc(sizeof(struct Graph_Node));
    
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

void getSineVal(struct Graph_Node **first, struct Graph_Node *curr, struct Graph_Node *last, double *values){
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


double getRandNum(double minN, double maxN){ return (double) rand()/RAND_MAX * (maxN - minN) + minN; }
double getXVal_N(double r){ return (double)(r*((2*M_PI)/MAX_ELEM)-M_PI); }


