/*1650254 ��1 ��Ң��*/
#include<iostream>
using namespace std;
int main()
{
	double a;
	double temp;
	double sum = 0;;
	cin >> a;
	a = a + 0.001;
	temp = int(a / 50);
	a -= temp * 50;
	sum += temp;
	if (temp != 0)
		cout << "50Ԫ*" << temp << " ";
	temp = int(a / 20);
	a -= temp * 20;
	sum += temp;
	if (temp != 0)
		cout << "20Ԫ*" << temp << " ";
	temp = int(a / 10);
	a -= temp * 10;
	sum += temp;
	if (temp != 0)
		cout << "10Ԫ*" << temp << " ";
	temp = int(a / 5);
	a -= temp * 5;
	sum += temp;
	if (temp != 0)
		cout << "5Ԫ*" << temp << " ";
	temp = int(a / 1);
	a -= temp * 1;
	sum += temp;
	if (temp != 0)
		cout << "1Ԫ*" << temp << " ";
	temp = int(a / 0.5);
	a -= temp * 0.5;
	sum += temp;
	if (temp != 0)
		cout << "5��*" << temp << " ";
	temp = int(a / 0.1);
	a -= temp * 0.1;
	sum += temp;
	if (temp != 0)
		cout << "1��*" << temp << " ";
	temp = int(a / 0.05);
	a -= temp * 0.05;
	sum += temp;
	if (temp != 0)
		cout << "5��*" << temp << " ";
	temp = int(a / 0.02);
	a -= temp * 0.02;
	sum += temp;
	if (temp != 0)
		cout << "2��*" << temp << " ";
	temp = int(a / 0.01);
	a -= temp * 0.01;
	sum += temp;
	if (temp != 0)
		cout << "1��*" << temp << " ";
	cout << "\n" << "������Ϊ" << sum << endl;
	return 0;
}