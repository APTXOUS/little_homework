/*1650254 计1 尤尧寅*/
#include<iostream>
#include<iomanip>
using namespace std;
int zeller(int year, int month, int day)
{
	int c, y, m, d, w;
	if (month == 1 || month == 2)
	{
		c = (int)((year - 1) / 100);
		y = (int)((year - 1) % 100);
		m = month + 12;
	}
	else
	{
		c = (int)(year / 100);
		y = (int)(year % 100);
		m = month;
	}
	d = day;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0)
		while (w < 0)
			w = w + 7;
	w = w % 7;
	return w;
}
void calender(int a, int b)
{
	int w;
	int tap;
	int day = 0;
	w = zeller(a, b, 1);
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		tap = 1;
	else
		tap = 0;
	if (tap == 1 && b == 2)
	{
		day = 0;
		for (int i = 1; i <= w; i++)
		{
			cout << "    ";
			day++;
			cout << "    ";
		}
		for (int i = 1; i <= 29; i++)
		{
			cout << setiosflags(ios::right) << setw(4) << i;
			cout << "    ";
			day++;
			if (day == 7)
			{
				cout << endl;
				day = 0;
			}
		}
	}
	else
	{
		if (b == 2)
		{
			day = 0;
			for (int i = 1; i <= w; i++)
			{
				cout << "    ";
				day++;
				cout << "    ";
			}
			for (int i = 1; i <= 28; i++)
			{
				cout << setiosflags(ios::right) << setw(4) << i;
				cout << "    ";
				day++;
				if (day == 7)
				{
					cout << endl;
					day = 0;
				}
			}
		}
		if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
		{
			day = 0;
			for (int i = 1; i <= w; i++)
			{
				cout << "    ";
				day++;
				cout << "    ";
			}
			for (int i = 1; i <= 31; i++)
			{
				cout << setiosflags(ios::right) << setw(4) << i;
				cout << "    ";
				day++;
				if (day == 7)
				{
					cout << endl;
					day = 0;
				}
			}
		}
		else if (b == 4 || b == 6 || b == 9 || b == 11)
		{
			day = 0;
			for (int i = 1; i <= w; i++)
			{
				cout << "    ";
				day++;
				cout << "    ";
			}
			for (int i = 1; i <= 30; i++)
			{
				cout << setiosflags(ios::right) << setw(4) << i;
				cout << "    ";
				day++;
				if (day == 7)
				{
					cout << endl;
					day = 0;
				}
			}
		}
	}
}
void title(int a,int b)
{
	cout << a << "年" << b << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
}
int reng(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
		return 1;
	else
		return 0;
}
int main()
{
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (a >= 1900 && a <= 2100)
		{
			if (b >= 1 && b <= 12)
				break;
			else
				cout << "输入错误请重新输入（1900-2100之间的月份）：" << endl;
		}
		else
			cout << "输入错误请重新输入（1900-2100之间的月份）：" << endl;
	}
	title(a,b);
	calender(a,b);
	return 0;
	
}