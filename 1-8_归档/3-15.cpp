/*1650254 计1 尤尧寅*/ 
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
	cout << "最大公约数为" << b << endl;
	sum = (m*n) / b;
	cout << "最小公倍数为" << sum << endl;
	return 0;
}