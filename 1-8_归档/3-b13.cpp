/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
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
			cout << j << "¡Á" << i << "=";
			cout << setiosflags(ios::right) << setw(2) << j*i << "  ";
		}
		cout << endl;
	}
	return 0;
}