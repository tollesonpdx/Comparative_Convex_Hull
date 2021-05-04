// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_push.c

#include "headers.h"

int push(stack* S, pt* point)
    {
    if (S->bottom == NULL)
        {
        S->bottom = point;
        S->top = point;
        S->count = 1;
        }
    else
        {
        point->above = NULL;
        point->below = S->top;
        S->top->above = point;
        S->top = point;
        S->count++;
        }
    return S->count;
    }
