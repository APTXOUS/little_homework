/*1650254 º∆1 ”»“¢“˙*/
#include<iostream>
using namespace std;
int main()
{
	double x, temp1,temp2,temp3;
	double right=1, left=0;
	double y;
	x = 1;
	while(1)
	{
		y = x;
		x = (right + left)/2;
		temp1 = 2 * x*x*x - 9 * x*x + 12 * x - 3;
		temp2 = 2 * right*right*right - 9 * right*right + 12 * right - 3;
		temp3 = 2 * left*left*left - 9 * left*left + 12 * left - 3;
		if (temp1*temp2 < 0)
			left = x;
		if (temp1*temp3 < 0)
			right = x;
		if (fabs(y-x) < 1e-5)
			break;
	}
	cout << x << endl;
	return 0;
}