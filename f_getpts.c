// Chad Tolleson
// CS584 - Spring 2019
// filename: f_getpts.c

#include "headers.h"

struct pt ** getpts(char * filename, int * num, int print)
    {
    print = 0;

    FILE * f1 = fopen(filename,"r");
    int n = 0;

    fscanf(f1,"%d",&n);
    struct pt** array = malloc(n * sizeof(pt*));

    for (int i=0; i<n; i++)
        {
        double x;
        double y;
        array[i] = malloc(sizeof(pt));
        fscanf(f1, "%lf %lf", &x, &y);
		array[i]->x = x;
        array[i]->y = y;
        array[i]->index = i;
        if (print) { printf("point %d = %lf, %lf\n",
                        array[i]->index,array[i]->x,array[i]->y); }
        }
    
    fclose(f1);
    *num = n;
    return array;
    }
