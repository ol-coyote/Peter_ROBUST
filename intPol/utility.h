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

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

void set_array_cos_val(void *v, void *xv);
void set_link_list_cos_val(void *f, void *c, void *l);/* Prototype code */
void set_st_array_cos_val(void *graph_v);
void set_array_sin_val(void *v, void *xv);
void set_link_list_sin_val(void *f, void *c, void *l);/* Prototype code */
void set_st_array_sin_val(void *graph_v); 
double get_rand_num(double min_num, double max_num);
double get_x_val_n(double entry);

#endif
