#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "sinTest.h"
#include <time.h>
#define BIL 1E9


int main(void){

  int i;
  double sinValues [MAX_ELEM];
  double xval[MAX_ELEM];
  double totalTime=0.0;
  //initialization of struct pointers                                             
  struct SineInterPolateObj *first = NULL;
  struct SineInterPolateObj *curr = NULL;
  struct SineInterPolateObj *last = NULL;
  struct timespec start, stop;
  struct InterpolationObject *test = (struct InterpolationObject *) malloc (sizeof(struct InterpolationObject *));
  
 
  setCOSINE(&first, &curr, &last,sinValues,xval);
  
  if(BT){ // code to iterate and test if linked list is compilated correctly.
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
  test->n=MAX_ELEM;
  test->x0=X_LOW;
  test->invDx=INVDX;
  test->values = &sinValues;
  if(BT){
    for(i=0;i<MAX_ELEM;i++){
      printf("i: %d ARRAY cos(x*PI): %f\n",i,test->values[i]);
      printf("i: %d ARRAY x*PI: %f\n",i,xval[i]);
    }
    fprintf(stderr, "Num of objects:%d\nStarting ordinate range: %f\ninverse table spacing: %f\n",test->n,test->x0, test->invDx); 
  }
  

  double s;
  double *f;
  f=(double *)malloc(sizeof(double *));
  double *df;
  df=(double *)malloc(sizeof(double *));
  double complete = 0.5;
  int j,rVal;
  
  for(;totalTime < complete ; ){
    //fprintf(stderr,"j: %d\n",j);
    clock_gettime(CLOCK_REALTIME, &start);
    s=setRandNum(1,10000);
    rVal=(int)floor(s);
    if(BT){
      printf("\n");
      printf("***** Starting interpolate ******\n");
      printf("random value generated: %f\n",s);
      printf("test->table[%d]: %f\nxval: %f\n",rVal,test->values[rVal],xval[rVal] );
    }
    interpolate(test, xval[rVal], f,df);
    printf("~~~~~ Interpolate complete ~~~~~\n");
    printf("\n");
    
    clock_gettime(CLOCK_REALTIME, &stop);
    totalTime += ((double)(stop.tv_sec - start.tv_sec)) + ((double)(stop.tv_nsec - start.tv_nsec)) / BIL;
    // printf(" TIME: %f\n",totalTime);
  }
  if(BT){
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
  return 0;
}
