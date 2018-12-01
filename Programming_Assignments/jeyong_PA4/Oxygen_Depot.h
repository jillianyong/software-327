/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

/*This class has a location and an amount of oxygen, and has a display code letter and
ID number to help identify the object in the output.
Oxygen_Depot inherits from Game_Object.*/

//Checkpoint 2

#ifndef Oxygen_Depot_h
#define Oxygen_Depot_h

#include <iostream>
#include "Game_Object.h"
//using namespace std;

class Oxygen_Depot : public Game_Object //oxygen depot inherits from Game_Object
{	
public:
	bool is_empty();
	double extract_oxygen(double);
	bool update();
	void show_status();
	Oxygen_Depot(); //default constructor
	Oxygen_Depot(Cart_Point inputLoc, int inputid); //non-default constructor
	~Oxygen_Depot(); //Destructor
	//double amount_to_extract = 20.0;

private:
	double amount_oxygen;
};

#endif