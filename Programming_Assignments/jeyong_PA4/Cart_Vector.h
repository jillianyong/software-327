/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Cart_Vector Class

#ifndef Cart_Vector_h
#define Cart_Vector_h

#include <iostream>
#include "Cart_Point.h"

class Cart_Vector
{
public:
	double x;
	double y;
	Cart_Vector(); //default constructor
	Cart_Vector(double inputx, double inputy); //non-default constructor
};

Cart_Vector operator*(Cart_Vector, double value); //multiplication operator

Cart_Vector operator/(Cart_Vector, double value); //division operator

std::ostream& operator<<(std::ostream& out, const Cart_Vector& obj); //stream output operator

#endif
