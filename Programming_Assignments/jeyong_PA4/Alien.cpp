/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <cmath>
#include "Astronaut.h"
#include "Game_Command.h"
#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include "Cart_Point.h"

using namespace std;

Alien::Alien() : Game_Object ('X')
{
	display_code = 'X';
	attack_strength = 2;
	range = 2.0;
	target = NULL; //object being attacked
	speed = 5;

	cout << "default Alien constructed." << endl;
}

Alien::Alien(int in_id, Cart_Point in_loc) : Game_Object (in_loc, in_id, 'X') 
{
	display_code = 'X';
	attack_strength = 2;
	range = 2.0;
	target = NULL; //object being attacked
	speed = 5;

	cout << "Alien constructed." << endl;
}

Alien::~Alien()
{
	cout << "Alien destructed." << endl;
}

void Alien::setup_destination(Cart_Point dest)//sets up object to start moving
{
	destination = dest;
	Cart_Vector temppt = destination - location;

	delta = temppt * (speed / cart_distance(destination, location));
}

void Alien::start_moving(Cart_Point dest) //tells alien to start moving
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

void Alien::stop() //tells alien to stop moving or collecting oxygen
{
	state = 's'; //stopped
}

void Alien :: start_attack(Astronaut* in_target)
{
	double distance = cart_distance(location, in_target->get_location());
	if (distance <= range) 
	{
		cout << display_code << id_num << ": Smash!" << endl;
		target = in_target;
		state = 'a'; 
	}

	else
	{
		cout << display_code << id_num << ": Target is out of range." << endl;
	}
}

bool Alien::update_location()	//checks to see if the object is within one step of its destination
{
	Cart_Vector temppt = destination - location;
	if(fabs(temppt.x) <= fabs(delta.x) && fabs(temppt.y) <= fabs(delta.y))
	{
		cout << display_code << id_num << ": I'm there!" << endl; //if alien has arrived at destination
		return true; //object has arrived
	}
	else
	{
		location = location + delta;
		cout << display_code << id_num << ": step..." << endl; //if alien hasn't arrived at destination
		return false;
	}
}

bool Alien::update()
{
	switch (state)
	{
		case 's' : //stopped
		{
			return false;
			break;
		}

		case 'm' : //moving
		{
			if (update_location())
			{
				state = 's';
				return true;
			}
			
			else
			{
				return false;
			}
			break;
		}

		case 'a' :
		{
			double distance = cart_distance(location, target->get_location());
			if (distance > range) 
			{
				cout << display_code << id_num << ": Target is out of range" << endl;
				cout << "FOR NARNIAAAAAAAAAAA" << endl; //CHARRRRGGGEEEEEE
				state = 's';
				return true;
				break;
			}
			else
			{
				if (target->is_alive()) //target is alive
				{
					cout << display_code << id_num << ": Take that!" << endl;
					target->take_hit(attack_strength); 
					return false;
					break;
				}
				else //Target is dead
				{
					cout << display_code << id_num << ": I triumph!" << endl;
					state = 's';
					return true;
					break;
				}
			}

		}
	}

	return true;
}

void Alien::show_status()
{

	if (state == 's') //stopped
	{
		cout << "Alien status: " << display_code << id_num << " at " << get_location() << " is stopped." << endl;
	}

	else if (state == 'm') //moving
	{
		cout << "Alien status: " << display_code << id_num << " is moving at a speed of " << speed << " towards " << destination << " at each step of " << delta << endl;
	}
	else if (state == 'a') //attacking
	{
		cout << "Alien status: " << display_code << id_num << " is attacking astronaut A" << target->get_id() << endl;
	}
}