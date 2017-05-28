/*1650254 计1 尤尧寅*/
#include<iostream>
#include<fstream>
using namespace std;
int search1(int a[][9],int flag,int num)
{
	if (num == 9)
		return 1;
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (a[flag][i] == num)
			{
				return search1(a, flag, num + 1);
			}
		}
		return -1;
	}
}
int search2(int a[][9],int flag,int num)
{
	if (num == 9)
		return 1;
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (a[i][flag] == num)
			{
				return search2(a, flag, num + 1);
			}
		}
		return - 1;
	}
}
int search3(int a[][9], int flag1,int flag2, int num)
{
	if (num == 9)
		return 1;
	else
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			if (a[flag1+i][flag2+j] == num)
			{
				return search3(a, flag1, flag2, num + 1);
			}
		return -1;
	}
}
int main()
{
	int a[9][9];
	int temp1=0, temp2=0, temp3=0;
	ifstream fin;
	fin.open("shudu.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			fin >> a[i][j];

	for (int i = 0; i < 9; i++)
		temp1 += search1(a, i, 1);
	for (int i = 0; i < 9; i++)
		temp2 += search2(a, i, 1);
	for (int i = 0; i < 9; i = i + 3)
		for (int j = 0; j < 9; j = j + 3)
			temp3 += search3(a, i, j, 1);
	
	if (temp1 == 9 && temp2 == 9 && temp3 == 9)
		cout << "满足数独的解" << endl;
	else
		cout << "不满足数独的解" << endl;
	fin.close();

	return 0;
}