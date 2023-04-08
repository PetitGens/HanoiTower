#ifndef __HANOI_ENGINE_H__
#define __HANOI_ENGINE_H__

#define NB_TOWER 3

typedef struct hanoiGame_s* hanoiGame;

hanoiGame initGame(int nbDisks);

void destroyGame(hanoiGame);

void printGame(const hanoiGame);

#endif //__HANOI_ENGINE_H__