#include <stdio.h>

#include "stack.h"

int main(){
    hanoiStack stack = initHanoiStack(3);

    printStack(stack);

    stackUp(stack, 1);
    printStack(stack);
    printf("\n");

    stackUp(stack, 2);
    printStack(stack);
    printf("\n");

    stackUp(stack, 3);
    printStack(stack);
    printf("\n");

    printf("%d\n", stackUp(stack, 0));
    printf("\n");

    for(int i = 0; i < 3; i++){
        printf("%d\n", unstack(stack));
    }

    printStack(stack);

    destroyHanoiStack(stack);

    return 0;
}