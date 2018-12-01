//contains the functions WriteRandomData and ReadData for PA2 Question 2

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

using namespace std;

//Function that writes random integers to a text file
void WriteRandomData(int N, int M, const char *filename)
{
	ofstream output;
	output.open(filename); //open the file

	srand(time(NULL)); //pseudo-random number generator

	for(int i = 0; i < N; i++) //making N random integers from 0 to M
	{
		int randnum = rand() % (M + 1); 
		output << randnum << endl;
	}
	output.close();
}

//Function that reads data from a specified text file and finds the size
void ReadData(const char *filename, int &size, int myArray[])
{
	ifstream input;
	input.open(filename); //open the file
	int numbers;
	size = 0; //size of array is originally 0

	while (input >> numbers)
	{
		myArray[size] = numbers; //storing the numbers into array
		size++; //modify the size to account for the new values in the array
	}
	input.close(); //close the file
}