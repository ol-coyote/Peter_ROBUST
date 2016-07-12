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
  double totalTime;
  //initialization of struct pointers                                             
  struct SineInterPolateObj *first = NULL;
  struct SineInterPolateObj *curr = NULL;
  struct SineInterPolateObj *last = NULL;
  struct timespec start, stop;

  clock_gettime(CLOCK_REALTIME, &start);
  
  setCOSINE(first, curr, last, sinValues);
  clock_gettime(CLOCK_REALTIME, &stop);
  totalTime = ((stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec)) / BIL;
  printf("\n");
  fprintf(stderr, "Start time: %lf\n",start);
  printf("\n");
  fprintf(stderr, "Total time: %lf\n",totalTime);
  printf("\n");
  fprintf(stderr, "Start time: %lf\n",stop);
  printf("\n");

  if(BT){ // code to iterate and test if linked list is compilated correctly. 
    i=0;
    curr = first;
    while (curr !=NULL){
      if (BT) fprintf(stderr,"Node value: %f i:%d \n",curr->value, i++);
      last=curr;
      curr=curr->next;
      free(last);
      if (BT) fprintf(stderr,"last free'd\n");
    }
  }

  return 0;
}
