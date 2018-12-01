/*EC327 Programming Assignment 3
The Space Race: Exploring the Void in C++ - Episode 1*/

//Cart_Point Class

#ifndef Cart_Point_h
#define Cart_Point_h

#include <iostream>
#include "Cart_Vector.h"

using namespace std;
class Cart_Vector;

class Cart_Point 
{
public:
	double x;
	double y;
	Cart_Point(); //default constructor
	Cart_Point(double inputx, double inputy); //non default constructor
};

double cart_distance(Cart_Point, Cart_Point); //nonmember function prototype

std::ostream& operator<<(std::ostream& os, const Cart_Point& obj); //overloaded stream

Cart_Point operator+(Cart_Point, Cart_Vector); //addition operator

Cart_Vector operator-(Cart_Point, Cart_Point); //subtraction operator

#endif
