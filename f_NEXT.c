// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_NEXT.c

#include "headers.h"

pt* NEXT(stack* S)
    {
    pt* current = S->top;
    current = current->below;
    return current;
    }
