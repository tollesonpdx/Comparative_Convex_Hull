// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_pt_swap.c

#include "headers.h"

int pt_swap(pt* p, pt* q)
    {
    pt temp;
    temp = *p;
    *p = *q;
    *q = temp;
    return 1;
    }
