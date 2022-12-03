#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string"
#include "snake.h"
#include "Python.h"


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

    try {
        PyObject *filee,*pFunc,*pDict,*pResult;
        filee = PyImport_Import((PyObject *) "test");
        pDict = PyModule_GetDict(filee);
        pFunc = PyDict_GetItemString(pDict, "add");
        pResult = PyObject_CallObject(pFunc,NULL);
        if(pResult == NULL)
            printf("Calling the add method failed.\n");
        string result = reinterpret_cast<basic_string<char> &&>(pResult);
        cout<<result;
        Py_Finalize();
    }
    catch (exception e){
        cout<<e.what();
    }

    //Py_Finalize();
    return 0;
}
