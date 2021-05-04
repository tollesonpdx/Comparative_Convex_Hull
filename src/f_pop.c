// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_pop.c

#include "headers.h"

pt* pop(stack* S)
    {
    pt* current = S->top;
    if (S->top == S->bottom)
        {
        S->top = NULL;
        S->bottom = NULL;
        }
    else
        {
        pt* newtop = S->top->below;
        current->below = NULL;
        current->above = NULL;
        newtop->above = NULL;
        S->top = newtop;
        }
    S->count--;
    return current;
    }
