/*1650254 ��1 ��Ң��*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, c;
	int tap;
	int i, j, day;
	while (1)
	{ 
	cout << "���������(2000 - 2030)���·�(1 - 12):";
	cin >> a >> b;
	if ((a < 2000 || a>2030) || (b < 1 || b>12))
		cout << "����Ƿ�������������" << endl;
	else
		break;
	}
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		tap = 1;
	else
		tap = 0;
	while (1)
	{
		cout << "������" << a << "��" << b << "��1�յ�����(0-6��ʾ������-������) :";
		cin >> c;
		if (c < 0 || c>6)
			cout << "����Ƿ�������������" << endl;
		else
			break;
	}
	cout << a << "��" << b << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	if (tap == 1 && b == 2)
	{
		day = 0;
		for (i = 1; i <= c; i++)
		{
			cout << "    ";
			day++;
			cout << "    ";
		}
		for (i = 1; i <= 29; i++)
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
		if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
		{
			day = 0;
			for (i = 1; i <= c; i++)
			{
				cout << "    ";
				day++;
				cout << "    ";
			}
			for (i = 1; i <= 31; i++)
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
		else if (b == 2 || b == 4 || b == 6 || b == 9 || b == 11)
		{
			day = 0;
			for (i = 1; i <= c; i++)
			{
				cout << "    ";
				day++;
				cout << "    ";
			}
			for (i = 1; i <= 30; i++)
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
	cout << endl;
	return 0;
}