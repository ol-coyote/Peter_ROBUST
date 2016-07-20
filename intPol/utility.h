#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void getCOS_Val(struct Graph_Node *first, struct Graph_Node *curr, struct Graph_Node *last, double *sinValues, double *xvals);
void getSineVal(struct Graph_Node **first, struct Graph_Node *curr, struct Graph_Node *last, double *values);
double getRandNum(double minN, double maxN);
double getXVal_N(double r);

#endif
