#ifndef __HANOI_STACK_H__
#define __HANOI_STACK_H__

typedef struct s_hanoiStack* hanoiStack;

typedef enum {STA_SUCCESS, STA_UNSTACKING_VOID_STACK} staErrCode;

#define STA_EXCEEDING_MAX_SIZE -1
#define STA_STACKING_UPON_SMALLER_DISK -2
#define STA_VOID_STACK -3

hanoiStack initHanoiStack(int size);

void destroyHanoiStack(hanoiStack);

int getTopDisk(const hanoiStack stack);

staErrCode stackUp(hanoiStack, int element);

int unstack(hanoiStack);

void printStack(const hanoiStack stack);

#endif //__HANOI_STACK_H__