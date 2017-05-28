/*1650254 计1 尤尧寅*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	extern void f1();
	extern void f2(double a, double b, double c, double de);
	extern void f3(double a, double b, double c, double de);
	extern void f4(double a, double b, double c, double de);
	double a, b, c;
	double de;
	while (1)
	{
		cin >> a >> b >> c;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入错误请重新输入" << endl;
		}
		else
			break;
	}
	if (fabs(a) < 1e-15)
	{
		f1();
		return 0;
	}
	de = b*b - 4 * a*c;
	if (de < 0)
	{
		f2(a, b, c, de);
		return 0;
	}
	else
	{
		if (de == 0)
		{
			f3(a, b, c, de);
			return 0;
		}
		else
		{
			f4(a, b, c, de);
			return 0;
		}
	}
}