
#include "GenStack.h"
#include "Matcher.h"
using namespace std;

Matcher::Matcher(int maxSize, int type)
{
  myStack = new GenStack(maxSize, type);
  isInDoubleQuote = false;
  isInSingleQuote = false;
}
Matcher::~Matcher()
{

}
bool Matcher::newChar(char thisChar)
{
  if(thisChar == '\"' && prevChar != '\\')
  {
    if(isInDoubleQuote)
    {
      isInDoubleQuote = false;
    }
    else
    {
      isInDoubleQuote = true;
    }
    return true;
  }
  else if(thisChar == '\'' && prevChar != '\\')
  {
    if(isInSingleQuote)
    {
      isInSingleQuote = false;
    }
    else
    {
      isInSingleQuote = true;
    }
    return true;
  }
  else if(isInSingleQuote==false && isInDoubleQuote==false)
  {
    if(thisChar == '(' || thisChar == '[' || thisChar == '{')
    {
      return isOpeningStatement(thisChar);
    }
    else if(thisChar == ')' || thisChar == ']' || thisChar == '}')
    {
      return isClosingStatement(thisChar);
    }
    return true;
  }
  else
  {
    return true;
  }
}

bool Matcher::isOpeningStatement(char statment)
{
  myStack->push(statment);
  return true;
}
bool Matcher::isClosingStatement(char statment)
{
  char top = myStack->peek();
  if(myStack->isEmpty()==true)
  {
    return false;
  }
  if(statment == ')')
  {
    if(top != '(')
    {
      return false;
    }
  }
  else if(statment == ']')
  {
    if(top != '[')
    {
      return false;
    }
  }
  else if(statment == '}')
  {
    if(top != '{')
    {
      return false;
    }
  }
  myStack->pop();
  return true;
}
