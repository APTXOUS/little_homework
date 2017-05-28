/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
#include<iomanip>
using namespace std;
void sort(int score[])
{
	int max;
	int temp;
	for (int i = 0; i <90; i++)
	{
		max = i;
		for (int j = i; j <90; j++)
			if (score[max] < score[j])
				max = j;

		temp = score[max];
		score[max] = score[i];
		score[i] = temp;
	}
}
int main()
{
	int score[100] = { 0, 77, 52, 71, 12, 24, 91, 32, 71, 67,
					 37, 9, 48, 16, 52, 44, 20, 3, 13, 59,
					 3, 22, 87, 55, 29, 49, 65, 91, 5, 61,
					 97, 92, 94, 96, 80, 86, 23, 56, 51, 35,
					 38, 35, 4, 50, 94, 100, 1, 94, 10, 38,
					 8, 44, 57, 67, 65, 22, 71, 41, 80, 68,
					 53, 52, 57, 51, 54, 59, 23, 27, 23 ,51,
					 82, 30, 34, 69, 97, 58, 92, 58, 46, 92,
					 70, 35, 97, 92, 49, 76, 79, 88, 93, 18 };
	sort(score);
	int temp=score[0];
	int num = 1;
	int flag=0;
		for (int i = 0; i < 90; i++)
		{
			cout <<setw(3)<< score[i];
			if (score[i] == temp)
			{
				cout << "    " << num << endl;
				flag++;
			}
			else
			{
				num += flag;
				cout << "    " << num << endl;
				temp = score[i];
				flag = 1;
			}

		}
	return 0;
}