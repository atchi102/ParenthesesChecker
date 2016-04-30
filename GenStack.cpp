#include <iostream>
#include <string>
#include "GenStack.h"

using namespace std;

GenStack::GenStack()
{

}
GenStack::GenStack(int max, int type)
{
  typeChosen = type;
  arrayCreated = false;
  numElements = 0;
  maxSize = max;
  top = -1;
}

GenStack::~GenStack()
{
  if(typeChosen == 0)
  {
      delete myCharArray;

  }

  cout << "object destroyed"<<endl;
}

void GenStack::push(char data)
{
  if(numElements == maxSize)
  {
    overload();
  }
  if(arrayCreated == false)
  {
      myCharArray = new char[maxSize];
      arrayCreated = true;
  }
  if(typeChosen == 0)
  {
      myCharArray[++top] = data;
  }
  numElements++;
}

char GenStack::pop()
{
  numElements--;
  return myCharArray[top--];
}

char GenStack::peek()
{
  return myCharArray[top];
}

void GenStack::overload()
{
  tempArray = new char[maxSize*2];
  for(int i = 0; i<=maxSize; ++i)
  {
    tempArray[i] = myCharArray[i];
  }
  myCharArray = tempArray;
  maxSize = maxSize*2;
  delete tempArray;

}

bool GenStack::isFull()
{
  return (top==maxSize-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}
