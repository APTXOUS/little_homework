/*1650254 ╪ф1 схр╒рЗ*/
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	double x,y;
	double a;
	cin >> a;
	x = a;
	y = 1;
	while(1)
	{
		y = x;
		x = (1.0 / 2) * (x + a / x);
		if (fabs(x - y) < 1e-5)
			break;
	}
	cout << x;
	return 0;
}