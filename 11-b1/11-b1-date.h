#pragma once
/*1650254 ��Ң�� �����һ��*/
#pragma once
#include <iostream>

using namespace std;

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������ */
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
/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */

/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
const int month_day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int month_day_leap[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };