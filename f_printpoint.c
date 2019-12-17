// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_printpoint.c

#include "headers.h"

int printpoint(pt* p)
    {
    printf("point index %d\t",p->index);
    printf("coords: %f, %f\t",p->x, p->y);
    printf("theta: %f,  radius: %f\n",p->theta, p->radius);
    return 1;
    }
