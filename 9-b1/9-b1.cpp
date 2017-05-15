/*1650254 ��Ң�� �����һ��*/
#include <iostream>
using namespace std;

class Days {
private:
	int year;
	int month;
	int day;
	int is_leap_year();  //�ж��Ƿ����꣬�ǣ�����1  /   �񣺷���0
public:
	int calc_days();     //�����ǵ���ĵڼ���
						 /* ������Բ���������Ҫ�����Ա�����Ķ��壬�������� */
	Days(int, int, int);
};

/* �˴��������Ա����������ʵ�� */
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
/* main������׼�� */
int main()
{
	if (1) {
		Days d1(2012, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2012, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2011, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}
	
	return 0;
}
