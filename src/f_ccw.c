// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_ccw.c

#include "headers.h"

double ccw(pt * p, pt * q, pt * r)
    {
    double px = p->x;
    double py = p->y;
    double qx = q->x;
    double qy = q->y;
    double rx = r->x;
    double ry = r->y;
    double val = (qy-py)*(rx-px)-(qx-px)*(ry-py);
    
    if (val == 0)
        { return 0; }
    else if (val > 0)
        { return 1; }
    else
        { return 2; }
    // 0 is on line, 1 is clockwise, 2 is counter-clockwise
    }
