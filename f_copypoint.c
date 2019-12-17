// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_copypoint.c

#include "headers.h"

int copypoint(pt* from, pt* to)
    {
    to->index = from->index;
    to->x = from->x;
    to->y = from->y;
    //to->theta = from->theta;
    //to->radius = from->radius;
    //to->below = from->below;
    //to->above = from->above;
    return 1;
    }
