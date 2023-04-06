#ifndef __HANOI_STACK_H__
#define __HANOI_STACK_H__

typedef struct s_hanoiStack* hanoiStack;

struct s_hanoiStack* initHanoiStack(int size);

void destroyHanoiStack(hanoiStack);

int stackUp(hanoiStack, int element);

int unstack(hanoiStack);

void printStack(struct s_hanoiStack *stack);

#endif //__HANOI_STACK_H__