//Lab 4 Cashier Problem
//Updated Github test
#include <iostream>
#include "cashier.h"
using namespace std;

int main()
{
	double amount;
	cout<<"What is the amount? $";
	cin>>amount;
	char kind;
	cout<<"is it (f) or (l)iquor? ";
	cin>>kind;
	double amountwtax = amount + tax(amount, kind);
	double total = 0;
	total = total + amountwtax;
	char items;
	cout<<"Do you have more items? ";
	cin>>items;
	while(items == 'y')
	{
		cout<<"What is the amount? $";
		cin>>amount;
		cout<<"is it (f) or (l)iquor? ";
		cin>>kind;
		double amountwtax = amount + tax(amount, kind);
		total = total + amountwtax;
		cout<<"Do you have more items? ";
		cin>>items;
	}

	//After user is done inputting items
	int percent;
	cout<<"What percent would you like to tip? ";
	cin>>percent;
	while(percent < 15)
	{
		cout<<"Tip should be greater or equal to 15"<<endl<<"Percent? ";
		cin>>percent;
	}
	if(percent > 20)
	{
		cout<<"clearly you were given great service or you're just hella generous I can't tell"<<endl;
	}
	
	total = total + tip(total, percent);

	//split code
	int people;
	cout<<"How many people are you splitting this with? ";
	cin>>people;
	cout<<"Your total will be $"<<split(total, people)<<" per person."<<endl;

	return 0;

}
