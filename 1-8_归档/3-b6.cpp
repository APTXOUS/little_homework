/*1650254 ��1 ��Ң��*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double ax, ay;
	double bx, by;
	double cx, cy;
	double square;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;
	square = fabs((1.0 / 2.0)*(ax*by + bx*cy + cx*ay - ay*bx - by*cx - cy*ax));
	if (square == 0)
		cout << "���ܹ���������";
	else
		cout <<"���������Ϊ"<< square << endl;
	return 0;
}