//
// Created by soham on 2/12/22.
//

#include "Python.h"
#include <curses.h>
#include <stdlib.h>
#include "headers/conio.h"
#include <unistd.h>
#include "ncurses.h"
#ifndef GAME_SNAKE_H
#define GAME_SNAKE_H

//This function is to genrate random positions on screen
int randPposition(int* a, int* b){
    srand(time(NULL));
//    PyObject *pResult;
//    *pResult = PyRun_SimpleString("import random");
    *a = rand() % 10 + 1;
    *b = rand() % 10 + 1;
    return 0;
}

//This is only for testing now!!
int gameTest(int *currX,int *currY,int *posX ,int *posY , int mode){
    printf("\ngameTest started\n");
    while (mode == 1){
        if(*currX == *posX && *currY == *posY){
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

#define QUOTE(...) #__VA_ARGS__
const char *pyCode = QUOTE(
        import os;
        import sys;
        sys.path.append('..');
        //print('Hello from Python!!');
        //from pypackage import testPy
);
char *charTostr(char destination[], char source)
{
    destination[0] = source;	// copy the character into the string
    destination[1] = '\0';		// null-terminate the string
    return destination;			// common convention for str functions
}

void setup(int *x,int *y,int *fruitx,int *fruity,int *height,int *width,int *gameover,int *score)
{
    *gameover = 0;

    // Stores height and width
    *x = *height / 2;
    *y = *width / 2;
    label1:
        *fruitx = rand() % 20;
        if (*fruitx == 0)
            goto label1;
    label2:
    *fruity = rand() % 20;
        if (fruity == 0)
            goto label2;
        *score = 0;
}


int runEmbedPython()
{
    Py_Initialize();
    PyRun_SimpleString(pyCode);
    Py_Finalize();
    return 0;
}

void input(int *flag,int *gameover)
{
    while (!kbhit()) {
        switch (getchar()) {
            case 'a':
                *flag = 1;
                break;
            case 's':
                *flag = 2;
                break;
            case 'd':
                *flag = 3;
                break;
            case 'w':
                *flag = 4;
                break;
            case 'x':
                *gameover = 1;
                break;
        }
    }
}

void logic(int *flag,int *x,int *y,int *gameover,int *height,int *width,int *fruitx,int *fruity,int *score)
{
    sleep(0.01);
    switch (*flag) {
        case 1:
            *y-=1;
            break;
        case 2:
            *x+=1;
            break;
        case 3:
            *y+=1;
            break;
        case 4:
            *x-=1;
            break;
        default:
            break;
            }

    // If the game is over
    if (*x < 0 || *x > *height
    || *y < 0 || *y > *width)
        *gameover = 1;

    // If snake reaches the fruit
    // then update the score
    if (*x == *fruitx && *y == *fruity) {
        label3:
            *fruitx = rand() % 20;
            if (*fruitx == 0)
                goto label3;

        // After eating the above fruit
        // generate new fruit
        label4:
            *fruity = rand() % 20;
            if (*fruity == 0)
                goto label4;
            *score += 10;
        }
}

void draw(int *x,int *y,int *i,int *j,int *width,int *height,int *fruitx,int *fruity,int *score)
{
    for (*i = 0; *i < *height; *i+=1) {
        for (*j = 0; *j < *width; *j+=1) {
            if (*i == 0 || *i == *width - 1
            || *j == 0
            || *j == *height - 1) {
                printf("#");
                }
            else {
                if (*i == *x && *j == *y)
                    printf("0");
                else if (*i == *fruitx
                && *j == *fruity)
                    printf("*");
                else
                    printf(" ");
                }
            }
        printf("\n");
        }

    // Print the score after the
    // game ends
    printf("score = %d", *score);
    printf("\n");
    printf("press X to quit the game");
}

#endif //GAME_SNAKE_H
