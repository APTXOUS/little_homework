/* 1650254 ��Ң�� �����һ�� */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS2015��Ϊunsafe�ĺ���
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

struct tj_time {
	int tj_year;		//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;		//��ʾ��(1-28/29/30/31)
	int tj_hour;		//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */
void changesecondintohour(struct tj_time *inputdata, int *input_time)
{
	(*inputdata).tj_minute = *input_time / 60;
	(*inputdata).tj_second = *input_time % 60;
	if ((*inputdata).tj_minute >= 60)
	{
		(*inputdata).tj_hour = (*inputdata).tj_minute / 60;
		(*inputdata).tj_minute = (*inputdata).tj_minute % 60;
	}
	if ((*inputdata).tj_hour >= 24)
	{
		(*inputdata).tj_day += (*inputdata).tj_hour / 24;
		(*inputdata).tj_hour = (*inputdata).tj_hour % 24;
	}
	if ((*inputdata).tj_day >= 32)
	{
		while (1)
		{
			if ((*inputdata).tj_month == 1 || (*inputdata).tj_month == 3 || (*inputdata).tj_month == 5 || (*inputdata).tj_month == 7 || (*inputdata).tj_month == 8 || (*inputdata).tj_month == 10 || (*inputdata).tj_month == 12 || (*inputdata).tj_month == 12)
			{
				if ((*inputdata).tj_day > 31)
				{
					(*inputdata).tj_day -= 31;
					if ((*inputdata).tj_month == 12)
					{
						(*inputdata).tj_year++;
						(*inputdata).tj_month = 1;
					}
					else
						(*inputdata).tj_month++;
				}
				else
					break;
			}
			if ((*inputdata).tj_month == 4 || (*inputdata).tj_month == 6 || (*inputdata).tj_month == 9 || (*inputdata).tj_month == 11)
			{
				if ((*inputdata).tj_day > 30)
				{
					(*inputdata).tj_day -= 30;
					(*inputdata).tj_month++;
				}
				else
					break;
			}
			if ((*inputdata).tj_month == 2)
			{
				if (((*inputdata).tj_year % 4 == 0 && (*inputdata).tj_year % 100 != 0) || ((*inputdata).tj_year % 400 == 0))
				{
					if ((*inputdata).tj_day > 29)
					{
						(*inputdata).tj_day -= 29;
						(*inputdata).tj_month++;
					}
					else
						break;
				}
				else
				{
					if ((*inputdata).tj_day > 28)
					{
						(*inputdata).tj_day -= 28;
						(*inputdata).tj_month++;
					}
					else
						break;
				}
			}
		}
	}
}
/* ����ϵͳ��ת����������ʾ����������ֵת��Ϊ�뱾�����ƵĽṹ�岢��� */
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
	struct tm *tt;	//struct tm Ϊϵͳ����Ľṹ��

	tt = localtime(&input_time);	//localtimeΪϵͳ����

									/* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
	cout << tt->tm_year + 1900 << '-' << tt->tm_mon + 1 << '-' << tt->tm_mday << ' ' << tt->tm_hour << ':' << tt->tm_min << ':' << tt->tm_sec << endl;

	return;
}

/* ������� */
void tj_time_output(struct tj_time *tp)
{
	/* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
	cout << tp->tj_year << '-' << tp->tj_month << '-' << tp->tj_day << ' ' << tp->tj_hour << ':' << tp->tj_minute << ':' << tp->tj_second << endl;
}

struct tj_time *tj_time_convert(int input_time)
{
	static struct tj_time result;	//���徲̬�ֲ���������׼��

									/* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
	result.tj_year = 1970;
	result.tj_month = 1;
	result.tj_day = 1;
	result.tj_hour = 0;
	result.tj_minute = 0;
	result.tj_second = 0;
	input_time += 8 * 60 * 60;
	changesecondintohour(&result, &input_time);
	/* ʵ�ֹ��̽��� */


	return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
}

int main()
{
	int test_time[] = { 1, 123456789, 349823021, 987654321, 1202990407, 1216468807, 1250312143, 1272636353, 1326193524, 1336549496, 1392837128, 1625675376, 2052743737 };
	int i;
	struct tj_time *tp;

	for (i = 0; i < sizeof(test_time) / sizeof(int); i++) {
		cout << "��ʱ����        ��" << test_time[i] << endl;
		cout << "ϵͳת���Ľ��  ��";
		system_time_output(test_time[i]);

		cout << "�Զ���ת���Ľ����";
		tp = tj_time_convert(test_time[i]);
		tj_time_output(tp);

		cout << endl << "���س�������" << endl;
		getchar();
	}

	if (1) {
		struct tj_time *tp;
		int t = (int)time(NULL);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ����������time_t Ϊϵͳ�����64λ������

		cout << "ϵͳת���ĵ�ǰϵͳʱ�䣺";
		system_time_output(t);

		cout << "�Զ���ת����ǰϵͳʱ�䣺";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		cout << endl << "���س�������" << endl;
		getchar();
	}

	return 0;
}
