#include <stdio.h>
#include <stdlib.h>

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

void destroyHanoiStack(struct s_hanoiStack *stack){
    free(stack->stack);
    free(stack);
}

int stackUp(struct s_hanoiStack *stack, int element){
    if(stack->nbPieces + 1 > stack->size){
        return -1;
    }

    stack->stack[stack->nbPieces] = element;

    stack->nbPieces++;

    return 0;
}

int unstack(struct s_hanoiStack *stack){
    if(stack->nbPieces <= 0){
        return -1;
    }

    stack->nbPieces--;

    return stack->stack[stack->nbPieces];
}

void printStack(const struct s_hanoiStack *stack){
    if (stack->nbPieces == 0){
        printf("[empty]\n");
    }

    else{
        for(int i = stack->nbPieces - 1; i >= 0; i--){
            printf("%2d\n", stack->stack[i]);
        }
    }
}