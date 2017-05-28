/*1650254 ╪ф1 схр╒рЗ*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double e = 1, c;
	double x, temp1,temp2;
	double n, i;
	cin >> x;
	temp1 = 1;
	temp2 = 1;
	n = 1;
	c = 1;
	while (fabs(c) > 1e-6)
	{
		for (i = 1; i <= n; i++)
		{
			temp1 = temp1 * x;
			temp2 = temp2 * i;
		}
		c = (temp1 / temp2);
		e += c;
		n++;
		temp1 = 1;
		temp2 = 1;
	}
	cout << setiosflags(ios::fixed)<<setprecision(7)<< e << endl;
	return 0;
}