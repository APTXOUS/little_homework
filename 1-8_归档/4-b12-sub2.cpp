/*1650254 计1 尤尧寅*/
#include<iostream>
#include<cmath>
using namespace std;
void f2(double a, double b, double c, double de)
{
	double x1;
	double x2;
	cout << "有两个虚根" << endl;
	x1 = sqrt(-de) / a;
	x2 = b / a;
	if (x2 != 0)
	{
		cout << "x1=" << x2 << "+" << x1 << "i" << endl;
		cout << "x2=" << x2 << "-" << x1 << "i" << endl;
	}
	else
	{
		cout << "x1=" << "+" << x1 << "i" << endl;
		cout << "x2=" << "-" << x1 << "i" << endl;
	}
}