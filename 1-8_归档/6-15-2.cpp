/*1650254 ��Ң�� ��1*/
#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;
const int num_of_students = 4;
const int num_of_subjects = 5;
double cal_ping(int(*p)[num_of_students], int a)
{
	double result = 0;
	for (int i = 0; i < num_of_students; i++)
		result += *(*(p + a) + i);
	return result / num_of_students*1.0;
}
void search_bujige(int(*p)[num_of_students])
{
	int flag = 0;
	for (int i = 0; i < num_of_students; i++)
	{
		int count = 0;
		for (int j = 0; j < num_of_subjects; j++)
		{
			if (*(*(p + j) + i) < 60)
			{
				count++;
			}
		}
		if (count >= 2)
		{
			flag = 1;
			cout << "ѧ��Ϊ";
			cout << i + 1;
			cout << "��ͬѧ�����ż��������ϲ������Ŀ��" << endl;
			cout << "��ȫ���γ̳ɼ�Ϊ��" << endl;
			double sum = 0;
			for (int m = 0; m < num_of_subjects; m++)
			{
				cout << *(*(p + m) + i) << " ";
				sum += *(*(p + m) + i);
			}
			sum = sum / num_of_subjects*1.0;
			cout << endl;
			cout << "ƽ���ɼ�Ϊ:" << sum << endl;


		}
	}
	if (flag == 0)
		cout << "û�����ż��������ϲ������ѧ��" << endl;
}
void search_youxiu(int(*p)[num_of_students])
{
	int flag = 0;
	for (int i = 0; i < num_of_students; i++)
	{
		int count = 0;
		double sum = 0;
		for (int j = 0; j < num_of_subjects; j++)
		{
			if (*(*(p + j) + i) >= 85)
				count++;
			sum += *(*(p + j) + i);
		}
		sum = sum / num_of_subjects*1.0;
		if (count == num_of_subjects || sum > 90 || fabs(sum - 90) < 1e-7)
		{
			cout << i + 1 << "��ѧ��" << endl;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "û��������ѧ��" << endl;
}
int main()
{
	int a[num_of_subjects][num_of_students];
	for (int i = 0; i < num_of_subjects; i++)
	{
		cout << "�������" << i + 1 << "�ſε�ѧ���ɼ�:";
		for (int j = 0; j < num_of_students; j++)
		{
			while (1)
			{
				cin >> *(*(a + i) + j);
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "����������������룺";
				}
				else if (*(*(a + i) + j) >= 0 && *(*(a + i) + j) <= 100)
					break;
				else
					cout << "������������������ѧ���ɼ���";
			}
		}
		cout << endl;
	}
	cout << "��һ�ſε�ƽ����Ϊ" << cal_ping(a, 0) << endl;
	search_bujige(a);
	cout << "ƽ���ɼ���90�����ϻ�ȫ���γ���85���ϵ�ѧ��Ϊ��" << endl;
	search_youxiu(a);

	return 0;
}