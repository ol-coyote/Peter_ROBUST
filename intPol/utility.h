/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern struct Interpolation_Object* table;
extern struct Graph_Node *first;

#ifndef UTILITY_H
#define UTILITY_H

#define BIL 1E9
#define HALF_SEC 0.5
#define INCR (RANGE/MAX_ELEM)
#define INV_DX (1/(INCR*M_PI))
#define MAX_ELEM 10000
#define RANGE 2.0
#define START 1
#define X_DIST 0.036
#define X_LOW -1*M_PI
#define X_HI 1*M_PI
#define VERBOSE 0

void set_cos_val_proto(void *fir, void *cur, void *las, void *graph_v); /* Prototype code */
void set_cos_val(void  *f, void *c, void *l, void *v, void *xv);
void get_sin_val(struct Graph_Node *first, struct Graph_Node *curr, struct Graph_Node *last, double *values);
double get_rand_num(double min_num, double max_num);
double get_x_val_n(double entry);

#endif
