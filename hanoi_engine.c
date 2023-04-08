#include <stdio.h>
#include <stdlib.h>

#include "hanoi_engine.h"
#include "stack.h"

struct hanoiGame_s
{
    hanoiStack towers[NB_TOWER];
    int nbDisks;
};

hanoiGame initGame(int nbDisks){
    hanoiGame newGame = malloc(sizeof(struct hanoiGame_s));

    if (nbDisks <= 0){
        return NULL;
    }

    newGame->nbDisks = nbDisks;

    newGame->towers[0] = initHanoiStack(nbDisks);

    for(int i = nbDisks; i > 0; i--){
        if (stackUp(newGame->towers[0], i) != STA_SUCCESS){
            return NULL;
        }
    }

    for (int i = 1; i < NB_TOWER; i++){
        newGame->towers[i] = initHanoiStack(nbDisks);
    }

    return newGame;
}

void destroyGame(hanoiGame game){
    for(int i = 0; i < NB_TOWER; i++){
        destroyHanoiStack(game->towers[i]);
    }

    free(game);
}

void printGame(const hanoiGame game){
    for(int i = 0; i < NB_TOWER; i++){
        printStack(game->towers[i]);
        printf("\n");
    }
}

//hanoiGame
