#include <iostream>
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include "Game_Object.h"

using namespace std;

int main()
{
	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2017" << endl;
	cout << "Programming Assignment 3" << endl;

	View spaceview = View();
	Model spacemodel = Model();

	main_loop(spacemodel, spaceview);

	return 0;

}