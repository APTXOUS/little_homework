/*1650254 ��1 ��Ң��*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << j << "��" << i << "=";
			cout << setiosflags(ios::right) << setw(2) << j*i << "  ";
		}
		cout << endl;
	}
	return 0;
}