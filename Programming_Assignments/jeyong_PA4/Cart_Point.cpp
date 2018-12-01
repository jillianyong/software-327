/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//Programming Assignment 4, Class Specifications
//Cart_Point class, represents a point on a Cartesian Coordinate System

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <cmath>

using namespace std;

Cart_Point::Cart_Point() //creating default Cart_Point constructor
{
	x = 0.0;
	y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy) //creating non-default constructor
{
	x = inputx;
	y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2) //find the distance
{
	double xdist = p1.x - p2.x;
	double ydist = p1.y - p2.y;
	double distance;
	distance = sqrt(xdist * xdist + ydist * ydist); //pythagorean theorem
	return distance;
}


std::ostream& operator<<(std::ostream& os, const Cart_Point& obj) //stream output operator
{
	os << "(" << obj.x << ", " << obj.y << ")";
	return os;
}

Cart_Point operator+(Cart_Point p1, Cart_Vector v1) //addition operator  
{
	Cart_Point p2(p1.x + v1.x, p1.y + v1.y);
	return p2;
}

Cart_Vector operator-(Cart_Point p1, Cart_Point p2) //subtraction operator
{
	Cart_Vector v2(p1.x - p2.x, p1.y - p2.y);
	return v2;
}
