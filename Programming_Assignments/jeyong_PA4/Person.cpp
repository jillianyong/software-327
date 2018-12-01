/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Object Person

#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <cmath>
using namespace std;

Person::Person() : Game_Object('p')//default constructor
{
	speed = 5.0;
	health = 5.0;
	cout << "Person default constructed" << endl;
}

Person::Person(char in_code) : Game_Object(in_code)//non-default constructor
{
	speed = 5.0;
	health = 5.0;
	state = 's'; //stopped
	display_code = in_code;
	cout << "Person constructed" << endl;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code) : Game_Object(in_loc, in_id, in_code)//non-default constructor
{
	speed = 5.0;
	health = 5.0;
	cout << "Person constructed" << endl;
}

Person::~Person()
{
	cout << "Person destructed." << endl; //destructor
}


void Person::setup_destination(Cart_Point dest)//sets up object to start moving
{
	destination = dest;
	Cart_Vector temppt = destination - location;

	delta = temppt * (speed / cart_distance(destination, location));
}

Cart_Point Person::get_destination()
{
	return destination;
}

bool Person::update_location()	//checks to see if the object is within one step of its destination
{
	Cart_Vector temppt = destination - location;
	if(fabs(temppt.x) <= fabs(delta.x) && fabs(temppt.y) <= fabs(delta.y))
	{
		cout << display_code << id_num << ": I'm there!" << endl; //if astronaut has arrived at destination
		return true; //object has arrived
	}
	else
	{
		location = location + delta;
		cout << display_code << id_num << ": step..." << endl; //if astronaut hasn't arrived at destination
		return false;
	}
}

void Person::start_moving(Cart_Point dest) //tells person to start moving
{
	if (state == 'x')
	{
		cout << "I can't move, I'm dead." << endl;
	}
	else
	{
		setup_destination(dest);
		destination = dest;
		cout << "Moving "<<id_num<<" to "<<destination << endl;

		if (dest.x == location.x && dest.y == location.y)
		{
			cout << "I'm already there. see?" << endl;
		}
		else
		{
			state = 'm'; //moving
			cout << display_code << id_num << ": On my way." << endl;
		}
	}
}

void Person::stop() //tells person to stop moving or collecting oxygen
{
	if (state == 'x')
	{
		cout << "I can't move, I'm dead." << endl;
	}
	else
	{
		state = 's'; //stopped
	}
}

double Person::get_speed()
{
	return speed;
}

Cart_Vector Person::get_delta()
{
	return delta;
}

bool Person :: is_alive() 
{
	if (state != 'x')
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

void Person :: take_hit(int attack_strength)
{
	health = health - attack_strength;
	if (health <= 0)
	{
		cout << display_code << id_num << ": Gasp! I'm dying..." << endl;
		state = 'x';
	}
	else
	{
		cout << display_code << id_num << ": Ouch!" << endl;
	}

	if (health < 3)
	{
		//convert display code to lower case if health < 3
		int asciicode = int(display_code);
  	 	int asciilower = asciicode + 32;
  	 	display_code = (char)asciilower;
    }
}

int Person::get_health()
{
	return health;
}

void Person :: start_supplying(Oxygen_Depot *inputDepot)
{
	cout << "Sorry, I can't work a depot." << endl;
}

void Person :: start_depositing(Space_Station *inputStation)
{
	cout << "Sorry, I can't work a station." << endl;
}

void Person :: go_to_station(Space_Station *inputStation)
{
	cout << "Sorry, I can't lock into a station." << endl;
}

void Person::show_status()//outputs the info contained in the class for moving speed
{
	Game_Object::show_status();
	
	cout << "State: " << state << endl; 
	cout << "Speed: " << speed << endl;
	cout << "Destination: " << destination << endl; 
	cout << "Delta: "<< delta << endl;

	if (state == 's')
		cout << display_code << id_num << " is stopped." << endl;
	else if (state == 'l')
		cout << display_code << id_num << " is locked." << endl;
	else if (state == 'x')
		cout << display_code << id_num << " is dead." << endl;
	else
		cout << display_code << id_num << " 's health is: " << health << endl;

}
