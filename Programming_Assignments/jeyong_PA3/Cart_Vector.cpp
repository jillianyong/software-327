/*EC327 Programming Assignment 3
The Space Race: Exploring the Void in C++ - Episode 1*/

//Programming Assignment 3, Class Specifications
//Program for Cart_Vector class

#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"

using namespace std;

Cart_Vector :: Cart_Vector () //creating default Cart_Vector constructor
{
	x = 0.0;
	y = 0.0;
}

Cart_Vector :: Cart_Vector (double inputx, double inputy) //non-default constructor
{
	x = inputx;
	y = inputy;
}

Cart_Vector operator*(Cart_Vector v1, double value) //multiplication operator
{
	Cart_Vector v2(v1.x * value, v1.y * value);
	return v2;
}

Cart_Vector operator/(Cart_Vector v1, double value) //division operator
{
	Cart_Vector v3(v1.x / value, v1.y / value);
	return v3;
}

std::ostream& operator<<(std::ostream& out, const Cart_Vector& obj) //stream output operator
{
	cout << "<" << obj.x << ", " << obj.y << ">";
	return out;
}