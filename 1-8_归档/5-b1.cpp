/*1650254 ��Ң�� ��1*/
#include<iostream>
#include<iomanip>
using namespace std;
void print(int i, int j, int a[10][10])
{
	if (j == 0)
		cout << setw(40 - 3 * i) << a[i][j];
	else
		cout << setw(6) << a[i][j];




}
int main()
{
	int a[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (i == 0 || j == 0)
				a[i][j] = 1;
			else if (i == 1)
				a[i][j] = 1;
			else if (j == i)
				a[i][j] = 1;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			print(i, j, a);
		}
		cout << endl;
	}
	return 0;




}