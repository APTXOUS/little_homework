/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void input(int saolei[][26])
{
	srand((unsigned int)time(0));
	for (int i = 1; i <= 50; i++)

	{
		int x = (rand() % 10);
		int y = (rand() % 26);
		if (saolei[x][y] == 0)
		{
			saolei[x][y] = 1;
		}
		else
			i--;
	}
}
void search(int saolei[][26],int temp[][26])
{
	for(int i=0;i<10;i++)
		for (int j = 0; j < 26; j++)
		{
			if (i == 0 && j == 0)
			{
				temp[i][j]= saolei[0][1] + saolei[1][1] + saolei[1][0];
			}
			else if (i == 9 && j == 0)
			{
				temp[i][j] = saolei[8][0] + saolei[8][1] + saolei[9][1];
			}
			else if (i == 9 && j == 25)
			{
				temp[i][j] = saolei[9][24] + saolei[8][24] + saolei[8][25];
			}
			else if (i == 0 && j == 25)
			{
				temp[i][j] = saolei[0][24] + saolei[1][24] + saolei[1][25];
			}
			else if (i == 0 && j != 0 && j != 25)
			{
				temp[i][j] = saolei[i][j - 1] + saolei[i][j + 1] + saolei[i + 1][j] + saolei[i + 1][j + 1] + saolei[i + 1][j - 1];
			}
			else if (i == 9 && j != 0 && j != 25)
			{
				temp[i][j] = saolei[i][j - 1] + saolei[i][j + 1] + saolei[i - 1][j] + saolei[i - 1][j + 1] + saolei[i - 1][j - 1];
			}
			else if (j == 0 && i != 0 && i != 9)
			{
				temp[i][j] = saolei[i - 1][j] + saolei[i + 1][j] + saolei[i - 1][j + 1] + saolei[i][j + 1] + saolei[i + 1][j + 1];
			}
			else if (j == 25 && i != 0 && i != 9)
			{
				temp[i][j] = saolei[i - 1][j] + saolei[i + 1][j] + saolei[i - 1][j - 1] + saolei[i][j - 1] + saolei[i + 1][j - 1];
			}
			else
			{
				temp[i][j] = saolei[i - 1][j] + saolei[i + 1][j] + saolei[i][j + 1] + saolei[i][j - 1] + saolei[i - 1][j - 1] + saolei[i - 1][j + 1] + saolei[i + 1][j + 1] + saolei[i + 1][j - 1];
			}

		}
}
int main()
{

	int saolei[10][26] = { 0 };
	int temp[10][26] = { 0 };
	input(saolei);
	search(saolei, temp);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (saolei[i][j] == 1)
				cout << "*" << " ";
			else
				cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
