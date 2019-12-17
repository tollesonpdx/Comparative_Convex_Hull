// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_makestack.c

#include "headers.h"

struct stack* make_stack()
    {
    stack* S = malloc(sizeof(stack*));
    S->bottom = NULL;
    S->top = NULL;
    S->count = 0;
    return S;
    }
