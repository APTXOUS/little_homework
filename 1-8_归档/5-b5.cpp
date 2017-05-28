/*1650254 计1 尤尧寅*/
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
void sort(int score[],int num)
{
	int max;
	int temp;
	for (int i = 0; i <num; i++)
	{
		max = i;
		for (int j = i; j <num; j++)
			if (score[max] < score[j])
				max = j;

		temp = score[max];
		score[max] = score[i];
		score[i] = temp;
	}
}
int main()
{
	int score[1002];
	int i = 0;
	ifstream fin;
	fin.open("score.dat", ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		system("pause");
		return -1;
	}
	while (1)
	{
		fin >> score[i];
		if (score[i] == -1)
			break;
		i++;
	}
	i = i - 1;
	sort(score,i);
	int temp = score[0];
	int num = 1;
	int flag = 0;
	for (int j = 0; j < i; j++)
	{
		cout << setw(3) << score[j];
		if (score[j] == temp)
		{
			cout << "    " << num << endl;
			flag++;
		}
		else
		{
			num += flag;
			cout << "    " << num << endl;
			temp = score[j];
			flag = 1;
		}

	}
	fin.close();
	return 0;
}