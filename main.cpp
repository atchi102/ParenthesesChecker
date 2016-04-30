#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"
#include "Matcher.h"

using namespace std;
void runProgram(string fileName);

int main(int argc, char** argv)
{

  char userInput = 'x';
  string fileName = "";
  if(argc >= 2)
  {
    fileName = argv[1];
  }
  else
  {
    cout<<"Please insert a command line argument of what file I should go over"<<endl;
    exit(1);
  }
  cout<<fileName<<endl;
  runProgram(fileName);

  while(true)
  {
    cout<<"Would you like me to process a new file? (Y/N)"<<endl;
    cin>>userInput;
    if(userInput=='N')
    {
      break;
    }
    if(userInput == 'Y')
    {
      cout<<"What file would you like me to process?"<<endl;
      cin>>fileName;
      runProgram(fileName);
    }
  }


  return 0;
}

void runProgram(string fileName)
{
  Matcher parenMatch(2,0);
  ifstream fin;

  fin.open(fileName);
  if (fin.fail( ))
  {
    cout << "Input file opening failed.\n"<<endl;
    exit(1);
   }

   char next;
   int lineNum = 1;
   fin.get(next);

   //while the input is not at the end of file
  while (! fin.eof( ))
  {
    //if reached end of line enter if statment else increment whichever character count it is
    if (next == '\n')
    {
      lineNum++;//increment line
    }
    else{
      if(parenMatch.newChar(next)==false)
      {
        cout<<"Error: didn't find closing statment at line "<<lineNum<<endl;
        char tempChar = parenMatch.myStack->peek();
        if(tempChar == '{')
        {
          cout<<"Expected } found "<<next<<endl;
        }
        else if(tempChar == '[')
        {
          cout<<"Expected ] found "<<next<<endl;
        }
        else if(tempChar == '(')
        {
          cout<<"Expected ) found "<<next<<endl;
        }
        exit(1);
      }
    }
    parenMatch.prevChar = next;
    fin.get(next);
  }
  if(parenMatch.myStack->isEmpty() == false)
  {
    if(parenMatch.isInDoubleQuote || parenMatch.isInSingleQuote)
    {
      cout<<"Error: reached end of file while still in quotations"<<endl;
    }
    cout<<"Error: reached end of file without recieving closing statment"<<endl;
  }
  else
  {
    cout<<"ParenMatch complete: Success"<<endl;
  }
}
