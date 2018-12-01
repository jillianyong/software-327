//EC327 Programming Assignment 1, Question 1
//Intersection of 2 rectangles

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  //Prompt user for rectangle information
  cout<<"Enter the information for the first rectangle"<<endl;
  int lxcoord1;
  cout<<"x-coordinate: ";
  cin>>lxcoord1;
  int lycoord1;
  cout<<"y-coordinate: ";
  cin>>lycoord1;
  int length1;
  cout<<"length: ";
  cin>>length1;
  int height1;
  cout<<"height: ";
  cin>>height1;

  //determine coordinates of upper right corner of rectangle 1
  int rxcoord1;
  rxcoord1=lxcoord1+length1;
  int rycoord1;
  rycoord1=lycoord1+height1;

  //Prompt user for rectangle information
  cout<<"Enter the information for the second rectangle"<<endl;
  int lxcoord2;
  cout<<"x-coordinate: ";
  cin>>lxcoord2;
  int lycoord2;
  cout<<"y-coordinate: ";
  cin>>lycoord2;
  int length2;
  cout<<"length: ";
  cin>>length2;
  int height2;
  cout<<"height: ";
  cin>>height2;

  //determine coordinates of upper right corner of rectangle 2
  int rxcoord2;
  rxcoord2=lxcoord2+length2;
  int rycoord2;
  rycoord2=lycoord2+height2;

 //one rectangle is on left side of other (will not intersect)
  if(lxcoord1 > rxcoord2 || lxcoord2 > rxcoord1)
  {
    cout<<"THE RECTANGLES DO NOT INTERSECT"<<endl;
  }

  //one rectangle above the other (will not intersect)
  else if(lycoord1 > rycoord2 || lycoord2 > rycoord1)
  {
    cout<<"THE RECTANGLES DO NOT INTERSECT"<<endl;
  }
  //all other cases, rectangles will intersect
  else
  {
    cout<<"THE RECTANGLES INTERSECT"<<endl;
  }

  return 0;

}
