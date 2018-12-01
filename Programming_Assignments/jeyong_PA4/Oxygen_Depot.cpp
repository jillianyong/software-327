/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

/*This class has a location and an amount of oxygen, and has a display code letter and
ID number to help identify the object in the output.
Oxygen_Depot inherits from Game_Object.*/

//Checkpoint 2

#include <iostream>
#include "Oxygen_Depot.h"
#include "Game_Object.h"

using namespace std;

Oxygen_Depot::Oxygen_Depot() : Game_Object('d') //default constructor
{
	display_code = 'O';
	state = 'f'; //full of oxygen
	amount_oxygen = 50;
	cout << "Oxygen_Depot default constructed" << endl;
}

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputid) : Game_Object(inputLoc, inputid, 'd') //Game Object Determines the location, ID, and display code
{
	id_num = inputid;
	location = inputLoc;
	display_code = 'O';
	state = 'f';
	amount_oxygen = 50;
	cout << "Oxygen_Depot constructed" << endl;
}

Oxygen_Depot::~Oxygen_Depot()
{
	cout << "Oxygen_Depot destructed." << endl; //destructor
}

bool Oxygen_Depot::is_empty()
{
	if (amount_oxygen == 0)
		return true;
	else
		return false;
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract = 20.0)
{
	if (amount_oxygen >= amount_to_extract)
	{
		amount_oxygen = amount_oxygen - amount_to_extract;
		return amount_oxygen;
	}
	else
	{
		amount_oxygen = 0;
		return amount_oxygen;
	}
}

bool Oxygen_Depot::update()//Function should not be returning true if oxygen_depot is depleted. Should ONLY return true when Oxygen_Depot becomes empty
{
	if (amount_oxygen == 0)
	{
		state = 'e';
		display_code = 'o';
		cout<<"Oxygen_Depot "<<id_num<<" has been depleted"<<endl;
		return true;
	}
	else
		return false; //not depleted
}

void Oxygen_Depot::show_status()
{
	cout << "Oxygen Depot status: " << display_code << id_num << " at "<< location <<" contains " << amount_oxygen << " oxygens." << endl;
}