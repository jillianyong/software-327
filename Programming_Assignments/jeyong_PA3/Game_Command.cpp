/*EC327 Programming Assignment 3
The Space Race: Exploring the Void in C++ - Episode 1*/

/*The Game_Command represents the Controller of the MVC pattern and provides 
multiple functions that interpret user input in order to perform the 
appropriate actions.*/

#include "Game_Command.h"
#include "Model.h"
#include "Person.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Game_Object.h"
#include "Cart_Point.h"
#include <iostream>

using namespace std;

void do_move_command(Model& mod) //Move, m
{
	int id_num;
	double x;
	double y;
	cin >> id_num >> x >> y;
	Cart_Point destination = Cart_Point(x,y);
	
	//cout << "Moving " << id_num << " to " << "(" << destination.x << "," << destination.y << ")." << endl;
	
	mod.get_Person_ptr(id_num)->start_moving(destination);
}

void do_work_command(Model& mod) //Start supplying at oxygen depot, w
{
	int id_num;
	int oxy_id;
	cin >> id_num >> oxy_id;

	Oxygen_Depot* oxylife = mod.get_Oxygen_Depot_ptr(oxy_id);
	Astronaut* astro = mod.get_Person_ptr(id_num);

	cout << "Astronaut " << id_num << " supplying from Oxygen Depot " << oxy_id << "." << endl;
	static_cast<Astronaut*>(astro)->start_supplying(oxylife);
}

void do_deposit_command(Model& mod) //Depositing Moonstones, d
{
	int id_num;
	int space_id;
	cin >> id_num >> space_id;

	Space_Station* spacedepos = mod.get_Space_Station_ptr(space_id);
	Astronaut* astro = mod.get_Person_ptr(id_num);
	
	cout << "Astronaut "<<id_num<<" depositing at Space Station "<< space_id << "." << endl;
	static_cast<Astronaut*>(astro)->start_depositing(spacedepos);

}

void do_stop_command(Model& mod) //Stop, s
{
	int id_num;
	cin >> id_num;
	cout << "A1: Stopped." << endl;

	mod.get_Person_ptr(id_num)->stop();
}

void do_lock_command(Model& mod) //Lock in at station, l
{
	int id_num;
	int space_id;
	cin >> id_num >> space_id;
	
	Space_Station* gospace = mod.get_Space_Station_ptr(space_id);
	Astronaut* astro = mod.get_Person_ptr(id_num);
	
	cout << "Astronaut " << id_num << " locking in at Space Station " << space_id << "." << endl;
	static_cast<Astronaut*>(astro)->go_to_station(gospace);
	//mod.update();

}

void do_go_command(Model& mod) //Advance one time step, g
{
	cout << "Advancing one tick." << endl;

	mod.update();

	cout << "Time: " << mod.get_time() << endl; //*let's pretend that "Time" from Inception starts playing*
	
	mod.show_status();
}

void do_run_command(Model& mod) //Advance one time step & repeat, r
{
	cout << "Advancing to next event." << endl;

	for (int i = 0; i < 5; i++)
	{
		if(mod.update()) //Update function returns true, stop loop.
		{
			break;
		}
	}

	cout << "Time: " << mod.get_time() << endl; //*let's pretend that "Time" from Inception starts playing*
	
	//mod.update();
	mod.show_status();
}

void do_quit_command(Model& mod) //Quit, q
{
	cout << "Terminating program." << endl;
}

void main_loop(Model& mod, View& views) //Separate function that collects input required for each command
{
	cout << "Time: " << mod.get_time() << endl;
	mod.show_status();

	Game_Object* oxydep1 = mod.get_Oxygen_Depot_ptr(1);
	Game_Object* oxydep2 = mod.get_Oxygen_Depot_ptr(2);
	Game_Object* astro1 = mod.get_Person_ptr(1);
	Game_Object* astro2 = mod.get_Person_ptr(2);
	Game_Object* spacestation1 = mod.get_Space_Station_ptr(1);
	Game_Object* spacestation2 = mod.get_Space_Station_ptr(2);

	char command;
	while (command != 'q')
	{
		//View
		views.clear(); //clear view

		views.plot(astro1);
		views.plot(astro2);

		views.plot(spacestation1);
		views.plot(spacestation2);

		views.plot(oxydep1);
		views.plot(oxydep2);

		views.draw();

		//inputs
		cout << "Enter command: ";
		cin >> command;
	
		switch (command)
		{
			case 'm':
			{
				do_move_command(mod);
				break;
			}

			case 'w':
			{
				do_work_command(mod);
				break;
			}

			case 'd':
			{
				do_deposit_command(mod);
				break;
			}

			case 's':
			{
				do_stop_command(mod);
				break;
			}

			case 'l':
			{
				do_lock_command(mod);
				break;
			}

			case 'g':
			{
				do_go_command(mod);
				break;
			}

			case 'r':
			{
				do_run_command(mod);
				break;
			}

			default:
				cout << "Terminating program." << endl;
				break;
			
		}
	}
}