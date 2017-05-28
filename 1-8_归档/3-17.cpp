/*1650254 ╪ф1 схр╒рЗ*/
#include<iostream>
using namespace std;
int main() 
{
	int a, sn = 0, n, temp;
	cin >> a >> n;
	int i, j;
	temp = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
			temp = temp * 10 + a;
		sn += temp;
		temp = 0;
	}
	cout << sn;
	return 0;
}