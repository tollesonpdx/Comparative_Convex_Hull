// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: genpoints.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

int main()
    {
    struct timeval randseed;
    gettimeofday(&randseed, NULL);
    srand(randseed.tv_usec);

    FILE* results = fopen("data_100000000pts.txt","w");
    int n = 100000000;
    fprintf(results,"%d\n",n);
    // please note that I use n as the number of desired
    // points and also the upper bound on the X and Y
    // axis, or the radius in the case of a circle of
    // points
    
/*  // points in a square area
    for (int i = 0; i < n; i++)
        {
        float x = rand()%n;
        float y = rand()%n;
        fprintf(results,"%f %f\n",x,y);
        }
*/

    // points on a circlei
    int centerx = 0;
    int centery = 0;
    float radius = 10000.0;
    float r2 = radius * radius;
    for (int i = 0; i < n; i++)
        {
        float xsign = (rand()%2 == 0) ? -1 : 1;
        int xmax = (1 * radius) +1;
        float x = (xsign) * ( rand()%(xmax) );
        float x2 = x * x;
        float ysign = (rand()%2 == 0) ? -1 : 1;
        float y = (ysign) * ( sqrt(r2 - x2) );
        //printf("%f %f\n",x,y);
        fprintf(results,"%f %f\n",x,y);
        }
    
    fclose(results);
    if (results) { free(results); }
    return 0;
    }
