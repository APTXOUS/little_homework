/*1650254 ��1 ��Ң��*/
#include<iostream>
#include<cmath>
#include"4-b12.h"
using namespace std;
int main()
{
	double a, b, c;
	double de;
	while (1)
	{
		cin >> a >> b >> c;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "�����������������" << endl;
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