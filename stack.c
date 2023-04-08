#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct s_hanoiStack{
    int size;
    int *stack;
    int nbPieces;
};

struct s_hanoiStack* initHanoiStack(int size){
    if (size <= 0){
        return NULL;
    }

    struct s_hanoiStack* new = malloc(sizeof(struct s_hanoiStack));
    new->size = size;
    new->stack = malloc(sizeof(int) * size);
    new->nbPieces = 0;

    return new;
}

void destroyHanoiStack(hanoiStack stack){
    free(stack->stack);
    free(stack);
}

int getTopDisk(const hanoiStack stack){
    if (stack->nbPieces == 0){
        return STA_VOID_STACK;
    }

    return stack->stack[stack->nbPieces - 1];
}

staErrCode stackUp(hanoiStack stack, int element){
    if(stack->nbPieces + 1 > stack->size){
        return STA_EXCEEDING_MAX_SIZE;
    }

    int topDisk = getTopDisk(stack);

    if (topDisk != STA_VOID_STACK && element > topDisk){
        return STA_STACKING_UPON_SMALLER_DISK;
    }

    stack->stack[stack->nbPieces] = element;

    stack->nbPieces++;

    return STA_SUCCESS;
}

int unstack(hanoiStack stack){
    if(stack->nbPieces <= 0){
        return STA_UNSTACKING_VOID_STACK;
    }

    stack->nbPieces--;

    return stack->stack[stack->nbPieces];
}

void printStack(const hanoiStack stack){
    if (stack->nbPieces == 0){
        printf("[empty]\n");
    }

    else{
        for(int i = stack->nbPieces - 1; i >= 0; i--){
            printf("%2d\n", stack->stack[i]);
        }
    }
}