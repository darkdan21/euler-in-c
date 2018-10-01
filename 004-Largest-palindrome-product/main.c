#include <stdlib.h>
#include <stdio.h>
#include "../lib/shared.c"
#include <math.h>

int main(int argc, char** argv){
    printf("Problem: 4\n");
    long long total = 0;
    long long max = 0;
    for(long long i = 100; i<=999; i++){
        for(long long ii=100; ii<=999; ii++){
           total = i*ii;
           if(ispalindrome(total) == 0){
               if(total > max){
                   max = total;
                }
            }
        }
    }
    printf("The solution is %lld\n",max);
}
