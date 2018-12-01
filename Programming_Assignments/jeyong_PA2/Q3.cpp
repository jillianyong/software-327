//Programming Assignment 2, Question 3 - Rhombus Recursion

#include <iostream>
#include <string>

using namespace std;

//Function to format spacing and output
void rows(int userinput, int max)
{
	if (userinput < max)
	{
		cout << userinput << " "; //Spaces in between numbers
		rows(userinput+1, max);
	}
	cout << userinput << " ";
}


//Main PrintRhombus function to determine the size of the rhombus & print accordingly
void PrintRhombus(int userinput, int i = 1)
{
	if(i == 2 * userinput) return;

	int numbers = i < userinput ? i : 2 * userinput - i;
	int space = (userinput - numbers) * 2;
	cout << string(space, ' '); //Spacing to get the rhombus to look like a rhombus
	rows(1, numbers);
	cout << endl;

	PrintRhombus(userinput, i+1); //recursion!
}

int main ()
{
	int userinput;
	cout << "Enter a number [1-9]: ";
	cin >> userinput;

	if (userinput >= 1 && userinput <= 9) //Error check
	{
		PrintRhombus(userinput);
	}

	else
	{
		cout << "Invalid input." << endl;
	}

	return 0;
}