#include "shared.c"
int ismultiple(int x, int y);
struct linkedlist;
struct linkedlistitem;
int testlist(struct linkedlist * list, int(*test)(void * x, void * item),void * x);
int additem(struct linkedlist * list, void * item);
int divisorcheckfunc(void * number, void * item);
int divisorcheckfuncprint(void * number, void * item);
int sumlistfunc(void * x, void * item);
int printlistfunc(void * x, void * item);




