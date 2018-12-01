//Programming Assignment 2, Question 2

#include <iostream>
#include "statistics.h"
#include "FileFunctions.h"
#include <cmath>
#include <fstream>

using namespace std;

//Function doubles the size of the array and reverses the numbers

int * DoubleAndReverse (int *list, int size)
{
	for (int i = 0, j = size - 1; i < j; i++, j--)
	{
		int temporary = list[j];
		list [j] = list[i];
		list[i] = temporary;
	}

	return list;
}

//Function that prints the array
void printArrays(const int* list, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
}

int main()
{
	int *myArray;
	myArray = new int[1000]; //Preallocating array to maximium size
	int size = 0;

	/*int readfilename;
	cout << "Please state the filename you want to read to: ";
	cin >> readfilename;
	int writefilename;
	cout << "Please state the filename you want to write to: ";
	cin >> writefilename;
	*/

	int n;
	//cout << "Please enter a value for N: "; //Prompt User for number of random variables
	//cin >> n;
	int m;
	//cout << "Please enter a value for M: "; //Prompt User for max value
	//cin >> m;

	WriteRandomData(5, 20, "data.txt"); //N = 5, M = 20; Randomly chosen numbers, can be changed.

	ReadData("numbers.txt", size, myArray);
	
	cout << "Writing file: data.txt" << endl;

	cout << "Reading file: numbers.txt" << endl;

	cout << "Array Size is: " << size <<endl;
	
	cout << "Doubled and Reversed is [";
	printArrays(myArray, size);
	int * newarray = DoubleAndReverse(myArray, size);
	printArrays(newarray, size);
	cout << "\b" << "]" << endl;

	getMedian(myArray, size);

	getLargest(myArray, size);

	delete myArray; //Prevent any memory leaks

	return 0;
}