#ifndef MATCHER_H
#define MATCHER_H
#include "GenStack.h"
class Matcher{
public:
    Matcher(int maxSize, int type);
    ~Matcher();
    GenStack *myStack;
    bool newChar(char thisChar);
    bool isInDoubleQuote;
    bool isInSingleQuote;
    char prevChar;

private:
  bool isOpeningStatement(char statment);
  bool isClosingStatement(char statment);
};

#endif
