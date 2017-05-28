/*1650254 计1 尤尧寅*/
#include<iostream>
#include<cmath>
using namespace std;
double square(double x[],double y[],int n)
{
	double s=0;
	for (int i = 1; i < n-1; i=i+1)
	{
		s+=fabs((1.0 / 2.0)*(x[0]*y[i] +x[i]*y[i+1] + x[i+1]*y[0] - y[0]*x[i] - y[i]*x[i+1] - y[i+1]*x[0]));
	}
	return  s;
}
void print(int n)
{
	if (n == 4)
		cout << "不是四边形" << endl;
	else if (n == 5)
		cout << "不是五边形" << endl;
	else if (n == 6)
		cout << "不是六边形" << endl;
	else 
		cout << "不是七边形" << endl;

}
int cal(double x, double y, double a, double b, double c)
{
	double temp;
	temp = (a*x + b*y + c);
	if (fabs(temp) < 1e-16)
	{
		return 0;
	}
	else if (temp > 0)
		return 1;
	else 
		return -1;
}
int line(double x1,double y1,double x2,double y2,double x[],double y[],int n)
{
	double a;
	a = -(y1-y2);
	double count_gongxian = 0;
	double b;
	b = (x1 - x2);
	double c;
	c = -a*x1 - b*y1;
	int temp_fu = 0, temp_zheng = 0;
	for (int i = 0; i < n; i++)
	{
		if ((x[i] == x1&&y[i] == y1) || (x[i] == x2&&y[i] == y2))
		{
			continue;
		}
		else
		{
			if (cal(x[i], y[i], a, b, c) == 0)
				count_gongxian++;
			else if (cal(x[i], y[i], a, b, c) < 0)
			{
				temp_fu++;
			}
			else
				temp_zheng++;
		}
	}
	if (count_gongxian == 0)
	{
		if (temp_fu == n-2 &&temp_zheng == 0)
			return 1;
		else if (temp_fu == 0 && temp_zheng == n-2)
			return 1;
		else
			return 0;
	}
	else
	{
		return -1;
	}

}
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (cin.fail())
		{
			cin.ignore();
			cin.clear();
		}
		else if (n >= 4 && n <= 7)
			break;
	}
	double x[8], y[8];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			i--;
		}
	}
	int temp, count = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			temp = line(x[i], y[i], x[i + 1], y[i + 1], x, y, n);
		else
			temp = line(x[i], y[i], x[0], y[0], x, y, n);
		if (temp == -1)
		{
			print(n);
			break;
		}
		else if (temp == 0)
		{
			cout << "不是凸多边形" << endl;
			break;
		}
		else
			count++;
	}
	if (count == n)
	{
		cout << "是凸多边形,面积为";
		cout << square(x, y, n) << endl;
	}
	system("pause");
	return 0;





}