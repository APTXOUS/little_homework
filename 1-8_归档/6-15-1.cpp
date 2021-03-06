/*1650254 尤尧寅 计1*/
#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;
const int num_of_people = 4;
const int num_of_subjects = 5;

double cal_ping(int (*p)[num_of_subjects],int a)
{
	double result=0;
	for (int i = 0; i < num_of_people; i++)
		result += *(*(p + i) + a);
	return result / num_of_people;
}
void search_bujige(int (*p)[num_of_subjects])
{
	int flag = 0;
	for (int i = 0; i < num_of_people; i++)
	{
		int count = 0;
		for (int j = 0; j < num_of_subjects; j++)
		{
			if (*(*(p + i) + j) < 60)
			{
				count++;
			}
		}
		if (count >= 2)
		{
			flag = 1;
			cout << "学号为";
			cout << i + 1;
			cout << "的同学有两门及两门以上不及格科目。" << endl;
			cout << "其全部课程成绩为：" << endl;
			double sum=0;
			for (int m = 0; m < num_of_subjects; m++)
			{
				cout << *(*(p + i) + m) << " ";
				sum += *(*(p + i) + m);
			}
			sum = sum / num_of_subjects*1.0;
			cout << endl;
			cout << "平均成绩为:" << sum << endl;
		}
	}
	if (flag == 0)
		cout << "没有两门及两门以上不及格的学生" << endl;
}
void search_youxiu(int(*p)[num_of_subjects])
{
	int flag = 0;
	for (int i = 0; i < num_of_people; i++)
	{
		int count = 0;
		double sum = 0;
		for (int j = 0; j < num_of_subjects; j++)
		{
			if (*(*(p + i) + j) >= 85)
				count++;
			sum += *(*(p + i) + j);
		}
		sum = sum / num_of_subjects*1.0;
		if (count == num_of_subjects || sum > 90 || fabs(sum - 90) < 1e-7)
		{
			cout << i + 1 << "号学生" << endl;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "没有这样的学生" << endl;
}
int main()
{
	int a[num_of_people][num_of_subjects];
	for (int i = 0; i < num_of_people; i++)
	{
		cout << "请输入" << i+1 << "同学的"<< num_of_subjects<<"门课成绩:";
		for (int j = 0; j < num_of_subjects; j++)
		{
			while (1)
			{
				cin >> *(*(a + i) + j);
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "输入错误，请重新输入：";
				}
				else if (*(*(a + i) + j) >= 0 && *(*(a + i) + j) <= 100)
					break;
				else
					cout << "输入错误，请重新输入此门成绩：";
			}
		}
		cout << endl;
	}
	cout << "第一门课的平均分为" << cal_ping(a, 0) << endl;
	search_bujige(a);
	cout << "平均成绩在90分以上或全部课程在85以上的学生为：" << endl;
	search_youxiu(a);

	return 0;
}