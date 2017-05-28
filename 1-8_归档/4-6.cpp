/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
using namespace std;
double fx(double x)
{
	return(1 * x*x*x + 2 * x*x + 3 * x + 4);
}
double fx1(double x)
{
	return(3 * x*x + 4 * x + 3 );
}
double die(double x1, double x2, double x3)
{
	double temp;
	temp = x1 - x2 / x3;
	if (fabs(x1 - temp) < 1e-6)
	{
		return temp;
	}
	else
	{
		return die(temp, fx(temp), fx1(temp));
	}
}
int main()
{
	double x;
	double r;
	x = 1;
	r = die(1, fx(1), fx(1));
	cout << r << endl;
	return 0;
	
}