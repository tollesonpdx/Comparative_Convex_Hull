// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: headers.h

#ifndef __HEADERS_H_
#define __HEADERS_H_

// included libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#include "structs.h"

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)


//// function prototypes ////
struct pt** getpts(char * filename, int * num, int print);

int brute(pt** P, int num, int* h, int print);
int jarvis(pt** P, int num, struct stack* S, int print);
int graham(pt** P, int num, struct stack* S, int print);
int chan(pt** P, int num, struct stack* S, int print);

char* returnCurrentDateTime();
int printpoint(pt* p);
double ccw(pt * p, pt * q, pt * r);
double polar(pt* p, pt* q);
int pt_swap(pt* p, pt* q);
void quicksort(pt** P, int low, int high, int* ops);
int partition(pt** P, int low, int high, int* ops);
struct stack* make_stack();
int push(stack* S, pt* point);
int printstack(stack* S);
pt* pop(stack* S);
pt* NEXT(stack* S);
pt* TOP(stack* S);
int copypoint(pt* from, pt* to);

#endif 
