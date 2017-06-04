/*1650254 尤尧寅 计算机一班*/
#include <iostream>
#include "11-b1-date.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
Date::Date(int y, int m, int d) :year(y), month(m), day(d)
{
	if (y < 1900 || y>2099)
	{
		year = 1900;
		month = 1;
		day = 1;
	}
	else
	{
		year = y;
		if (m < 1 || m>12)
		{
			year = 1900;
			month = 1;
			day = 1;
		}
		else
		{
			month = m;
			if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			{
				if (month_day_leap[month - 1] < d)
				{
					year = 1900;
					month = 1;
					day = 1;
				}
				else
					day = d;
			}
			else
			{
				if (month_day[month - 1] < d)
				{
					year = 1900;
					month = 1;
					day = 1;
				}
				else
					day = d;

			}
		}
	}
}
Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}
void Date::set(int y, int m, int d)
{
	if (!y)
		y = year;
	if (!m)
		m = month;
	if (!d)
		d = day;
	*this = Date(y, m, d);
}
void Date::get(int &y, int &m, int &d)
{
	y = year;
	m = month;
	d = day;
}
void Date::show()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
Date::Date(int time)
{
	year = 1900;
	month = 1;
	if (time <= 1)
		day = 1;
	else
		day = time;
	if (day >= 32)
	{
		while (1)
		{
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 || month == 12)
			{
				if (day > 31)
				{
					day -= 31;
					if (month == 12)
					{
						year++;
						month = 1;
					}
					else
						month++;
				}
				else
					break;
			}
			if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 30)
				{
					day -= 30;
					month++;
				}
				else
					break;
			}
			if (month == 2)
			{
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				{
					if (day > 29)
					{
						day -= 29;
						month++;
					}
					else
						break;
				}
				else
				{
					if (day > 28)
					{
						day -= 28;
						month++;
					}
					else
						break;
				}
			}
		}
	}
	if (year > 2099)
	{
		year = 2099;
		month = 12;
		day = 31;
	}
	if (year < 1900)
	{
		year = 1900;
		month = 1;
		day = 1;
	}
}
Date::operator int()
{
	int time = 0;
	for (int i = 1900; i < year; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			time += 366;
		else
			time += 365;
	}
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		for (int i = 0; i < month - 1; i++)
			time += month_day_leap[i];
	else
		for (int i = 0; i < month - 1; i++)
			time += month_day[i];
	time += day;
	return time;
}
int Date::operator +(Date &b)
{
	int time;
	time = int(*this) + int(b);
	return time;
}
int Date::operator -(Date &b)
{
	int time;
	time = int(*this) - int(b);
	return time;
}
Date Date::operator +(int x)
{
	int time;
	time = int(*this) + x;
	return  Date(time);
}
Date Date::operator -(int x)
{
	int time;
	time = int(*this) - x;
	return  Date(time);
}
Date Date::operator++()
{
	int time;
	time = int(*this);
	*(this) = Date(time + 1);
	return *this;
}
Date Date::operator++(int)
{
	int time;
	time = int(*this);
	*(this) = Date(time + 1);
	return Date(time);
}
Date Date::operator--()
{
	int time;
	time = int(*this);
	*(this) = Date(time - 1);
	return *this;
}
Date Date::operator--(int)
{
	int time;
	time = int(*this);
	*(this) = Date(time - 1);
	return Date(time);
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
istream& operator >> (istream &in, Date &a)
{
	int y, m, d;
	in >> y >> m >> d;
	a = Date(y, m, d);
	return in;
}
ostream& operator << (ostream &out, Date &a)
{
	out << a.year << "年" << a.month << "月" << a.day << "日" << endl;
	return out;
}

bool operator < (Date &a, Date &b)
{
	return (int(a) < int(b));
}
bool operator > (Date &a, Date &b)
{
	return (int(a) > int(b));
}
bool operator <= (Date &a, Date &b)
{
	return (int(a) <= int(b));
}
bool operator >= (Date &a, Date &b)
{
	return (int(a) >= int(b));
}
bool operator == (Date &a, Date &b)
{
	return (int(a) == int(b));
}