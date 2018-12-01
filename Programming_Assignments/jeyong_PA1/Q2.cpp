//EC327 Programming Assignment 1, Question 2
//Cooking Converter

#include <iostream>

using namespace std;

int main()
{
  cout<<"Cups = 1, Ounces = 2, Tablespoons = 3, Teaspoons = 4"<<endl;
  int start;
  int endprod;
  cout<<"Conversion from: "; //prompt user for starting conversion unit
  cin>>start;
  cout<<"Conversion to: "; //prompt user for final conversion unit
  cin>>endprod;

  //Error Check
  while(start < 1 || start > 4 || endprod < 1 || endprod > 4)
  {
    cout<<"Invalid Input, Try Again"<<endl;
    cout<<"Conversion from: ";
    cin>>start;
    cout<<"Conversion to: ";
    cin>>endprod;
  }

  double amount;
  string typein;

//translating conversion unit to a string
  if(start == 1)
  {
     typein="Cups";
  }
  else if(start == 2)
  {
     typein="Ounces";
  }
  else if(start == 3)
  {
     typein="Tablespoons";
  }
  else if(start == 4)
  {
     typein="Teaspoons";
  }
  else
  {
     cout<<"Invalid input"<<endl;
  }
  //prompt user to input number amount
  cout<<"Enter the amount in "<<typein<<": ";
  cin>>amount;
  
  double output;

  if(start == 1 && endprod == 2) //cups to ounces; 1 cup = 8 ounces
  {
     output = amount * 8;
     cout<<amount<<" cups is "<<output<<" ounces"<<endl;
  }
  if(start == 1 && endprod == 3) //cups to tablespoons; 1 cup = 16 Tablespoons
  {
     output = amount * 16;
     cout<<amount<<" cups is "<<output<<" tablespoons"<<endl;
  }
  if(start == 1 && endprod == 4) //cups to teaspoons; 1 cup = 48 Teaspoons
  {
     output = amount * 48;
     cout<<amount<<" cups is "<<output<<" teaspoons"<<endl;
  }
  if(start == 2 && endprod == 1) //ounces to cups; 1 cup = 8 ounces
  {
     output = amount / 8;
     cout<<amount<<" ounces is "<<output<<" cups"<<endl;
  }
  if(start == 2 && endprod == 3) //ounces to tablespoons; 1 fluid Ounce = 2 Tablespoons
  {
     output = amount * 2;
     cout<<amount<<" ounces is "<<output<<" tablespoons"<<endl;
  }  
  if(start == 2 && endprod == 4) //ounces to teaspoons; 1 fluid Ounce = 6 Teaspoons
  {
     output = amount * 6;
     cout<<amount<<" ounces is "<<output<<" teaspoons"<<endl;
  }
  if(start == 3 && endprod == 1) //tablespoons to cups; 1 cup = 16 Tablespoons
  {
     output = amount / 16;
     cout<<amount<<" tablespoons is "<<output<<" cups"<<endl;
  }
  if(start == 3 && endprod == 2) //tablespoons to ounces; 1 fluid Ounce = 2 Tablespoons
  {
     output = amount / 2;
     cout<<amount<<" tablespoons is "<<output<<" ounces"<<endl;
  }
  if(start == 3 && endprod == 4) //tablespoons to teaspoons; 1 tablespoon = 3 Teaspoons
  {
     output = amount * 3;
     cout<<amount<<" tablespoons is "<<output<<" teaspoons"<<endl;
  }
  if(start == 4 && endprod == 1) //teaspoons to cups; 1 cup = 48 Teaspoons
  {
     output = amount / 48;
     cout<<amount<<" teaspoons is "<<output<<" cups"<<endl;
  }
  if(start==4 && endprod==2) //teaspoons to ounces; 1 fluid Ounce = 6 Teaspoons
  {
     output = amount / 6;
     cout<<amount<<" teaspoons is "<<output<<" ounces"<<endl;
  }
  if(start == 4 && endprod == 3) //teaspoons to tablespoons; 1 tablespoon = 3 Teaspoons
  {
     output = amount / 3;
     cout<<amount<<" teaspoons is "<<output<<" tablespoons"<<endl;
  }
  if(start == endprod) //input and output units are the same
  {
     output = amount;
     cout<<amount<<" "<<typein<<" is "<<output<<" "<<typein<<endl;
  }

  return 0;

}
