//EC327 Programming Assignment 1, Question 4
//Rock ,Paper, Scissors

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
  //Prompt User Input
  int userselect;
  cout<<"Choose Rock (0), Paper (1), or Scissors (2): ";
  cin>>userselect;

  //Error Check
  while(userselect < 0 || userselect > 2)
  {
    cout<<"Invalid Input. Try Again."<<endl;
    cout<<"Choose Rock (0), Paper (1), or Scissors (2): ";
    cin>>userselect;
  }

  //computer randomly chooses a value
  double computerselect; 
  srand (time (NULL));
  computerselect = rand() % 3;
  string compchoice;
  if(computerselect==0)
    compchoice="Rock";
  if(computerselect==1)
    compchoice="Paper";
  if(computerselect==2)
    compchoice="Scissors";
  cout<<"Computer chooses: "<<compchoice<<endl;


  if(userselect == computerselect) //both choose the same value
  {
    cout<<"You tie!"<<endl;
  }
  else if(userselect == 0 && computerselect == 1) //Paper beats Rock
  {
    cout<<"You lose!"<<endl;
  }
  else if(userselect == 0 && computerselect == 2) // Rock beats scissors
  {
    cout<<"You win!"<<endl;
  }
  else if(userselect == 1 && computerselect == 2) //Scissors beats paper
  {
    cout<<"You lose!"<<endl;
  }
  else if(userselect == 1 && computerselect == 0) // Paper beats Rock
  {
    cout<<"You win!"<<endl;
  }
  else if(userselect == 2 && computerselect == 1) //Scissors beats paper
  {
    cout<<"You win!"<<endl;
  }
  else if(userselect == 2 && computerselect == 0) // Rock beats scissors
  {
    cout<<"You lose!"<<endl;
  }

  return 0;
}
