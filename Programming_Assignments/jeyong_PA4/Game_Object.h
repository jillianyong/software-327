/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Game_Object Class

#ifndef Game_Object_h
#define Game_Object_h

#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"

using namespace std;

class Cart_Point;

class Game_Object
{
	protected:
	Cart_Point location;
	int id_num;
	char display_code;
	char state;
	
	public:
	Game_Object(char in_code);
	Game_Object(Cart_Point in_loc, int in_id, char in_code);
	virtual ~Game_Object(); //destructor
	Cart_Point get_location();
	int get_id();
	char get_state();
	virtual void show_status();
	virtual bool update() = 0; //pure virtual
	virtual bool is_alive();
	void drawself(char* ptr);

};


#endif
