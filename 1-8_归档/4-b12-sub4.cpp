/*1650254 ��1 ��Ң��*/
#include<iostream>
#include<cmath>
using namespace std;
void f4(double a, double b, double c, double de)
{
	double x1;
	double x2;
	cout << "����������ʵ��" << endl;
	x1 = (-b + sqrt(de)) / (2 * a);
	x2 = (-b - sqrt(de)) / (2 * a);
	cout << x1 << " " << x2;
}