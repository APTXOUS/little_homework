/*1650254 ��1 ��Ң��*/ 
#include<iostream>
using namespace std;
int main()
{
	int m, n;
	int a, b, c = -1, sum;
	cin >> m >> n;
	if (m > n)
	{
		a = m;
		b = n;
	}
	else
	{
		a = n;
		b = m;
	}
	while (c != 0)
	{
		c = b%a;
		b = a;
		a = c;
	}
	cout << "���Լ��Ϊ" << b << endl;
	sum = (m*n) / b;
	cout << "��С������Ϊ" << sum << endl;
	return 0;
}