// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_graham.c

#include "headers.h"

int graham(pt ** P, int num, struct stack* S, int print)
    {
    //print = 0;

    int ops = 0;
    int l = 0;


    //if (print) { printf("if less than 3 points, all points on hull\n"); }
    if (num < 4)
        {
        for (int i = 0; i < num; i++)
            {
            push(S, P[i]);
            ops++;
            }
        if (print)
            {
            printf("Printing vertexes of hull:\n");
            printstack(S);
            printf("total operations = %d\n",ops);
            }
        return ops;
        }
        

    //if (print) {printf("finding lowest y-coord, using x-coord to break tie\n");}
    for (int i = 0; i < num; i++)
        {
        ops++;
        if ( (P[i]->y < P[l]->y) || (P[i]->y == P[l]->y && P[i]->x < P[l]->x) )
            { l = i; }
        }



    //if (print) { printf("calculating polar angle from l\n"); }
    ops++;
    P[l]->theta = 0;
    P[l]->radius = 0;
    for (int i = 0; i < num; i++)
        {
        ops++;
        if (i != l)
            { polar(P[l],P[i]); }
        }



    //if (print) { printf("sorting points by polar angle from l\n"); }
    //if (print){for(int i=0; i<num; i++) {printf("%f ",P[i]->theta);} printf("\n");}
    pt_swap(P[0],P[l]);
    ops++;
    //if (print){for(int i=0; i<num; i++) {printf("%f ",P[i]->theta);} printf("\n");}
    //if (print) { printf("sorting\n"); }
    quicksort(P, 1, num-1, &ops);
    //if (print){for(int i=0; i<num; i++) {printf("%f ",P[i]->theta);} printf("\n");}



    if (print) { printf("\n\n---Graham scanning for convex hull---\n"); }
    push(S, P[0]);
    push(S, P[1]);
    push(S, P[2]);
    for (int i = 3; i < num; i++)
        {
        // 0 is on line, 1 is clockwise, 2 is counter-clockwise
        while (ccw(NEXT(S), TOP(S), P[i]) != 2)
            { 
            ops++;
            pop(S);
            }
        push(S, P[i]);
        ops++;
        }



    // print hull
    if (print)
        {
        printf("Printing vertexes of hull:\n");
        printstack(S);
        printf("total operations = %d\n",ops);
        }
    return ops;
    }
