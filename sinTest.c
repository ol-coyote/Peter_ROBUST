#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "sinTest.h"
#define MAX_ELEM 10000
#define INCRM 0.036
#define VERBOSE 1
#define BT 0
void interpolate(struct InterpolationObject* table, double r, double* f, double* df);
void makeTable(void *first, void *curr, void *last, double value);
int main(void){
  double x = 0.0; // Temporary value of x to run through sine function            
  int i;
  double sinValues [MAX_ELEM];
  //initialization of struct pointers                                             
  struct SineInterPolateObj *first = NULL;
  struct SineInterPolateObj *curr = NULL;
  struct SineInterPolateObj *last = NULL;
  void *fptr = &first;
  void *cptr = &curr;
  void *lptr = &last;
  for(i=0;i < MAX_ELEM;i++){
    // Dynamic allocation of each node
    
    makeTable(fptr, cptr, lptr, sin(x));

    sinValues[i]=sin(x); // insert values into table array
    x+=INCRM; // increment value of x
  }

  if(VERBOSE){ // code to iterate and test if linked list is compilated correctly. 
    if (VERBOSE) fprintf(stderr,"TEST LIST");
    i=0;
    curr = first;
    while (curr !=NULL){
      if (VERBOSE) fprintf(stderr,"Node value: %f i:%d \n",curr->value, i++);
      last=curr;
      curr=curr->next;
      free(last);
      if (VERBOSE) fprintf(stderr,"last free'd\n");
    }
  }
  return 0;
}

void makeTable(void *first, void *curr, void *last, double value){
  struct SineInterPolateObj *fptr = (struct SineInterPolateObj *) first;
  struct SineInterPolateObj *cptr = (struct SineInterPolateObj *) curr;
  struct SineInterPolateObj *lptr = (struct SineInterPolateObj *) last;
  curr = (struct SineInterPolateObj *) malloc(sizeof(struct SineInterPolateObj)); 

  if (fptr == NULL)
    fptr = cptr;
  if (lptr != NULL)
    lptr->next = cptr;

  cptr->value = value; // insert sin value into node for linked list
  cptr->next = NULL; // set next to null
  lptr=cptr; // set last to current
}




