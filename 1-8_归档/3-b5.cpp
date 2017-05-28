/*1650254 计1 尤尧寅 */
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a, b, c, p;
	double square;
	cin >> a >> b >> c;
	if (a + b > c&&b + c > a&&c + a > b)
	{
		p = (a + b + c) / 2;
		square = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << square;
	}
	else
		cout << "此三边无法构成三角形";
	return 0;
}