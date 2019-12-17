// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_polar.c

#include "headers.h"

double polar(pt* p, pt* q)
    {
    double px = p->x;
    double py = p->y;
    double qx = q->x;
    double qy = q->y;
    double xdiff = qx-px;
    double ydiff = qy-py;
    double xsqr = (xdiff * xdiff);
    double ysqr = (ydiff * ydiff);
    double sroot = sqrt(xsqr + ysqr);
    if (sroot < 0) { sroot *= -1; }
    double radangs = atan2(ydiff,xdiff);
    q->theta = radangs;
    q->radius = sroot;
    return radangs;
    }
