//*1650254 �����1�� ��Ң��*/
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
	cout << setiosflags(ios::fixed) << setprecision(2)<< "Բ�ܳ���" << CIRCLE << endl;
	cout << "Բ�����"<< SQUARE << endl;
	cout << "���������" << BSQUARE << endl;
	cout << "�������"<< BV << endl;
	cout << "Բ�������" << YUANZHUMIANJI << endl;
	return 0;
}