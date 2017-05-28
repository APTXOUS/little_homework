/*1650254 计1 尤尧寅*/
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
		cout << "不是一元二次方程";
	de = b*b - 4 * a*c;
	if (de < 0)
	{
		cout << "有两个虚根" << endl;
		x1 = sqrt(-de) / a;
		x2 = b / a;
		cout << "x1=" << x2 << "+" << x1 << "i" << endl;
		cout << "x2=" << x2 << "-" << x1 << "i" << endl;
	}
	else
	{
		if(de==0)
		{
			cout << "有两个相等实根" << endl;
			x1 = (-b) / (2 * a);
			cout << x1 << " " <<x1;
		}
		else
		{
			cout << "有两个不等实根" << endl;
			x1 = (-b + sqrt(de)) / (2 * a);
			x2 = (-b - sqrt(de)) / (2 * a);
			cout << x1 << " " << x2;
		}
	}
	return 0;
}