/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Model View Controller Platform

#include "View.h"
#include "Model.h"
#include "Person.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Alien.h"
#include "Input_Handling.h"
#include <iostream>
#include <stdlib.h> 
#include <list>
#include <iterator>

using namespace std;

Model :: Model() : Game_Object('p')
{
	time = 0;
	count_down = 10;

	//Astronaut 1
	Cart_Point astroloc1 = Cart_Point(5,1);
	Astronaut* a1 = new Astronaut(1,astroloc1);
	object_ptrs.push_back(a1);
	person_ptrs.push_back(a1);
	active_ptrs.push_back(a1);

	//Astronaut 2
	Cart_Point astroloc2 = Cart_Point(10,1);
	Astronaut* a2 = new Astronaut(2, astroloc2);
	object_ptrs.push_back(a2);
	person_ptrs.push_back(a2);
	active_ptrs.push_back(a2);

	//Oxygen Depot 1
	Cart_Point oxyloc1 = Cart_Point(1,20);
	Oxygen_Depot* oxy1 = new Oxygen_Depot(oxyloc1,1); 
	object_ptrs.push_back(oxy1);
	depot_ptrs.push_back(oxy1);
	active_ptrs.push_back(oxy1);

	//Oxygen Depot 2
	Cart_Point oxyloc2 = Cart_Point(10,20);
	Oxygen_Depot* oxy2 = new Oxygen_Depot(oxyloc2, 2); 
	object_ptrs.push_back(oxy2);
	depot_ptrs.push_back(oxy2);
	active_ptrs.push_back(oxy2);

	//Space Station 1 - default constructed
	Space_Station* space1 = new Space_Station();
	object_ptrs.push_back(space1);
	station_ptrs.push_back(space1);
	active_ptrs.push_back(space1);

	//Space Station 2
	Cart_Point spaceloc2 = Cart_Point(5,5);
	Space_Station* space2 = new Space_Station(spaceloc2, 2); 
	object_ptrs.push_back(space2);
	station_ptrs.push_back(space2);
	active_ptrs.push_back(space2);

	//Alien 1
	Cart_Point alienloc1 = Cart_Point(7,14);
	Alien* alien1 = new Alien(1, alienloc1);
	object_ptrs.push_back(alien1);
	alien_ptrs.push_back(alien1);
	active_ptrs.push_back(alien1);

	//Alien 2
	Cart_Point alienloc2 = Cart_Point(7,5);
	Alien* alien2 = new Alien(2, alienloc2);
	object_ptrs.push_back(alien2);
	alien_ptrs.push_back(alien2);
	active_ptrs.push_back(alien2);

	cout << "Model default constructed." << endl;

}

Model :: ~Model() //Destructor, deletes each object
{
	object_itr = object_ptrs.begin();
	for (int i = 0; i < object_ptrs.size(); i++)
	{
		delete *object_itr; //Game_Object
	}

	cout << "Model Destructed." << endl;
}

Astronaut* Model :: get_Person_ptr(int id) //Search Person Function
{
	person_itr = person_ptrs.begin();

    for(int i = 0; i < person_ptrs.size(); i++)
    {
        if((*person_itr)->get_id() == id)
        {
          return *person_itr;
        }
        person_itr++;
    }

   return 0;
}

Oxygen_Depot* Model :: get_Oxygen_Depot_ptr(int id) //Search Oxygen_Depot Function
{
	depot_itr = depot_ptrs.begin();

    for(int i = 0; i < depot_ptrs.size(); i++)
    {
        if((*depot_itr)->get_id() == id)
        {
          return *depot_itr;
        }
        depot_itr++;
    }

    return 0;
}

Space_Station* Model :: get_Space_Station_ptr(int id) //Search Space_Station Function
{
	station_itr = station_ptrs.begin();

    for(int i = 0; i < station_ptrs.size(); i++)
    {
        if((*station_itr)->get_id() == id)
        {
          return *station_itr;
        }
        station_itr++;
    }

    return 0;
}

Alien* Model :: get_Alien_ptr(int id) //Search Alien Function
{
	alien_itr = alien_ptrs.begin();

    for(int i = 0; i < alien_ptrs.size(); i++)
    {
        if((*alien_itr)->get_id() == id)
        {
          return *alien_itr;
        }
        alien_itr++;
    }

    return 0;
}

//create a new function for the blast off parts
bool Model::update() //Update Check function
{
	time++;
	int updates = 0; //counter

	//iterate thru active list
	for(list<Game_Object*>::iterator active_itr = active_ptrs.begin(); active_itr != active_ptrs.end(); active_itr++)
	{
		if((*active_itr)->update()) //iterating through all active_ptrs
		{
			updates++;
		}
		if((*active_itr)->is_alive() == false) //checks if the thing is alive
		{
			active_itr = active_ptrs.erase(active_itr);
		}
	}

	if(updates > 0)
		return true;
	else
		return false;

	//iterate to see if person is locked in or not
	for(list<Astronaut*>::iterator person_itr = person_ptrs.begin(); person_itr != person_ptrs.end(); person_itr++)
	{
		if ((*person_itr)->get_state() == 'l' && updates > 0)
		{
			cout << "Ready for takeoff? " << count_down << "..." << endl;
			count_down--;
			return true;
			if (count_down == 0)
			{
				cout << "Unmanned takeoff... You lose!" << endl;
				std::_Exit(0);
			}
		}
		for (list<Space_Station*>::iterator station_itr = station_ptrs.begin(); station_itr != station_ptrs.end(); station_itr++)
		{
			list<Space_Station*>::iterator station_last = station_ptrs.end();
			if ((*station_itr)->get_astronauts() == 0 && (*station_last)->get_astronauts() == 0)
			{
				cout << "Missing " << person_ptrs.size() << " astronauts!" << endl;
				count_down--;
				return true;
			}
			else
			{
				cout << "Blast Off! You Win!" << endl;
				std::_Exit(0);
			}
		}
	}
}

void Model::display(View &gameview)
{
	gameview.clear();
	active_itr = active_ptrs.begin();
	for(std::list<Game_Object*>::const_iterator iterator = active_ptrs.begin(), end = active_ptrs.end(); iterator != end; ++iterator)
	{
		gameview.plot(*object_itr);
	}

	gameview.draw();
}


void Model :: show_status() //Outputs status of all Game_Objects
{
	object_itr = object_ptrs.begin();
	for (std::list<Game_Object*>::const_iterator iterator = object_ptrs.begin(), end = object_ptrs.end(); iterator != end; ++iterator)
  	{
  		Game_Object* myObj = *iterator;
		if(myObj != NULL)
		{	
			myObj->show_status();
		}
	}


}

int Model :: get_time() //function to return time
{
	return time;
}

void Model::new_command(char type, int id, double x, double y)
{
	Cart_Point location = Cart_Point(x, y); //cart point for location
	switch(type)
	{
		case 'd': //oxygen depot
		{
			//check for duplicate oxygen depots
			for(depot_itr = depot_ptrs.begin(); depot_itr != depot_ptrs.end(); depot_itr++)
			{
				if(id == (*depot_itr)->get_id())
				{
					Invalid_Input sameoxydep = Invalid_Input("An oxygen depot with this ID already exists!");
					throw sameoxydep;
				}
			}

			//make new one
			Oxygen_Depot* newdepot = new Oxygen_Depot(location, id);
			object_ptrs.push_back(newdepot);
			active_ptrs.push_back(newdepot);
			depot_ptrs.push_back(newdepot);
			break;
		}

		case 's': //space station
		{
			//check for duplicate space stations
			for(station_itr = station_ptrs.begin(); station_itr != station_ptrs.end(); station_itr++)
			{
				if(id == (*station_itr)->get_id())
				{
					Invalid_Input samespacestation = Invalid_Input("A space station with this ID already exists!");
					throw samespacestation;
				}
			}

			//make new one
			Space_Station* newstation = new Space_Station(location, id);
			object_ptrs.push_back(newstation);
			active_ptrs.push_back(newstation);
			station_ptrs.push_back(newstation);
			break;
		}

		case 'a': //Astronauts
		{
			//check for duplicate astronauts
			for(person_itr = person_ptrs.begin(); person_itr != person_ptrs.end(); person_itr++)
			{
				if(id == (*person_itr)->get_id())
				{
					Invalid_Input sameastro = Invalid_Input("An astronaut with this ID already exists!");
					throw sameastro;
				}
			}

			//make new one
			Astronaut* newastro = new Astronaut(id, location);
			object_ptrs.push_back(newastro);
			active_ptrs.push_back(newastro);
			person_ptrs.push_back(newastro);
			break;
		}

		case 'x': //Aliens
		{
			//check for duplicate aliens
			for(alien_itr = alien_ptrs.begin(); alien_itr != alien_ptrs.end(); alien_itr++)
			{
				if(id == (*alien_itr)->get_id())
				{
					Invalid_Input samealien = Invalid_Input("An oxygen depot with this ID already exists!");
					throw samealien;
				}
			}

			//make new one
			Alien* newalien = new Alien(id, location);
			object_ptrs.push_back(newalien);
			active_ptrs.push_back(newalien);
			alien_ptrs.push_back(newalien);
			break;
		}

		default: {
					//invalid char type
					Invalid_Input wronginput = Invalid_Input("Character type is invalid");
					cin.clear();
					cin.ignore(10, '\n');
					throw wronginput;
				}
	}
}
