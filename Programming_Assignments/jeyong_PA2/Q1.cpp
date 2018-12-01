//Programming Assignment 2, Question 1

#include <iostream>
#include <cmath>
#include <fstream>
#include "functions.h"

using namespace std;

const int ENTRIES = 10;

int main()
{
  initialize();
  char commandcode;

  while (true)
  {
      cout<<"Please enter command code: ";
      cin>>commandcode; 
      bool truefalse = checkCode(commandcode);

    if (commandcode == 'f' || commandcode == 'F') //Calculating Factorial
    {
    	int number;
    	cout<<"Please enter command parameters: ";
    	cin>>number;

    	factorial (number);
    }

    else if (commandcode == 'b' ||  commandcode == 'B') //Calculating Fibonacci
    {
    	int number;
    	cout<<"Please enter command parameters: ";
    	cin>>number;

        cout<<"fibonacci("<<number<<") = "<<fibonacci(number)<<endl;
    }

    else if (commandcode == 'r' ||  commandcode == 'R') //Calculating Square Root
    {
       double first; 
       double last;
       double delta;
       cout<<"Please enter command parameters: ";
       cin>>first;
       cin>>last;
       cin>>delta;

       findSqrtValue(first, last, delta);

     }

    else if (commandcode == 'd' ||  commandcode == 'D') //compute odd numbers, list odd numbers between first and last number provided
    {
       int userfirst;
       int userlast;
       cout<<"Please enter command parameters: ";
       cin>>userfirst;
       cin>>userlast;

       findNextOddValue(userfirst, userlast);
    }

    else if (commandcode == 'l' ||  commandcode == 'L') //calculating natural log
    {
       double first; 
       double last;
       double delta;
       cout<<"Please enter command parameters: ";
       cin>>first;
       cin>>last;
       cin>>delta;

       naturalLog(first, last, delta);
    }

    else if (commandcode == 'n' ||  commandcode == 'N') //calculate the nyan cat value
    {
       double first; 
       double last;
       double delta;
       cout<<"Please enter command parameters: ";
       cin>>first;
       cin>>last;
       cin>>delta;

       findNyanCatValue(first, last, delta);

    }
    else if (commandcode == 'i' ||  commandcode == 'I') //file input, read data
    {
      char filein[100];

      const char * parameter = "Please enter command parameters: " ;
      cout<<parameter;
      cin >> filein;
      
      readDataFromFile(filein);

    }
    else if (commandcode == 'o' ||  commandcode == 'O') //file output, write data
    {
      char fileout[100];

      const char * parameters = "Please enter command parameters: " ;
      cout<<parameters;
      cin >> fileout;

      writeDataToFile(fileout); //FYI this function creates an output file but doesn't properly work sorry I tried really hard

    }

    else if (commandcode == 'q' ||  commandcode == 'Q') //Quit Code
    {
    	break;
    }

    else
    {
    	cout<<"Invalid Command Code"<<endl;
    }

 }
  
  return 0;

}
