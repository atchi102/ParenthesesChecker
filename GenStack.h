#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>


class GenStack{
  public:
    GenStack(int maxSize, int type);
    GenStack();
    ~GenStack();

    void push(char data);
    char pop();
    char peek();
    void overload();


    bool isFull();
    bool isEmpty();

    int top;
    int numElements;
    int maxSize;
    bool arrayCreated;
    int typeChosen;
    // 0 = char
    // 1 = int
    // 2 = double
    // 3 = bool
    // 4 = string
    char *myCharArray;
    char *tempArray;

};
#endif
