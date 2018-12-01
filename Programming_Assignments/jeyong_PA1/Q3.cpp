//EC327 Programming Assignment 1, Question 3
//Hamming Distance of the hex values of integers

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    //Prompt user for 2 integers
    int input1;
    int input2;
    cout<<"Enter two positive integers: ";
    cin>>input1;
    cin>>input2;
    //retaining original inputs
    int originput1=input1; 
    int originput2=input2;

    //converting input 1 into hex
    string hex1 = "";

    while(input1 !=0)
    {
       int hexval1 = input1 % 16;

       char hexchar1 = (hexval1 <= 9 && hexval1 >= 0) ?
	    static_cast<char>(hexval1 + '0') :
	    static_cast<char>(hexval1 - 10 + 'A');

       hex1 = hexchar1 + hex1;
       input1 = input1 / 16;
    }

    // cout<<"The hex value of Input 1 is: "<<hex1<<endl;

    //converting input 2 into hex
    string hex2 = "";

    while(input2 !=0)
    {
	int hexval2 = input2 % 16;

	char hexchar2 = (hexval2 <= 9 && hexval2 >= 0) ?
	     static_cast<char>(hexval2 + '0') :
	     static_cast<char>(hexval2 - 10 + 'A');

	 hex2 = hexchar2 + hex2;
	 input2 = input2 / 16;
    }

    //cout<<"The hex value of Input 2 is: "<<hex2<<endl;

    //indexing into the string to compare it, sum of counters = hamming distance
    int counter = 0;

    //indexing into string if the first input is longer than the second
    if (hex1.length() > hex2.length())
    {
       for(int i = 0; i <= hex1.length(); i++) 
  	  if(hex1[i] != hex2[i])
  	  {
  	     counter = counter + 1;
  	  }
  	  else
  	  {
  	     continue;
  	  }
    }

     //indexing into string if the second input is longer than the first
     else if(hex1.length() < hex2.length())
     {
  	for(int i=0; i <= hex2.length(); i++)
  	   if(hex1[i] != hex2[i])
	   {
  	      counter = counter + 1;
  	   }
  	   else
  	   {
  	      continue;
	   }
  	}
     //indexing into string if the first input is equal to the second
     else if (hex1.length() == hex2.length())
     {
  	 for(int i = 0; i <= hex2.length(); i++)
  	    if(hex1[i] != hex2[i])
  	    {
  	       counter = counter + 1;
	    }
  	    else
  	    {
  	       continue;
	    }
     }

  cout<<"Hamming distance between "<<originput1<<" and "<<originput2<<" when the numbers are in hex format is "<<counter<<endl;

  return 0;
}


