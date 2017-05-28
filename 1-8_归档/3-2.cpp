//*1650254 计算机1班 尤尧寅*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double r = 1.5;
	int h = 3;
	double CIRCLE, SQUARE, BSQUARE, BV, YUANZHUMIANJI;
	double pi = 3.1415926;
	CIRCLE = pi * 2 * r;
	SQUARE = pi * r * r;
	BSQUARE = 4 * pi*r*r;
	BV = 4.00*pi*r*r*r / 3.00;
	YUANZHUMIANJI = SQUARE*h;
	cout << setiosflags(ios::fixed) << setprecision(2)<< "圆周长是" << CIRCLE << endl;
	cout << "圆面积是"<< SQUARE << endl;
	cout << "球面面积是" << BSQUARE << endl;
	cout << "球体积是"<< BV << endl;
	cout << "圆柱体积是" << YUANZHUMIANJI << endl;
	return 0;
}