/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/

extern struct InterpolationObject* table;
extern struct InterpolationObjectProto* test; /* Prototype code */
#ifndef CALCULATE_H
#define CALCULATE_H


void interpolate(struct InterpolationObject* table, double r, double* f, double* df);
void interpolate_proto(struct InterpolationObjectProto* test, double r, double* f, double* df); /* Prototype code */
#endif
