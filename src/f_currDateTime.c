// Chad Tolleson Copywrite (c) 2019
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: f_currDateTime.c


// attribution: https://en.wikipedia.org/wiki/C_date_and_time_functions

// attribution: https://stackoverflow.com/questions/3673226/how-to-print-time-in-format-2009-08-10-181754-811 USER paxdiablo

#include "headers.h"

char* returnCurrentDateTime()
    {
    time_t current_time;
    time(&current_time);
    struct tm* tm_info = localtime(&current_time);
    char* timebuffer = calloc(27, sizeof(char));
    strftime(timebuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    //printf("%s\n",timebuffer);
    return timebuffer;
    }
