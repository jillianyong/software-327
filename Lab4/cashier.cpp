#include "cashier.h"

using namespace std;

double tip(double total, double percent)
{
	double tipamount;
	tipamount = total * (percent/100);

	return tipamount;

}

double tax(double amount, char kind)
{
	double taxamount;
	if(kind == 'f')
	{
		taxamount = amount * 0.09;
	}
	else if(kind == 'l')
	{
		taxamount = amount * 0.12;
	}

	return taxamount;
}

double split(double total, int people)
{
	double perperson;
	perperson = total/people;

	return perperson;
}
