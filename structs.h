// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: structs.h

#ifndef __STRUCTS_H_
#define __STRUCTS_H_

typedef struct pt
    {
    int index;
    double x;
    double y;
    double theta;
    double radius;
    struct pt* below;
    struct pt* above;
    } pt;

typedef struct stack
    {
    struct pt* bottom;
    struct pt* top;
    int count;
    } stack;

#endif 
