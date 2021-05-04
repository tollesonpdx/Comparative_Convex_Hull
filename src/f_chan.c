// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_chan.c

#include "headers.h"

int chan(pt ** P, int num, struct stack* S, int print)
    {
    //print = 0;

    int ops = 0;
    int l = 0;
    
    
    //if (print) {printf("\n\nfinding lowest y-coord, using x-coord to break tie\n");}
    for (int i = 0; i < num; i++)
        {
        ops++;
        if ( (P[i]->y < P[l]->y) || (P[i]->y == P[l]->y && P[i]->x < P[l]->x) )
            { l = i; }
        }



    if (print) { printf("\n\n---Channing---\n"); }
    int m = min(256,num); //initial number of splits in the points
    int start = 0;
    int finish = m;
    
    do
        {
        struct pt** P2 = malloc(m * sizeof(pt*));
        //if (print) { printf("copying batch from P to P2\n"); }
        for (int i = 0; i < m; i++)
            {
            P2[i] = malloc(sizeof(pt));
            copypoint(P[start+i],P2[i]);
            //if (print) { printpoint(P2[i]); }
            ops++;
            }
        
        if (print) { printf("-still Channing, calling Graham function\n"); }
        ops += graham(P2, m, S, 0); //last parameter, print = 0 
        if (P2) { free(P2); } 
        start = finish;
        finish = min((finish + m),num);
        m = min(m,(finish-start));
        //if (print) { printf("done updating start, finish, and m\n"); }
        }   while (start != finish);
    
    int scount = S->count;
    struct pt** P3 = malloc(scount * sizeof(pt*));
    for (int i = 0; i < scount; i++)
        {
        P3[i] = malloc(sizeof(pt));
        P3[i] = pop(S);
        //if (print) { printpoint(P3[i]); }
        ops++;
        }
    
    if (print) { printf("-still Channing, calling Jarvis function\n"); }
    ops += jarvis(P3, scount, S, 0); //last paramter, print = 0


    // print hull
    if (print)
        {
        printf("Printing vertexes of hull:\n");
        printstack(S);
        printf("total operations = %d\n",ops);
        }
    return ops;
    }
