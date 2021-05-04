// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_quicksort.c

#include "headers.h"

void quicksort(pt** P, int low, int high, int* ops)
    {
    if (low < high)
        {
        int party = partition(P, low, high, ops);
        quicksort(P, low, party-1, ops);
        quicksort(P, party+1, high, ops);
        }
    return;
    }
