/*EC327 Programming Assignment 3
The Space Race: Exploring the Void in C++ - Episode 1*/

//Object Person

#ifndef Person_h
#define Person_h

#include <iostream>
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"

using namespace std;
class Cart_Point;
class Cart_Vector;
class Person : public Game_Object
{
public:
	Person();
	Person(char in_code);
	Person(Cart_Point in_loc, int in_id, char in_code);
	virtual ~Person();
	void start_moving(Cart_Point dest);
	void stop();
	void show_status();
	double get_speed();
	Cart_Vector get_delta();
	Cart_Point get_destination();
	virtual void start_supplying(Oxygen_Depot *inputDepot);
	virtual void start_depositing(Space_Station *inputStation);
	virtual void go_to_station(Space_Station *inputStation);

protected:
	bool update_location();
	void setup_destination(Cart_Point dest);

private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;

};

#endif
