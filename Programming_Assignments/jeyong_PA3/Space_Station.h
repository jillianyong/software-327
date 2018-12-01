/*EC327 Programming Assignment 3
The Space Race: Exploring the Void in C++ - Episode 1*/

/*This class has a location and an amount of moon stones. 
It also has a display_code letter and an ID number to help identify the object. 
Space_Station Object Inherit from Game_Object*/

//Checkpoint 2

#ifndef Space_Station_h
#define Space_Station_h

#include <iostream>
#include "Game_Object.h"

class Space_Station : public Game_Object //space station inherits from game object
{
public:
	void deposit_moonstones(double deposit_amount);
	bool add_astronaut();
	int get_astronauts();
	bool update();
	void show_status();
	Space_Station(); //default constructor
	Space_Station(Cart_Point inputLoc, int inputid); //non-default constructor
	~Space_Station(); //destructor

private:
	double amount_moonstones;
	int number_astronauts;
};

#endif