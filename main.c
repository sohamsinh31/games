//
// Created by soham on 3/12/22.
//
//#include <Python.h>
//#include "headers//snake.h"
//#define QUOTE(...) #__VA_ARGS__
//const char *pyCode = QUOTE(
//        import os;
//        import sys;
//        sys.path.append('..');
//        //from pypackage import getInput;
//);

//int main(){
//    Py_Initialize();
//    PyObject *myResult = NULL;
//    PyRun_SimpleString(pyCode);
//    PyObject* myModuleString = (PyObject *) PyUnicode_FromString((char *) "pypackage.getInput");
//    PyObject* myModule = PyImport_Import(myModuleString);
//    if(!myModule){
//        goto done;
//    }
//    char c;
//    do {
//        myResult = PyObject_CallMethod(myModule,"getchar",NULL);
//        c = PyUnicode_AsUTF8(myResult)[0];
//    } while (c != 'x');
//
//    if(!myResult){
//        goto done;
//    }
//    done:
//        PyErr_Print();
//        Py_CLEAR(myResult);
//        Py_CLEAR(myModule);
//
//    Py_Finalize();
//        printf("%c",getNative());
//        return 0;
//}

