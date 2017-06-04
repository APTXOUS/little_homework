#pragma once
/*1650254 尤尧寅 计算机一班*/
#pragma once
#include <iostream>

using namespace std;

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
public:
	/* 根据需要定义所需的成员函数、友元函数等 */
	Date(int, int, int);
	Date();
	Date(int time);
	void set(int y, int m = 1, int d = 1);
	void get(int &, int &, int &);
	void show();
	operator int();
	int operator +(Date &b);
	int operator -(Date &b);
	Date operator +(int);
	Date operator -(int);
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	friend istream& operator>>(istream &, Date &);
	friend ostream& operator<<(ostream &, Date &);
	friend bool operator <(Date&, Date&);
	friend bool operator >(Date&, Date&);
	friend bool operator <=(Date&, Date&);
	friend bool operator >=(Date&, Date&);
	friend bool operator ==(Date&, Date&);
};
/* 如果有其它全局函数需要声明，写于此处 */

/* 如果有需要的宏定义、只读全局变量等，写于此处 */
const int month_day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int month_day_leap[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };