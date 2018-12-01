//Statistics program that includes getMedian() and getLargest() for PA 2 Question 2

#include <iostream>

using namespace std;

//Function that finds the median of the array
void getMedian(int myArray[], int size)
{
	int temparray;
	int median;
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size - i - 1; j++)//loop sorts array into small to large
		{
			if(myArray[j] < myArray[j+1])
			{
				temparray = myArray[j];
				myArray[j] = myArray[j+1];
				myArray[j+1] = temparray;
			}

		if (size % 2 == 1) //calculating median for odd numbers in array
		{
			median = (myArray[i/2] + myArray[i/2] - 1) / 2.0; 
		}
		
		else //calculating median for even numbers in array
		{
			median = myArray[i/2];
		}

	}
	cout << "Median is: " << median << endl;

}

//Function that finds the largest number in the array
void getLargest(int myArray[], int size)
{
	//loop that stores largest number into myArray[0]
	for (int i = 1; i < size; ++i)
	{
		if(myArray[0] < myArray[i]) //check if next number is larger
			myArray[0] = myArray[i]; //if yes, store in the myArray[0]
	}

	cout << "Largest is: " << myArray[0] << endl;
}