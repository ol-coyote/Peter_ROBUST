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
  double totalTime=0.0;
  //initialization of struct pointers                                             
  struct SineInterPolateObj *first = NULL;
  struct SineInterPolateObj *curr = NULL;
  struct SineInterPolateObj *last = NULL;
  struct timespec start, stop;
  struct InterpolationObject *test = (struct InterpolationObject *) malloc (sizeof(struct InterpolationObject *));
  
 
  setSineVal(&first, &curr, &last,sinValues);
  
  if(BT){ // code to iterate and test if linked list is compilated correctly.
    fprintf(stderr,"IN LINKED LIST\n");
    i=0;
    curr = first;
    
    while (curr !=NULL){
      if (BT) fprintf(stderr,"Node value: %f i:%d \n",curr->value, i++);
      last=curr;
      curr=curr->next;
      free(last);
      if (VERBOSE) fprintf(stderr,"last freed\n");
    }
  }
  test->n=MAX_ELEM;
  test->x0=1;
  test->invDx=1/INCR;
  test->values = &sinValues;
  if(BT){
    for(i=0;i<MAX_ELEM;i++)
      printf("ARRAY X: %f\n",test->values[i]);
    fprintf(stderr, "Num of objects:%d, Starting ordinate range: %f, table spacing: %f\n",test->n,test->x0, test->invDx); 
  }
  

  double s;
  double *f;
  f=(double *)malloc(sizeof(double *));
  double *df;
  df=(double *)malloc(sizeof(double *));
  double complete= 0.5;
  int j;
  
  for(;totalTime < complete ; ){
    //fprintf(stderr,"j: %d\n",j);
    clock_gettime(CLOCK_REALTIME, &start);
    s=setRandNum(1,10000);
    interpolate(test, s, f,df);
    
    clock_gettime(CLOCK_REALTIME, &stop);
    totalTime += (((double)(stop.tv_sec - start.tv_sec)) + ((double)(stop.tv_nsec - start.tv_nsec))) / BIL;
    // printf(" TIME: %f\n",totalTime);
  }
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
  return 0;
}
