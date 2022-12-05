#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string"
#include "snake.h"
#include "Python.h"

using namespace std;

int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

extern "C" {
    #include "stdio.h"
    int printf(const char* format, ...);
}


int main()
{
    srand(time(0));// Initialize random number generator.
    //runEmbedPython();
    setup(&x,&y,&fruitx,&fruity,&height,&width,&gameover,&score);
    while(!gameover){
        draw(&x,&y,&i,&j,&width,&height,&fruitx,&fruity,&score);
        input(&flag,&gameover);
        logic(&flag,&x,&y,&gameover,&height,&width,&fruitx,&fruity,&score);
    }
    return 0;
}
