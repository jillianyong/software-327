//Functions program for Question 1 of PA1

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdio.h>

using namespace std;

extern const int ENTRIES = 10;

void initialize() // print header
{
   cout << "EC327: Introduction to Software Engineering" << endl;
   cout << "Fall 2017" << endl;
   cout << "Programming Assignment 2" << endl;
   cout << "Value of Entries is: " << ENTRIES << endl;
}

bool checkCode(char commandcode) // check if it was a valid input command
{
  if (commandcode == 'f' || commandcode == 'F' || commandcode == 'b' || commandcode == 'B' || commandcode == 'r' || commandcode == 'R' || commandcode == 'd' || commandcode == 'D' || commandcode == 'l' || commandcode == 'L' || commandcode == 'n' || commandcode == 'N' || commandcode == 'i' ||commandcode == 'I' ||commandcode == 'o' ||commandcode == 'O' ||commandcode == 'q' ||commandcode == 'Q')
    return true;
  else
    return false;
}

double findNyanCatValue(double first, double last, double delta) //three double integer inputs
{
  int counter = 1;
  double nyanval;
  double value;
  value = first;

  if (first > last || delta <= 0)
  {
    cout << "No computation needed."<< endl;
  }

  else if (first == last)
  {
        double lastval = (2.0*last)+(last*(pow(6.0,last)));
        cout << "NyanCat value of " <<last<<" = " << lastval << endl;
  }

  while (value < last && delta > 0)
  {
     nyanval = (2.0*value)+(value*(pow(6.0,value)));
     cout << "NyanCat value of " <<value<<" = " << nyanval << endl;
     value = value + delta;
      
     counter++;
      
     if (counter > ENTRIES)
     {
      break;
     }

    if (value >= last)
    {
      double lastval = (2.0*last)+(last*(pow(6.0,last)));
      cout << "NyanCat value of " <<last<<" = " << lastval << endl;
    }

  }

return 0;

}


int factorial(int number) //Single integer value input
{
  unsigned long long factorial = 1;

  for (int i = 1; i <= number; ++i)
  {
    factorial *= i;
  }

  cout << "factorial ("<<number<<") = "<< factorial << endl;

  return 0;

}

int fibonacci(int number) //single integer value input
{
  if (number <= 1)
    return number;
  return fibonacci(number-1) + fibonacci(number-2);

}

double findSqrtValue(double first, double last, double delta) //three double inputs, first, last, delta
{
  double sqrtvalue;
  double value;
  int counter = 1;
  value = first;

  if (first > last || delta <= 0)
  {
    cout << "No computation needed." << endl;
  }

  else if (first == last)
  {
        cout << "squareroot (" << last << ") = " << sqrt(last) << endl;
  }

  while (value < last && delta > 0)
  {
    cout << "squareroot (" << value << ") = " << sqrt(value) << endl;
    value = value + delta;

    counter++;
      
    if (counter > ENTRIES)
    {
      break;
    }
      
    if(value >= last || first == last)
    {
      cout << "squareroot (" << last << ") = " << sqrt(last) << endl;
    }

  }
  
  return 0;

}

double naturalLog(double first, double last, double delta) //3 double inputs, calculate natural log
{
  double logval;
  double value;
  int counter = 1;
  value = first;

  if (first > last || delta < 0) //error checking
  {
    cout << "No computation needed."<<endl;

  }

  else if (first == last)
  {
        cout<<"ln("<<last<<") = "<<log(last)<<endl;
  }

  while (value < last && delta > 0)
  {
    cout<<"ln("<<value<<") = "<<log(value)<<endl;
    value = value + delta;
    counter++;
      
    if (counter > ENTRIES)
    {
      break;
    }

    if (value >= last || first == last)
    {
      cout<<"ln("<<last<<") = "<<log(last)<<endl;
    }

  }

return 0;

}

int findNextOddValue(int userfirst, int userlast) //finding odd value after user input
{
  int firstodd;
  int counter = 1;

  if(userfirst%2 == 1) //checking if inputted value is odd
  {
    firstodd = userfirst;
  }

  else //adjusting output if input is even
  {
    firstodd = userfirst + 1;
  }

  while (firstodd <= userlast)
  {
    cout << firstodd << ", ";
    firstodd = firstodd + 2;
    counter++;
      
    if (counter > ENTRIES)
    {
      break;
    }

  }
  cout << "\b" << "\b" << " " << endl;
  //cout << endl;

  return 0;
}

void writeDataToFile(const char * input) //FYI this function creates an output file but doesn't properly work sorry I tried really hard
{
  char file[100];
  char message[420];

  ofstream outputfile;

  outputfile.open(input);

  if (outputfile.is_open())
  {
    outputfile << message << endl;
  }
  else
  {
    cout << "Error" << endl;
  }

  outputfile.close();
}


void readDataFromFile(const char * file) //ifstream
{
  ifstream readin;
  readin.open(file);
  double first;
  double last;
  double delta;
  char commandcode;
  int commandnumber = 1;

  while (commandnumber < ENTRIES)
  {
    while (readin >> commandcode >> first >> last >> delta)
    {
      if(commandcode == 'r' || commandcode == 'R')
      {
        cout << "Enter command code: " << commandcode << endl;
        cout << "Enter command paramters: " << first << " " << last << " " << delta << endl;
        findSqrtValue(first, last, delta);
      }

      else if (commandcode == 'l' || commandcode == 'L')
      {  
        cout << "Enter command code: " << commandcode << endl;
        cout << "Enter command paramters: " << first << " " << last << " " << delta << endl;
        naturalLog(first, last, delta);
      }

      else if (commandcode == 'n' || commandcode == 'N')
      {
        cout << "Enter command code: " << commandcode << endl;
        cout << "Enter command paramters: " << first << " " << last << " " << delta << endl;
        findNyanCatValue(first, last, delta);
      }

      else if (commandcode == 'd' ||  commandcode == 'D')
      {
        cout << "Enter command code: " << commandcode << endl;
        cout << "Enter command paramters: " << first << " " << last << " "<< endl;
       findNextOddValue(first, last);
      }

      else if (commandcode == 'b' ||  commandcode == 'B')
      {
        cout << "Enter command code: " << commandcode << endl;
        cout << "Enter command paramters: " << first << endl;
        cout<<"fibonacci("<<first<<") = "<<fibonacci(first)<<endl;
      }

      else if (commandcode == 'f' || commandcode == 'F')
      {
        cout << "Enter command code: " << commandcode << endl;
        cout << "Enter command paramters: " << first << endl;
        factorial (first);
      }

      commandnumber++;

    }

    return;

  }
  
  //read.close(file);
}
