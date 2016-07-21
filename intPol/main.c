#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "calculate.h"
#include "interpolObj.h"
#include "utility.h"


int main(void){

  int i;
  double graphValues [MAX_ELEM];
  double *xval;
  struct Graph_Node *first, *curr, *last;
  xval = (double *)malloc(MAX_ELEM*sizeof(double*));
  double totalTime=0.0;
  //initialization of struct pointers                                             
  first = NULL;
  curr = NULL;
  last = NULL;
  struct timespec start, stop;
  struct InterpolationObject *test = (struct InterpolationObject *) malloc (sizeof(struct InterpolationObject *));
  
 
  setCOS_Val(&first, &curr, &last,graphValues,xval);

  test->n=MAX_ELEM;
  test->x0=X_LOW;
  test->invDx=INVDX;
  test->values = graphValues;

  int rVal;
  double complete, s;
  double *df, *f;
  
  f=(double *)malloc(sizeof(double *));
  df=(double *)malloc(sizeof(double *));
  complete = 0.5; // how long the kernel should run
  
  for(; totalTime < complete ;){ // run while totatTime is less than complete time

    s=getRandNum(1,10000); //generate a random number
    rVal=(int)floor(s); // grab floor value
    
    clock_gettime(CLOCK_REALTIME, &start); // start the timer
    interpolate(test, xval[rVal], f,df);
    
    clock_gettime(CLOCK_REALTIME, &stop);
    totalTime += ((double)(stop.tv_sec - start.tv_sec)) + ((double)(stop.tv_nsec - start.tv_nsec)) / BIL;
  }

  
  while (curr !=NULL){
      last=curr;
      curr=curr->next;
      free(last);
  }
  return 0;
}


/*
this code was used to iterate through the linked list, so I removed it to reinstate it later once the array code is working. 
  
  if(BT1){ // code to iterate and test if linked list is compilated correctly.
    fprintf(stderr,"IN LINKED LIST\n");
    i=0;
    curr = first;
    
    while (curr !=NULL){
      if (BT1) fprintf(stderr,"Node value: %f i:%d \n",curr->value, i++);
      last=curr;
      curr=curr->next;
      free(last);
      if (VERBOSE) fprintf(stderr,"last freed\n");
    }
  }
*/


/* The rest of this crap is in random code hell. I just dont want to type this again... So it sits in the 2nd dimension of hell.  Possibly for eternity. 

  if(BT){ // JUST FOR TIMING PURPOSES
    printf(" TIME: %f\n",totalTime);
    printf("\n");
    fprintf(stderr, "Start time: %lf\n",start);
    printf("\n");
    fprintf(stderr, "Total time: %lf\n",totalTime);
    printf("\n");
    fprintf(stderr, "Stop time: %lf\n",stop);
    printf("\n");
    printf("test\n");
    fprintf(stderr," \n");
  }

    printf("\n");
    printf("***** Starting interpolate ******\n");
    printf("random value generated: %f\n",s);
    printf("test->table[%d]: %f\nxval: %f\n",rVal,test->values[rVal],xval[rVal] );
    printf("~~~~~ Interpolate complete ~~~~~\n");
    printf("\n");

    if(BT1){
    for(i=0;i<MAX_ELEM;i++){
      printf("i: %d ARRAY cos(x*PI): %f\n",i,test->values[i]);
      printf("i: %d ARRAY x*PI: %f\n",i,xval[i]);
    } 
  }
  fprintf(stderr, "Num of objects:%d\nStarting ordinate range: %f\ninverse table spacing: %f\n",test->n,test->x0, test->invDx);

 */
