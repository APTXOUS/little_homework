/*1650254 ��1 ��Ң��*/
#include<iostream>
#include<cmath>
using namespace std;
void f1()
{
	cout << "����һԪ���η���" << endl;
}
void f2(double a,double b,double c,double de)
{
	double x1;
	double x2;
	cout << "���������" << endl;
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
void f3(double a, double b, double c, double de)
{
	double x1;
	cout << "���������ʵ��" << endl;
	x1 = (-b) / (2 * a);
	cout << x1 << " " << x1;
}
void f4(double a, double b, double c, double de)
{
	double x1;
	double x2;
	cout << "����������ʵ��" << endl;
	x1 = (-b + sqrt(de)) / (2 * a);
	x2 = (-b - sqrt(de)) / (2 * a);
	cout << x1 << " " << x2;
}
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
		f1(); system("pause");
		return 0;
	}
	de = b*b - 4 * a*c;
	if (de < 0)
	{
		f2(a,b,c,de); system("pause");
		return 0;
	}
	else
	{
		if (de == 0)
		{
			f3(a,b,c,de); system("pause");
			return 0;
		}
		else
		{
			f4(a,b,c,de); system("pause");
			return 0;
		}
	}
}