#include <stdlib.h>
#include <stdio.h>
#include "../lib/shared.h"


void nextfibsum(int * total, int * current, int * previous);

int main(int argc, char** argv){
    int * total = malloc(sizeof(int));
    int * current = malloc(sizeof(int));
    int * previous = malloc(sizeof(int));
    *current = 1;
    *previous = 0;
    *total = 0;
    while(*current < 4000000){
        nextfibsum(total,current,previous);
    }
    printf("Problem 2 solution:\n%d\n",*total);
}

void nextfibsum(int * total, int * current, int * previous){
    if(*current % 2 == 0){
        *total += *current;
    }
    int temp = *current;

     *current = *current + *previous;
     *previous = temp;
}
