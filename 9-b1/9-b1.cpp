/*1650254 尤尧寅 计算机一班*/
#include <iostream>
using namespace std;

class Days {
private:
	int year;
	int month;
	int day;
	int is_leap_year();  //判断是否闰年，是：返回1  /   否：返回0
public:
	int calc_days();     //计算是当年的第几天
						 /* 下面可以补充其它需要的类成员函数的定义，数量不限 */
	Days(int, int, int);
};

/* 此处给出类成员函数的体外实现 */
int Days::is_leap_year()
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;

}
Days::Days(int y, int m, int d) :year(y), month(m), day(d)
{
}

int Days::calc_days() 
{
	const int month_com[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const int month_reng[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month <= 0 || month > 12)
		return -1;
	else if (day <= 0)
		return -1;
	else if (is_leap_year())
		if (day > month_reng[month - 1])
			return -1;
		else
			;
	else if (!is_leap_year())
		if (day > month_com[month - 1])
			return -1;
		else
			;
	else
		;
	int num = 0;
	if (is_leap_year())
	{
		for (int i = 0; i < month - 1; i++)
			num += month_reng[i];
	}
	else
		for (int i = 0; i < month - 1; i++)
			num += month_com[i];
	return num +day;
}
/* main函数不准动 */
int main()
{
	if (1) {
		Days d1(2012, 3, 18);
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2012, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}
	
	return 0;
}
