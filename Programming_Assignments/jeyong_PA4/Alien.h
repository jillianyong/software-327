/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

#ifndef Alien_h
#define Alien_h

#include <iostream>
#include "Astronaut.h"
#include "Game_Command.h"
#include "Person.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include "Cart_Point.h"

using namespace std;

class Alien : public Game_Object
{
public:
	Alien();
	Alien(int in_id, Cart_Point in_loc);
	~Alien();
	void setup_destination(Cart_Point dest);
	void start_moving(Cart_Point dest);
	void stop();
	void start_attack(Astronaut* in_target);
	bool update_location();
	bool update();
	void show_status();

private:
	int attack_strength;
	double range;
	Person * target;
	double speed;
	Cart_Point destination;
	Cart_Vector delta;
};

#endif