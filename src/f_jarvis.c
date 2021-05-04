// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_jarvis.c

#include "headers.h"

int jarvis(pt ** P, int num, struct stack* S, int print)
    {
    //print = 0;
    
    //const char* values[3];
    //values[0]="co-linear";
    //values[1]="clockwise";
    //values[2]="counter-clockwise";
   
    int ops = 0;

    //if (print) { printf("creating tables\n"); }
    double * x = calloc(num, sizeof(double));
    double * y = calloc(num, sizeof(double));
    int * next = calloc(num, sizeof(int));
    int * prev = calloc(num, sizeof(int));

    //if (print) { printf("transferring array of pts\n"); }
    for (int i = 0; i < num; i++)
        {
        x[i] = P[i]->x;
        y[i] = P[i]->y;
        next[i] = -1;
        prev[i] = -1;
        //if (print) { printf("%d %lf %lf\n",i,x[i],y[i]); }
        }

    int p = 0;
    int q = 0;
    int l = 0;


    //if (print) { printf("finding lowest x-coord value\n"); }
    for (int i = 0; i < num; i++)
        {
        ops++;
        if (x[i] < x[l])
            { l = i; }
        }
    p = l;
    


    if (print) { printf("\n\n---Jarvis marching along the hull---\n"); }
    do  {
        ops++;
        q = (p + 1) % num;
        for (int i = 0; i < num; i++)
            {
            ops++;
            //if (print) { printf("loop %d\n",i); }
            int ccwt = ccw(P[p],P[i],P[q]);
            //if (print) { printf("ccwt is %s\n",values[ccwt]); }
            if (p != i && ccwt==2)
                { q = i; }
            //if (print) { printf("l is % d, p is %d, q is %d\n",l,p,q); }
            }
        next[p] = q;
        prev[q] = p;
        p = q;
        //if (print) { printf("l is % d, p is %d, q is %d\n",l,p,q); }
        } while (p != l);

    
    for (int i = 0; i < num; i++)
        { 
        if (next[i] != -1)
            { push(S, P[i]); }
        }
 
    if (print)
        {
        printf("Printing edges of hull:\n");
        for (int i = 0; i < num; i++)
            { 
            if (next[i] != -1)
                { printf("%d to %d, ",i, next[i]); }
            }
        printf("\n");
        printstack(S);
        printf("total operations = %d\n",ops); 
        }

    //if (print) { printf("freeing allocated memory\n"); }
    free(x);
    free(y);
    free(next);
    free(prev);

    return ops;
    }

