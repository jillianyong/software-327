/*EC327 Programming Assignment 4
The Space Race: Exploring the Void in C++ - Episode 1*/

//View Controller Platform
#include "View.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <iomanip>
#include <iostream>

using namespace std;

View :: View ()
{
	size = 11;
	scale = 2;
	origin = Cart_Point(0,0);
}

View :: ~View()
{
	cout << "View destructed." << endl;
}


void View :: clear() //creates background grid pattern
{
	for(int i = 0; i <= size; i++) //rows
	{
		for(int j = 0; j <= size; j++)//columns
		{
			grid[i][j][0] = '.'; //create grid
			grid[i][j][1] = ' '; //create grid
		}
	}
}

bool View :: get_subscripts(int &ix, int &iy, Cart_Point location) //Check to see if the Object is within the defined grid.
{
	Cart_Vector subscripts = (location - origin) / scale; //calculating subscripts
	ix = subscripts.x;
	iy = subscripts.y;

	if (ix <= size && iy <= size)
	{
		return true;
	}

	else
	{
		cout << "An object is outside the display." << endl;
		return false;
	}
}

void View :: plot(Game_Object * ptr) //plots pointed to object in the proper cell of the grid
{
    int x = 0; 
    int y = 0;

    Cart_Point location = ptr->get_location();
    bool good = get_subscripts(x, y, location);

   	if(good)
   	{
    	if (grid[x][y][0] == '.' && grid[x][y][1] == ' ')
     	{
       		ptr->drawself(grid[x][y]);
   		}
   		
   		else //if spot is occupied replace with a *
     	{
      		grid[x][y][0] = '*';
      		grid[x][y][1] = ' ';
      	}

     }
}

void View :: draw() //outputs the grid array. lovely
{
	int maxval = scale * size - scale; //20
	for (int i = size, j = 0; i > 0;)
	{
		int val = maxval - (j * scale); //axis value
		char tens = '0' + (val / 10) % 10; //creating axis
		char ones = '0' + val % 10;

		if(val >= 10)
		{
			grid[0][i][0] = tens; //x
			grid[0][i][1] = ones; //x

			grid[i][0][0] = tens; //y
			grid[i][0][1] = ones; //y
		}
		else
		{
			grid[i][0][0] = ones;
			grid[0][i][0] = ones;
		}

		grid[i-1][0][0] = ' '; //spaces between numbers
		grid[0][i-1][0] = ' '; //spaces between numbers

		i = i-2;
		j = j+2;

	}

	for(int i = size; i >= 0; i--) //rows
	{
		for(int j = 0; j<= size; j++) //columns
		{
			for(int k = 0; k <= 1; k++) //3D
				cout << grid[j][i][k];
		}

		cout << endl;
	}	


}