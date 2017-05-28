/*1650254 ��Ң�� �����һ��*/
#include<iostream>
using namespace std;
const int num_student = 10;
struct student {
	int no;
	char name[9];
	float score[3];
	float score_cal;
	int queue = 0;
};
void input_student(struct student *inputdata, const int num_input)
{
	for (int i = 1; i <= num_input; i++)
	{
		while (1)
		{
			cout << "�������" << i << "λѧ����ѧ��";
			cin >> (*(inputdata + i - 1)).no;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '/n');
			}
			else
				break;
		}
		cout << "�������" << i << "λѧ��������";
		cin >> (*(inputdata + i - 1)).name;
		for (int j = 0; j < 3; j++)
		{
			while (1)
			{
				cout << "�������" << i << "λѧ���ĵ�" << j + 1 << "�ſγɼ�";
				cin >> (*(inputdata + i - 1)).score[j];
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '/n');
				}
				else
					break;
			}
		}
	}
}
void output_student(struct student *inputdata, const int num_input)
{
	for (int i = 1; i <= num_input; i++)
	{
		float sum = 0;
		for (int j = 0; j < 3; j++)
			sum += (*(inputdata + i - 1)).score[j];
		(*(inputdata + i - 1)).score_cal = sum / 3;
		cout << "��" << i << "λѧ��������ƽ����Ϊ��";
		cout << (*(inputdata + i - 1)).score_cal << endl;
	}
}
void output_highest(struct student *inputdata, const int num_input)
{
	for (int i = 1; i <= num_input; i++)
	{
		int num_queue = 1;
		for (int j = 1; j <= num_input; j++)
			if ((*(inputdata + i - 1)).score_cal < (*(inputdata + j - 1)).score_cal)
				num_queue++;
		(*(inputdata + i - 1)).queue = num_queue;
	}
	cout << "��߷�ͬѧΪ��" << endl;
	for (int i = 1; i <= num_input; i++)
		if ((*(inputdata + i - 1)).queue == 1)
		{
			cout << inputdata[i - 1].no << "   " << inputdata[i - 1].name << endl;
			cout << "���ſγɼ�Ϊ��" << inputdata[i - 1].score[0] << "  " << inputdata[i - 1].score[1] << "  " << inputdata[i - 1].score[2] << endl;
		}
}
int main()
{
	struct student example[num_student];
	input_student(example, num_student);
	output_student(example, num_student);
	output_highest(example, num_student);
	return 0;
}