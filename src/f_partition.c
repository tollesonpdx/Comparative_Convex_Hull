// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_partition.c

#include "headers.h"

int partition(pt** P, int low, int high, int* ops)
    {
    double pivot = P[high]->theta;
    int i = low-1;

    for (int j = low; j < high; j++)
        {
        if (P[j]->theta <= pivot)
            {
            i++;
            pt_swap(P[i],P[j]);
            ops++;
            }
        }
    pt_swap(P[i+1], P[high]);
    ops++;
    return (i + 1);
    }
