/*1650254 ��1 ��Ң��*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a, b, c;
	double de, answer;
	double x1,x2;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-15)
		cout << "����һԪ���η���";
	de = b*b - 4 * a*c;
	if (de < 0)
	{
		cout << "���������" << endl;
		x1 = sqrt(-de) / a;
		x2 = b / a;
		cout << "x1=" << x2 << "+" << x1 << "i" << endl;
		cout << "x2=" << x2 << "-" << x1 << "i" << endl;
	}
	else
	{
		if(de==0)
		{
			cout << "���������ʵ��" << endl;
			x1 = (-b) / (2 * a);
			cout << x1 << " " <<x1;
		}
		else
		{
			cout << "����������ʵ��" << endl;
			x1 = (-b + sqrt(de)) / (2 * a);
			x2 = (-b - sqrt(de)) / (2 * a);
			cout << x1 << " " << x2;
		}
	}
	return 0;
}