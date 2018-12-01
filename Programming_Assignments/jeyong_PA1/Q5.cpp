//EC327 Programming Assignment 1, Question 5
//Simple Ciphering with ASCII

#include <iostream>

using namespace std;

int main()
{
  char charinput;
  int asciichar;
  int opinput;
  char charoutput;
  int asciiout;

  //user inputs a character and desired operation 
  cout<<"Enter a character and operation: ";
  cin>>charinput;
  cin>>opinput;

  //convert character to ASCII
  asciichar = int(charinput);

  //Error check - Char
  if(asciichar > 90 && asciichar < 97)
  {
    cout<<"Result: Illegal Char"<<endl;
    return 0;
  }
  else if (asciichar < 65)
  {
    cout<<"Result: Illegal Char"<<endl;
    return 0;
  }
  else if (asciichar > 122)
  {
    cout<<"Result: Illegal Char"<<endl;
    return 0;
  }

  //Error Check - Operation
  while(opinput < 1 || opinput > 3)
  {
    cout<<"Result: Illegal operation"<<endl;
    return 0;
  }

  //Operation 1: Changing the Case
  if(opinput == 1) 
  {
    //Uppercase Letters
    if(asciichar > 64 && asciichar < 91)
    {
  	 asciiout = asciichar + 32;
  	 charoutput = (char)asciiout;
  	 cout<<"Result: "<<charoutput<<endl;
    }
    //Lowercase Letters
    else if(asciichar > 96 && asciichar < 123)
    {
      asciiout = asciichar - 32;
      charoutput = (char)asciiout;
      cout<<"Result: "<<charoutput<<endl;
    }
  }

  //Operation 2: Reverse Alphabet
  if(opinput == 2)
  {
     //Uppercase letters
     if(asciichar > 64 && asciichar < 91)
     {
       int normalizedposition;
       //determining location of letter from 0 to 26
       normalizedposition = asciichar - 65;
       //subtacting position from last lowercase to determine revere alphabet
       asciiout = 122 - normalizedposition;
       charoutput = (char)asciiout;
       cout<<"Result: "<<charoutput<<endl;
     }
      //Lowercase letters
      else if(asciichar > 96 && asciichar < 123)
      {
  	int normalizedposition;
	//determining location of letter from 0 to 26
  	normalizedposition = asciichar - 97;
	//subtracting position from last uppercase to determine reverse alphabet
  	asciiout = 90 - normalizedposition;
  	charoutput = (char)asciiout;
  	cout<<"Result: "<<charoutput<<endl;
      }
  }
  
  //Operation 3: Encrypt
  if(opinput == 3)
  {
       if(asciichar > 64 && asciichar < 85) //uppercase encryption
       {
  	 asciiout = asciichar + 6;
  	 charoutput = (char)asciiout;
  	 cout<<"Result: "<<charoutput<<endl;
       }
       else if (asciichar > 96 && asciichar < 117) //lowercase encryption
       {
  	 asciiout = asciichar + 6;
  	 charoutput = (char)asciiout;
  	 cout<<"Result: "<<charoutput<<endl;
       }
       else if(asciichar >= 85 && asciichar <= 90) //end of alphabet loop around, uppercase
       {
  	  asciiout = asciichar + 12;
  	  charoutput = (char)asciiout;
  	  cout<<"Result: "<<charoutput<<endl;
       }
       else if(asciichar >= 117 && asciichar <= 122) //end of alphabet loop around, lowercase
       {
  	  asciiout = asciichar - 52;
  	  charoutput = (char)asciiout;
  	  cout<<"Result: "<<charoutput<<endl;
       }
  }

  return 0;

}
