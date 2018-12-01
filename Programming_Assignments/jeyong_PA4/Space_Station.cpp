/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

/*This class has a location and an amount of moon stones. 
It also has a display_code letter and an ID number to help identify the object. 
Space_Station Object Inherit from Game_Object*/

//Checkpoint 2

#include "Space_Station.h"
#include "Game_Object.h"
#include <iostream>

using namespace std;

Space_Station::Space_Station() : Game_Object('p') //default constructor
{
	display_code = 's';
	state = 'o'; //original level
	amount_moonstones = 0;
	number_astronauts = 0;
	cout << "Space_Station constructed" << endl;
}

Space_Station::Space_Station(Cart_Point inputLoc, int inputid) : Game_Object(inputLoc, inputid, 'p') //non-default constructor
{
	id_num = inputid;
	location = inputLoc;
	display_code = 's';
	state = 'o'; //original level
	amount_moonstones = 0;
	number_astronauts = 0;
	cout << "Space_Station constructed" << endl;
}

Space_Station::~Space_Station()
{
	cout << "Space_Station destructed." << endl; //destructor
}

void Space_Station::deposit_moonstones(double deposit_amount) //adds deposit_amount of moonstones to Space_Station
{
	amount_moonstones = deposit_amount + amount_moonstones;
}

bool Space_Station::add_astronaut() //incremements # of astronauts when astronaut object calls this function
{
	if (state == 'u')
	{
		number_astronauts++;
		return true;
	}
	else
	{
		return false;
	}
}

int Space_Station::get_astronauts() //returns number of astronauts
{
	return number_astronauts;
}

bool Space_Station::update()
{
	if (amount_moonstones >= 10 && state != 'u') //only works 1 time, return false for later times
	{
		state = 'u';
		display_code = 'S';
		cout << display_code << id_num << " has been upgraded" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Space_Station::show_status() //print status
{
	if (state == 'u')
	{
		cout << "Space Station status: " << display_code << id_num << " at "<< location << " contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts. Upgraded." << endl;
	}
	else
	{
		cout << "Space Station status: " << display_code << id_num << " at "<< location << " contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts. Not yet upgraded." << endl;
	}
}