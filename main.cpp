#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string"
#include "snake.h"

using namespace std;



int main()
{
    srand(time(0));// Initialize random number generator.
    cout<<"Random numbers generated between 1 and 10:"<<endl;
//    for(int i=0;i<2;i++)
//        cout << (rand() % 10) + 1<<" ";

    int a ,b;
    int c = 5,d = 5;
    randPposition(&a,&b);
    cout<<a<<" and "<<b;
    gameTest(&c, &d, &a,&b);
    cout<<a<<" and "<<b;
    return 0;
}
