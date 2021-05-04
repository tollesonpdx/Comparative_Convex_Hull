// Chad Tolleson
// CS584 - Spring 2019
// Final Project - Convex Hull
// filename: convexHull.c

#include "headers.h"

int main()
    {
    int print = 0;
    int num = -1;
    
    char* datafiles[8];
    datafiles[0]="./data/data_00000016pts.txt";
    datafiles[1]="./data/data_00001000pts.txt";
    datafiles[2]="./data/data_00001000pts_forJarvisCircle.txt";
    datafiles[3]="./data/data_00010000pts.txt";
    datafiles[4]="./data/data_00100000pts.txt";
    datafiles[5]="./data/data_01000000pts.txt";
    datafiles[6]="./data/data_10000000pts.txt";
    datafiles[7]="./data/data_10000003pts_ForJarvis.txt";
   
    FILE* results = fopen("./results/results_summary.txt","a+");
    fprintf(results,"\n\n\n\nlog entry:\t");
    char* t = returnCurrentDateTime();
    fprintf(results, "%s\nfile|log_type|brute|jarvis|graham|chan\n",t);
    if (t) free(t);

    for (int i = 0; i < 8; i++)
        {
       
        int jstop = 1;
        clock_t t;

        // brute force
        struct pt** P = getpts(datafiles[i], &num, print);
        int br = 0;
        int br_h = 0;
        t=clock();
        if (num < 10000)
            {
            for (int j = 0; j < jstop ; j++)
                { br += brute(P, num, &br_h, print); }
            }
        t=clock()-t;
        double br_time = ((double)t)/CLOCKS_PER_SEC;
        if (P) { free(P); }

        // Graham's Scan
        P = getpts(datafiles[i], &num, print);
        int gr = 0;
        int gr_h = 0;
        t=clock();
        for (int j = 0; j < jstop ; j++)
            {
            stack* grH = make_stack();
            gr += graham(P, num, grH, print);
            gr_h = grH->count;
            if (grH) { free(grH); }
            }
        t=clock()-t;
        double gr_time = ((double)t)/CLOCKS_PER_SEC;
        if (P) { free(P); }

        // Jarvis's March
        P = getpts(datafiles[i], &num, print);
        int ja = 0;
        int ja_h = 0;
        t=clock();
        for (int j = 0; j < jstop ; j++)
            {
            stack* jaH = make_stack();
            ja += jarvis(P, num, jaH, print);
            ja_h = jaH->count;
            if (jaH) { free(jaH); }
            }
        t=clock()-t;
        double ja_time = ((double)t)/CLOCKS_PER_SEC;
        if (P) { free(P); }

        // Chan's Algorithm
        P = getpts(datafiles[i], &num, print);
        int ch = 0;
        int ch_h = 0;
        t=clock();
        for (int j = 0; j < jstop ; j++)
            {
            stack* chH = make_stack();
            ch += chan(P, num, chH, print);
            ch_h = chH->count;
            if (chH) { free(chH); }
            }
        t=clock()-t;
        double ch_time = ((double)t)/CLOCKS_PER_SEC;
        if (P) { free(P); }


        if (1)
            { 
            printf("\n\n");
            printf("data file: %s\t\n",datafiles[i]);
            printf("brute force: h = %d, ops = %d, secs = %f\n",br_h,br,br_time);
            printf("graham scan: h = %d, ops = %d, secs = %f\n",gr_h,gr,gr_time);
            printf("jarvis march: h = %d, ops = %d, secs = %f\n",ja_h,ja,ja_time);
            printf("chan algo: h = %d, ops = %d, secs = %f\n",ch_h,ch,ch_time);
            }

        fprintf(results, "%s|h|%d|%d|%d|%d\n",
                datafiles[i],br_h,gr_h,ja_h,ch_h);
        fprintf(results, "%s|ops|%d|%d|%d|%d\n",datafiles[i],br,gr,ja,ch);
        fprintf(results, "%s|time|%f|%f|%f|%f\n",
                datafiles[i],br_time,gr_time,ja_time,ch_time);

        }

    fclose(results); 
    printf("program complete\n");
    return 0;
    }
