/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Model View Controller Platform

#ifndef Model_h
#define Model_h

#include <iostream>
#include <list>
#include <iterator>
#include "Astronaut.h"
#include "Person.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "View.h"
#include "Alien.h"

using namespace std;

class Model : public Game_Object
{
public:
	Model();
	~Model();
	Astronaut * get_Person_ptr(int);
	Oxygen_Depot * get_Oxygen_Depot_ptr(int);
	Space_Station * get_Space_Station_ptr(int);
	Alien * get_Alien_ptr(int);
	bool update();
	void display(View &view);
	void show_status();
	int get_time();
	bool take_off();
	void new_command(char type, int id, double x, double y);

private:
	int time;
	int count_down;
	list<Game_Object*> object_ptrs;
	list<Game_Object*> active_ptrs;
	list<Astronaut*>person_ptrs;
	list<Space_Station*>station_ptrs;
	list<Oxygen_Depot*>depot_ptrs;
	list<Alien*>alien_ptrs;


 	list<Game_Object*>::iterator object_itr;
	list<Game_Object*>::iterator active_itr;
	list<Astronaut*>::iterator person_itr;
	list<Space_Station*>::iterator station_itr;
	list<Oxygen_Depot*>::iterator depot_itr;
	list<Alien*>::iterator alien_itr;
};

#endif