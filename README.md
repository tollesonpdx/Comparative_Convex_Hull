# Convex Hull Algorithm Comparison

This program is designed to compare the efficiency in operations and time of four algorithms solving the Convex Hull problem. A summary of the execution and comparison of performance results are located [HERE](report/CS584_Project_Tolleson_v8.pdf).

The program runs each of the four algorithms:
1) Brute Force, 
2) Graham's Scan,
3) Jarvis's March, and
4) Chan's Algorithm 

on the eight data sets contained within the **data** folder. The programs' results are stored in a text file in the **results** folder. Additional datasets can be created using the genpoints program within the **data** folder. The genpoints program will need to be edited to specificy the file name, and then the new dataset must be manually added into the main function, which is contained in the _convexHull.c_ file. Run 'make' to generate the executable file. PLEASE NOTE that this program may need to be adjusted to run on your machine due to the large amount of memory intentionally utilized.


### Files:

**data** -- folder containing sample data sets

**report** -- folder containing report summarizing process and results

**results** -- folder containing text files with detail and summary results of the program

* makefile -- run 'make' to compile the executable file

* headers.h -- header file containing library include statements, function prototypes, and includes for any other h files

* structs.h -- h file containing structure definitions

* convexHull.c -- contains main function that runs each Convex Hull algorithm on each data set

* f_brute.c -- contains the Brute Force algorithm

* f_ccw.c -- contains the function determining if an angle between three points is clockwise or counterclockwise

* f_chan.c -- contains Chan's Algorithm

* f_copypoint.c -- contains function to copy contents of one point struct into another

* f_currDateTime.c -- contains function that produces the current date and time, formatted

* f_getpts.c -- contains function that opens a data file and reads contents into an array of points

* f_graham.c -- contains Graham's Scan algorithm

* f_jarvis.c -- contains Jarvis's March algorithm

* f_makestack.c -- contains function to declare and establish a stack structure

* f_NEXT.c -- contains function that looks at the node second from the top in a stack

* f_partition.c -- contains partitioning algorithm for quicksort implementation

* f_polar.c -- contains function to calculate the polar angle and distance between two points

* f_pop.c -- contains function to pop the top node off of a stack

* f_printpoint.c -- contains function to print all the data in a point structure

* f_printstack.c -- contains function to print the count and all nodes in a stack

* f_pt_swap.c -- contains function to swap two points structures

* f_push.c -- contains function to push a point node onto a stack

* f_quicksort.c -- contains function to quicksort an array of points in place

* f_TOP.c -- contains function to look at the top node on a stack