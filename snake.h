//
// Created by soham on 2/12/22.
//
#include <stdlib.h>
#include <ctime>

#ifndef GAME_SNAKE_H
#define GAME_SNAKE_H


//This function is to genrate random positions on screen
int randPposition(int* a, int* b){
    srand(time(NULL));
    *a = rand() % 10 + 1;
    *b = rand() % 10 + 1;
    return 0;
}

int gameTest(int *currX,int *currY,int *posX = 0,int *posY = 0, int mode = 1){
    printf("\ngameTest started\n");
    while (mode == 1){
        if(*currX == *posX && *currY == *posY){
//            int tempA = 8,tempB = 7;
//            randPposition(&tempA,&tempB);
//            *posX = tempA;
//            *posY = tempB;
            printf("\nPosition matched\n");
            break;
        } else{
            int tempA,tempB;
            randPposition(&tempA,&tempB);
            *currX = tempA;
            *currY = tempB;
            printf("\n %d ,%d\n",*currX,*currY);
        }
    }
    return 0;
}

#endif //GAME_SNAKE_H
