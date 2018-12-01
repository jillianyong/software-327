/*EC327 Programming Assignment 3
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
#include <iostream>
#include <stdlib.h> 

using namespace std;

Model :: Model() : Game_Object('p')
{
	time = 0;
	count_down = 10;

	//Astronaut 1
	Cart_Point astroloc1 = Cart_Point(5,1);
	Astronaut* a1 = new Astronaut(1,astroloc1);
	object_ptrs[0] = a1;
	person_ptrs[0] = a1;

	//Astronaut 2
	Cart_Point astroloc2 = Cart_Point(10,1);
	Astronaut* a2 = new Astronaut(2, astroloc2);
	object_ptrs[1] = a2;
	person_ptrs[1] = a2;

	//Oxygen Depot 1
	Cart_Point oxyloc1 = Cart_Point(1,20);
	Oxygen_Depot* oxy1 = new Oxygen_Depot(oxyloc1,1); 
	object_ptrs[2] = oxy1;
	depot_ptrs[0] = oxy1;

	//Oxygen Depot 2
	Cart_Point oxyloc2 = Cart_Point(10,20);
	Oxygen_Depot* oxy2 = new Oxygen_Depot(oxyloc2, 2); 
	object_ptrs[3] = oxy2;
	depot_ptrs[1] = oxy2;

	//Space Station 1 - default constructed
	Space_Station* space1 = new Space_Station();
	object_ptrs[4] = space1;
	station_ptrs[0] = space1; 

	//Space Station 2
	Cart_Point spaceloc2 = Cart_Point(5,5);
	Space_Station* space2 = new Space_Station(spaceloc2, 2); 
	object_ptrs[5] = space2;
	station_ptrs[1] = space2; 

	num_objects = 5;
	num_persons = 2;
	num_depots = 2;
	num_stations = 2;

	cout << "Model default constructed." << endl;

}

Model :: ~Model() //Destructor, deletes each object
{
	for (int i = 0; i < 6; i++)
	{
		delete object_ptrs[i]; //Game_Object
	}

	cout << "Model Destructed." << endl;
}

Astronaut* Model :: get_Person_ptr(int id) //Search Person Function
{
	for (int i = 0; i < num_persons; i++)
	{
		if (person_ptrs[i] -> get_id() == id)
		{
			return person_ptrs[i];
		}
	}

	return 0;
}

Oxygen_Depot* Model :: get_Oxygen_Depot_ptr(int id) //Search Oxygen_Depot Function
{
	for (int i = 0; i < num_depots; i++)
	{
		if (depot_ptrs[i] -> get_id() == id)
		{
			return depot_ptrs[i];
		}
	}

	return 0;
}

Space_Station* Model :: get_Space_Station_ptr(int id) //Search Space_Station Function
{
	for (int i = 0; i < num_stations; i++)
	{
		if (station_ptrs[i] -> get_id() == id)
		{
			return station_ptrs[i];
		}
	}

	return 0;
}

bool Model :: update() //Update check function.
{
	time++;
	int updates = 0; //counter
	for (int i = 0; i < num_objects; i++)
	{
		if(object_ptrs[i]->update()) //iterating through all object_ptrs
		{
			updates++;
		}
	}

	if (updates > 0 && person_ptrs[0]-> get_state() != 'l' && person_ptrs[1]-> get_state() != 'l')
	{
		return true;
	}
	else if ((person_ptrs[0]->get_state() == 'l' || person_ptrs[1]->get_state() == 'l') && updates > 0)
	{
		cout << "Ready for takeoff? " << count_down << "..." << endl;
		count_down--;
		if (count_down == 0)
		{
			cout << "Unmanned takeoff... You lose!" << endl;
			std::_Exit(0);
		}

		if (station_ptrs[0]->get_astronauts() == 0 && station_ptrs[1]->get_astronauts() == 0)
		{
			cout << "Missing 2 astronauts!" << endl;
			return true;
		}

		else if (station_ptrs[0]->get_astronauts() > 0 && station_ptrs[1]->get_astronauts() == 0)
		{
			cout << "Missing 1 astronauts!" << endl;
			return true;
		}

		else if (station_ptrs[0]->get_astronauts() == 0 && station_ptrs[1]->get_astronauts() > 0)
		{
			cout << "Missing 1 astronauts!" << endl;
			return true;
		}

		else if (station_ptrs[0]->get_astronauts() >= 1 && station_ptrs[1]->get_astronauts() >= 1)
		{
			cout << "Blast Off! You Win!" << endl;
			std::_Exit(0);
		}
	}
	else
	{			
		return false;
	}

	return true;
}


class View;
void Model :: display(View& view)
{
	//cout << "Time is " << time << endl;
	//created later
}


void Model :: show_status() //Outputs status of all Game_Objects
{
	for (int i = 0; i < num_persons; i++)
	{
		person_ptrs[i] -> Astronaut::show_status();
	}

	for (int i = 0; i < num_depots; i++)
	{
		depot_ptrs[i] -> Oxygen_Depot::show_status();
	}

	for (int i = 0; i < num_stations; i++)
	{
		station_ptrs[i] -> Space_Station::show_status(); 
	}

}

int Model :: get_time() //function to return time
{
	return time;
}
