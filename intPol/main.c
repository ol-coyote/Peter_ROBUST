#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "calculate.h"
#include "interpolObj.h"
#include "utility.h"


int main(int argc, char **argv){

  int count, i, rVal;
  double complete, s, totalTime;
  double *df, *f;
  double graphValues[MAX_ELEM];
  double xval[MAX_ELEM];
  struct InterpolationObject *test;
  struct Graph_Node *first, *curr, *last;
  struct timespec start, stop;

  count = 0; //used to count how many times calculation ran
  complete = (argc > 1)? atof(argv[1]) : 0.5; // used to compute how long the kernel should run
  totalTime=0.0; // used to hold value of current runtime
  test = (struct InterpolationObject *) malloc (sizeof(struct InterpolationObject *));
  first = NULL;
  curr = NULL;
  last = NULL;
   
  setCOS_Val(&first, &curr, &last,graphValues,xval); // setting up table and nodes with values

  // Initializing InterpolObj struct
  test->n=MAX_ELEM;
  test->x0=X_LOW;
  test->invDx=INVDX;
  test->values = graphValues;

  /* 
     FYI: The timer is off right now. I dont have an exact value, but at 25s it took approximately 28s to complete. I think I have a way to fix/test it, but I'd much rather eat tacos right now. 
   */
  for(; totalTime < complete; count++){ // run while totatTime is less than complete time
    clock_gettime(CLOCK_REALTIME, &start); // start the timer
    
    f=(double *)malloc(sizeof(double *));
    df=(double *)malloc(sizeof(double *));
    
    s=getRandNum(1,10000); //generate a random number
    rVal=(int)floor(s); // grab floor value of random number
    
    interpolate(test, xval[rVal], f,df); // run calculation
    
    free(f); // free function result pointer
    free(df);// free derv. function result pointer

    clock_gettime(CLOCK_REALTIME, &stop);// stop the timer.
    totalTime += ((double)(stop.tv_sec - start.tv_sec)) + ((double)(stop.tv_nsec - start.tv_nsec)) / BIL; // calculate current runtime
    
  }
  printf("Calculations ran: %d times for at %f seconds\n",count,totalTime);
  // free linked list
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


   if(BT){
     fprintf(stderr,"f(x): %f\n",f);
     fprintf(stderr,"df(x): %df\n",df);
   }

   if(BT){
     printf("g1:%f = tt[%d]:%f - tt[%d]:%f\n",g1,ii+1,tt[ii+1],ii-1,tt[ii-1]);
     printf("g2:%f = tt[%d]:%f - tt[%d]:%f\n",g2,ii+2,tt[ii+2],ii,tt[ii]);
   }

   printf("r reset to fractional dist: %f\n",r - floor(r));
   if(BT){
     fprintf(stderr,"After bounds checking\n");
     fprintf(stderr,"r: %f\n",r);
     fprintf(stderr,"ii: %d\n",ii);
   }

   if(BT1) printf("intitial ii val: %d\n",ii);
   if(BT){
     fprintf(stderr,"r: %f\n",r);
     fprintf(stderr,"ii: %d\n",ii);
   }
   printf("r= (r-table->x0)*(table->invDx): %f\n",(r-table->x0)*(table->invDx));
   
   
   if(BT) fprintf(stderr, "r passed in: %f \n",r);

   if(BT) printf("r < table->x0 : %s\n",(r < table->x0)?"true":"false");
 */
