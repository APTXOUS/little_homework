/*1650254 ��Ң�� �����һ��*/
#include<iostream>
#include<iomanip>
using namespace std;
const int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int month_reng[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
struct time1
{
	int year;//���
	int month;//�·�
	int day;//����
};
int day(time1 temp)
{
	int num = 0;
	if ((temp.year % 4 == 0 && temp.year % 100 != 0) || (temp.year % 400 == 0))
	{
		for (int i = 0; i < temp.month - 1; i++)
			num += month_reng[i];
	}
	else
		for (int i = 0; i < temp.month - 1; i++)
			num += month[i];
	return num + temp.day;
}
int main()
{
	struct time1 fun;
	cout << "���Դ�����������:" << endl;
	while (1)//�ж�������ȷ��
	{
		cin >> fun.year >> fun.month >> fun.day;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "����������������룡" << endl;
		}
		else if (fun.month <= 0 || fun.month > 12)
			cout << "�·��������" << endl;
		else if (fun.day <= 0)
			cout << "�����������" << endl;
		else if ((fun.year % 4 == 0 && fun.year % 100 != 0) || (fun.year % 400 == 0))
			if (fun.day > month_reng[fun.month - 1])
				cout << "�����������!" << endl;
			else
				break;
		else if (!((fun.year % 4 == 0 && fun.year % 100 != 0) || (fun.year % 400 == 0)))
			if (fun.day > month[fun.month - 1])
				cout << "�����������!" << endl;
			else
				break;
		else
			break;
	}
	cout << day(fun) << endl;
	return 0;
}