# Chad Tolleson Copyright (c) 2019
# CS584 - Spring 2019
# Final Project - Convex Hull
# filename: makefile

CC = gcc

CFLAGS = -O3

OBJS = convexHull.o f_getpts.o f_printpoint.o f_ccw.o \
        f_brute.o f_jarvis.o f_graham.o f_chan.o f_currDateTime.o \
        f_polar.o f_pt_swap.o f_quicksort.o f_partition.o \
        f_makestack.o f_push.o f_printstack.o f_pop.o f_NEXT.o f_TOP.o \
        f_copypoint.o

all: convex

convex: $(OBJS)
	$(CC) -o convex $(OBJS) -lm

.c.o:
	$(CC) $(CFLAGS) -g -Wall -c $<

clean:
	rm -f convex *.o core
