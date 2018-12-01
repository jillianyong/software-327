/*EC327 Programming Assignment 3
The Space Race: Exploring the Void in C++ - Episode 1*/

//Model View Controller Platform

#ifndef Model_h
#define Model_h

#include <iostream>
#include "Astronaut.h"
#include "Person.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "View.h"

using namespace std;

class Model : public Game_Object
{
public:
	Model();
	~Model();
	Astronaut * get_Person_ptr(int);
	Oxygen_Depot * get_Oxygen_Depot_ptr(int);
	Space_Station * get_Space_Station_ptr(int);
	bool update();
	void display(View &view);
	void show_status();
	int get_time();

private:
	int time;
	int count_down;
	Game_Object * object_ptrs[10];
	int num_objects;
	Astronaut * person_ptrs[10];
	int num_persons;
	Oxygen_Depot * depot_ptrs[10];
	int num_depots;
	Space_Station * station_ptrs[10];
	int num_stations;
};

#endif