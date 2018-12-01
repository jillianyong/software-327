/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Object Astronaut (an astronaut is a person)

#ifndef Astronaut_h
#define Astronaut_h

#include <iostream>
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"

using namespace std;
class Space_Station;
class Oxygen_Depot;

class Astronaut : public Person
{
public:
	Astronaut();
	Astronaut(int in_id, Cart_Point in_loc);
	~Astronaut();
	bool update();
	void start_supplying(Oxygen_Depot *inputDepot);
	void start_depositing(Space_Station *inputStation);
	void go_to_station(Space_Station *inputStation);
	void show_status();

private:
	double amount_moonstones;
	double astronaut_oxygen;
	Oxygen_Depot *depot;
	Space_Station *home;

};

#endif
