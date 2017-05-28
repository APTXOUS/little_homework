/* 1650254 ╪ф1 схр╒рЗ */
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double x, y;
	double height=0;
	cin >>x >> y;
	if (fabs(x) < 0.0000000000000001 || fabs(y) < 0.0000000000000001)
		height = 0;
	if (x > 0 && y > 0 && y<=3-x)
		height = 1;
	if (x < 0 && y > 0 && y<=3+x)
		height = 2;
	if (x < 0 && y < 0 && y>=-x-3)
		height = 3;
	if (x > 0 && y < 0 && y>=x-3)
		height = 4;
	cout << height;
	return 0;
}