/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Programming Assignment 4, Class Specifications
//Base class for all the objects in the game

#include <iostream>
#include "Game_Object.h"
#include <iomanip>

using namespace std;

Game_Object :: Game_Object (char in_code) //default constructor
{
	display_code = in_code;
	id_num = 1;
	state = 's';
	cout << "Game_Object constructed" << endl;
}

Game_Object :: Game_Object (Cart_Point in_loc, int in_id, char in_code) //non default constructor
{
	display_code = in_code;
	location = in_loc;
	id_num = in_id;
	state = 's';
	cout << "Game_Object constructed" << endl;
}

Game_Object::~Game_Object() //destructor
{
	cout << "Game_Object destructed." << endl;
}

Cart_Point Game_Object :: get_location() //returns the location for the object
{
	return location;
}

int Game_Object :: get_id() //returns the id for the object
{
	return id_num;
}

char Game_Object :: get_state() //returns the state for the object
{
	return state;
}

void Game_Object :: show_status() //outputs info contained in the class
{
	cout << display_code << id_num << " at " << location << endl; //see sample output for formatting 
}

bool Game_Object :: is_alive()
{
	return true;
}

void Game_Object :: drawself(char* ptr) //puts display_code at the character pointed to by ptr & ASCII char for id_num
{
	ptr[0] = display_code;
	char tempchar = '0' + id_num;
	ptr[1] = tempchar;
}