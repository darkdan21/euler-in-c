#include <stdlib.h>
#include <stdio.h>
#include "../lib/shared.h"


int main(int argc, char** argv){
    int sum = 0;
    for(int i = 0; i<1000; i++){
        if(ismultiple(i,3) == 0){
            sum+=i;
        } else if(ismultiple(i,5) == 0){
            sum+=i;
        }
    }
    printf("Result:\n%d\n",sum);
}
