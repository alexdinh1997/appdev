// this file contains screen functions. They are used to d$
// sound levels on a PUTTY screen as a bar chart
#include<stdio.h>
#include "screen.h"

void barChart(int db[]){
        int;
        for(int i=0;i<COL;i++){
                for(int j=0;j<db[i]/3;j++){
                        printf("\033[%d;%dH",j+1,i+1);
                        printf("%s",BAR);
                }
        }
}
void clearScreen(void){
        printf("\033[2J");
        fflush(stdout); // for remote terminal (such as PU$
}

void setColors(short bg, short fg){
        printf("\033[%d;%d;1m",bg,fg);
        fflush(stdout);
}

void resetColors(void){
        printf("\033[0m");
        fflush(stdout);
}
