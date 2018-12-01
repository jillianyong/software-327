/*EC327 Programming Assignment 3
The Space Race: Exploring the Void in C++ - Episode 1*/

//Object Astronaut (an astronaut is a person)

#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Game_Object.h"
#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <cmath>
#include <stdlib.h> 

using namespace std;

Astronaut::Astronaut() : Person('A')
//Astronaut::Astronaut() : Game_Object('A')
{
	amount_moonstones = 0;
	astronaut_oxygen = 20;

	depot = NULL;
	home = NULL;
	cout << "Astronaut default constructed" << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc) : Person(in_loc, in_id, 'A')//non-default constructor
//Astronaut::Astronaut(int in_id, Cart_Point in_loc) : Game_Object(in_loc, in_id, 'A')//non-default constructor
{
	amount_moonstones = 0;
	astronaut_oxygen = 20;

	depot = NULL;
	home = NULL;
	cout << "Astronaut constructed" << endl;
}

Astronaut::~Astronaut()
{
	cout << "Astronaut destructed." << endl; //destructor
}


bool Astronaut::update() //updates the status of the object on each time unit
{
	switch (state)
	{
		case 's': //stopped
		{
			return false;
		}

		case 'm': //moving to a destination
		{
			if (Person::update_location())
			{
				state = 's';
				return true;
			}
			else
			{
				amount_moonstones++;
				astronaut_oxygen--;

				if (astronaut_oxygen == 0)
				{
					cout << "Out of Oxygen, you lose!" << endl;
					std::_Exit(0);
				}
				//amount_oxygen--;
				return false;
			}
		}

		case 'o': //outbound to depot
		{
			if (Person::update_location())
			{
				state = 'g';
				return true;
			}
			else
			{
				amount_moonstones++;
				astronaut_oxygen--;

				if (astronaut_oxygen == 0)
				{
					cout << "Out of Oxygen, you lose!" << endl;
					std::_Exit(0);
				}
				//amount_oxygen--;
				return false;
			}
		}

		case 'g': //getting oxygen
		{
			//Oxygen_Depot amount_extracted;
			//Oxygen_Depot::Oxygen_Depot();
			double amount_to_extract = 20;
			depot->extract_oxygen(amount_to_extract);
			//amount_extracted = Oxygen_Depot::extract_oxygen();
			cout << display_code << id_num << ": Got 20 more oxygen." << endl; //constructs and destucts oxygen_depot.
			astronaut_oxygen = amount_to_extract + astronaut_oxygen;
			//amount_oxygen = amount_to_extract + amount_oxygen;
			//cout << display_code << id_num << "Got " << amount_to_extract << " oxygen." << endl;
			state = 's';
			return true;
		}

		case 'i': //inbound to station
		{
			if (Person::update_location())
			{
				state = 'd';
				return true;
			}
			else
			{
				amount_moonstones++;
				astronaut_oxygen--;
				if (astronaut_oxygen == 0)
				{
					cout << "Out of Oxygen, you lose!" << endl;
					std::_Exit(0);
				}
				//amount_oxygen--;
				return false;
			}
		}

		case 'd': //depositing moonstones
		{
			cout << display_code << id_num << ": Depositing " << amount_moonstones << " moonstones." << endl;
			//Space_Station::Space_Station();
			//Space_Station dep;
			//double deposit_amount;
			home->deposit_moonstones(amount_moonstones); //constructs and destucts space_station??
			home->update();
			amount_moonstones = 0;
			state = 's';
			return true;
		}

		case 'l': //locking into station
		{
			if (Person::update_location())
			{
				home->add_astronaut();
				return true;
			}
		}
	}
	return true;
}

void Astronaut::start_supplying(Oxygen_Depot *inputDepot) //remove oxygen from the depot
{
	depot = inputDepot;
	Person::setup_destination(inputDepot -> get_location());
	state = 'o'; //Outbound
	cout << display_code << id_num << ": Yes, my lord." << endl;
}

void Astronaut::start_depositing(Space_Station *inputStation) //astronaut needs to start moving to station to deposit moonsones
{
	home = inputStation;
	Person::setup_destination(inputStation -> get_location());
	state = 'i'; //inbound;
	cout << display_code << id_num << ": Yes, my lord." << endl;
} 

void Astronaut::go_to_station(Space_Station *inputStation) //tells astronaut to lock into the input station
{
	Person::setup_destination(inputStation -> get_location());
	state = 'l'; //locking
}

void Astronaut::show_status()
{
	switch (state)
	{
		case 's': //stopped
		{
			cout << "Astronaut Status: "<< display_code << get_id() << " at " << get_location() << " is stopped with "<< astronaut_oxygen << " oxygen and " << amount_moonstones << " moonstones." << endl;
			break;		
		}
		
		case 'm': //moving to a destination
		{
			cout << "Astronaut Status: " << display_code << get_id() << " at " << get_location() << " moving at speed of " << get_speed() << " towards " << get_destination() << " at each step of " << get_delta() << endl;
			break;
		}
		
		case 'o': //outbound to depot
		{
			cout << "Astronaut Status: " << display_code << get_id() << " at " << get_location() << " moving at a speed of " << get_speed() << " towards " << get_destination() << " at each step of " << get_delta() << " is outbound to a Depot with " << astronaut_oxygen << " oxygen and " << amount_moonstones << " moonstones." << endl;
			break;
		}
		
		case 'g': //getting oxygen
		{
			cout << "Astronaut Status:" << display_code << get_id() << " at " << get_location() << " moving at a speed of " << get_speed() << " towards " << get_destination() << " at each step of " << get_delta() << " is getting oxygen from Depot." << endl;
			break;
		}
		
		case 'i': //inbound to station
		{
			cout << "Astronaut Status: " << display_code << get_id() << " at " << get_location() << " moving at a speed of " << get_speed() << " towards " << get_destination() << " at each step of " << get_delta() << " is inbound to home with load: " << amount_moonstones << " moonstones and " << astronaut_oxygen << " oxygen." << endl;
			break;
		}
		
		case 'd': //depositing moonstones
		{
			cout << "Astronaut Status: " << display_code << get_id() << " at " << get_location() << " moving at a speed of " << get_speed() << " towards " << get_destination() << " at each step of " << get_delta() << " is depositing " << amount_moonstones << " moonstones." << endl;
			break;
		}
		
		case 'l': //locking into station
		{
			if (Person::update_location())
			{
				cout << "Astronaut Status: "<< display_code << get_id() << " at " << get_location() << " is locked at Space Station." << endl;
			}
			else if (astronaut_oxygen == 0)
			{
				cout << "Astronaut Status: Out of Oxygen. Can't Move!" << endl;
				break;
			}
			else
			{
				cout << "Astronaut Status: "<< display_code << get_id() << " at " << get_location() << " is locked at Space Station." << endl;
			}
			break;
		}
	}
}
