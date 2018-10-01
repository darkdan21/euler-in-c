#include <stdlib.h>
#include <stdio.h>

int ismultiple(int x, int y){
    return x % y;
}
struct linkedlist{
    struct linkedlistitem * first;
    struct linkedlistitem * last;
};
struct linkedlistitem {
    struct linkedlistitem * next;
    void * data;
};
int additem(struct linkedlist * list, void * item){
    if(list == NULL){
        return 1;
    }
    struct linkedlistitem * last = list->last;
    struct linkedlistitem * new = malloc(sizeof(struct linkedlistitem));
    new->data = item;
    new->next = NULL;
    if(last != NULL){ //error checking isn't definitive because I'm lazy :)
        last->next = new;
    } else {
        list->first = new;
    }
    list->last = new;
    return 0;
}
int testlist(struct linkedlist * list, int(*test)(void * x, void * item),void * x){
    struct linkedlistitem * item = list->first;
    while(item != NULL){
        int result = test(x,item->data);
        if(result == 1){
            return 1;
        }
        if(result == 2){
            return 0;
        }
        item = item->next;
    }
    return 0;
}



int printlistfunc(void * x, void * item){
    printf("%d\n",*(int *)item);
    return 0;
}

int sumlistfunc(void * x, void * item){
    int i = *(int *)item;
    *(int *)x += i;
    return 0;
}


int divisorcheckfunc(void * number, void * item){
    int i = *(int *)item;
    int x = *(int *)number;
    if((x % i) == 0){
        return 1;
    }
    if(i*i > x){
        return 2;
    }
    return 0;
}

int divisorcheckfuncprint(void * number, void * item){
    int i = *(int *)item;
    long long x = *(long long *)number;
    if((x % i) == 0){
        printf("%d is a factor of %lld\n",i,x);
    }
    return 0;
}
