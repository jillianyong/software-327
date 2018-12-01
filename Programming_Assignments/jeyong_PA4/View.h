/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//View Controller Platform

#ifndef View_h
#define View_h

#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"

const int view_maxsize = 20;

class View
//class View : public Game_Object
{
public:
	View();
	~View();
	void clear();
	void plot(Game_Object * ptr);
	void draw();

private:
	int size;
	double scale;
	Cart_Point origin;
	char grid[view_maxsize][view_maxsize][2];
	bool get_subscripts(int &ix, int &iy, Cart_Point location);
};

#endif