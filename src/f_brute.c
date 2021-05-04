// Chad Tolleson
// CS584 - Spring 2019
// filename: f_brute.c

#include "headers.h"

int brute(pt ** P, int num, int* h, int print)
    {
    //print = 0;
    int hullct = 0;
    int ops = 0;
    //if(print) { printf("creating tables\n"); }
    double * x = calloc(num, sizeof(double));
    double * y = calloc(num, sizeof(double));
    int * next = calloc(num, sizeof(int));

    //if(print) { printf("transferring array of pts\n"); }
    for (int i = 0; i < num; i++)
        {
        x[i] = P[i]->x;
        y[i] = P[i]->y;
        next[i] = -1;
        }

    if (print) { printf("\n\n---Brutishly finding convex hull---\n"); }
    for (int i = 0; i < num-1; i++)
        {
        for (int j = i+1; j < num; j++)
            {
            int lesser = 0;
            int greater = 0;
            int on = 0;
            double a = y[j]-y[i];
            double b = x[i]-x[j];
            double c = (x[i] * y[j]) - (y[i] * x[j]);
            for (int k = 0; k < num; k++)
                {
                if ( (k != i) && (k != j) )
                    {
                    ops++;
                    double test = (a*x[k])+(b*y[k])-c;
                    if (test < 0)
                        { lesser++; }
                    if (test > 0)
                        { greater++; }
                    if (test == 0)
                        { on++; }
                    }
                }
            if ( ((lesser==0 && greater!=0) || (greater==0 && lesser!=0)) )
                {
                //if (print) { printf("found an edge on hull: %d and %d\n",i,j); }
                next[i]=j;
                next[j]=i;
                hullct++;
                }
            }
        }
    
    // print hull
    if (print)
        {
        printf("Printing edges of hull:\n");
        for (int i = 0; i < num; i++)
            { 
            if (next[i] != -1)
                {
                printf("%d to %d, ",i, next[i]);
                }
            }
        printf("\n");
        printf("total operations = %d\n",ops); 
        }

    //if (print) { printf("freeing allocated memory\n"); }
    free(x);
    free(y);
    free(next);

    *h = hullct;
    return ops;
    }


