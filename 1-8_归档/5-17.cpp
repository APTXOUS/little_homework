/*1650254 ��1 ��Ң��*/
#include<iostream>
using namespace std;
int main()
{
	char name[10][1000];
	char number[10][100];
	int score[10];
	cout << "������10λѧ��������ѧ�ųɼ���" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> name[i] >> number[i] >> score[i];
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			i--;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (score[i] < 60)
			cout << name[i] <<" "<< number[i]<<" " << score[i] << endl;
	}
	return 0;
}