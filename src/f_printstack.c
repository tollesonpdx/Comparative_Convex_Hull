// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_printstack.c

#include "headers.h"

int printstack(stack* S)
    {
    printf("stack count = %d\n",S->count);
    pt* current = S->bottom;
    do
        {
        printpoint(current);
        current = current->above;
        } while (current != NULL);
    return S->count;
    }
