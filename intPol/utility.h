#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern struct InterpolationObject* table;
extern struct Graph_Node *first;
#ifndef UTILITY_H
#define UTILITY_H

#define BIL 1E9
#define BT 0
#define BT1 0
#define INCR (RANGE/MAX_ELEM)
#define INVDX (1/(INCR*M_PI))
#define MAX_ELEM 10000
#define RANGE 2.0
#define X_DIST 0.036
#define X_LOW -1*M_PI
#define X_HI 1*M_PI
#define VERBOSE 0

void setCOS_Val(void  *f, void *c, void *l, void *v, void *xv);
void setCOS_Val_proto(void *fir, void *cur, void *las, void *graph_v);
void setSineVal(struct Graph_Node **first, struct Graph_Node *curr, struct Graph_Node *last, double *values);
double getRandNum(double minN, double maxN);
double getXVal_N(double r);

#endif
