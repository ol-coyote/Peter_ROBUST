/*
  
  author: Peter Estrada 
  email: pestrada2@miners.utep.edu

*/
extern struct Graph_Node *head;
extern struct Interpolation_Object* table;
extern struct Interpolation_Object_Proto* test; /* Prototype code */
#ifndef CALCULATE_H
#define CALCULATE_H
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

void compare(struct Graph_Node *head);
void interpolate(struct Interpolation_Object* table, double r, double* f, double* df);
void interpolate_proto(struct Interpolation_Object_Proto* test, double r, double* f, double* df); /* Prototype code */
#endif
