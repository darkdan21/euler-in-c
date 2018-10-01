#include <stdlib.h>
#include <stdio.h>
#include "../lib/shared.h"

int main(int argc, char** argv){
    printf("Problem: 3\n");
    struct linkedlist * list = malloc(sizeof(struct linkedlist));
    list->first = NULL;
    list->last = NULL;
    
    int(*divisorcheck)(void * x, void * item);
    divisorcheck = divisorcheckfunc;

    int(*printlist)(void * x, void * item);
    printlist = printlistfunc;

    int(*sumlist)(void * x, void * item);
    sumlist = sumlistfunc;

    int * item = malloc(sizeof(int));
    *item = 2;
    additem(list,item);

    for(int i = 3; i<1000000; i+=2){ //generate primes 'efficiently'
        item = malloc(sizeof(int));
        *item = i;
        if(!testlist(list,divisorcheck,&i)){
            item = malloc(sizeof(int));
            *item = i;
            additem(list,item);
        }
    }

    //testlist(list,printlist,NULL);


    long long int * lli = malloc(sizeof(long long int));
    *lli = 600851475143;
    divisorcheck = divisorcheckfuncprint;
    testlist(list,divisorcheck,lli);
    printf("The answer is the last factor\n");



    //int * sum = malloc(sizeof(int));
    //*sum = 0;
    //testlist(list,sumlist,sum);
    //printf("sum: %d\n",*sum);
}
