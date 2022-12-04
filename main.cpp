#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string"
#include "snake.h"

using namespace std;

extern "C" {
#include "stdio.h"
    void print() {
        std::printf("hii");
    }
}


int main()
{
    srand(time(0));// Initialize random number generator.
    cout<<"Random numbers generated between 1 and 10:"<<endl;
    int a ,b;
    int c = 5,d = 5;
    randPposition(&a,&b);
    cout<<a<<" and "<<b;
    gameTest(&c, &d, &a,&b);
    cout<<a<<" and "<<b<<"\n";
    runEmbedPython();
    return 0;
}
