/* 1650254 ��1 ��Ң�� */
#include <iostream>
#include <cstdio>
#include <iomanip>  
using namespace std;

int main()
{
	int a;
	int q, w, e, r, t;
	cin >> a;
	q = a / 10000;
	a = a - q * 10000;
	w = a / 1000;
	a = a - w * 1000;
	e = a / 100;
	a = a - e * 100;
	r = a / 10;
	a = a - r * 10;
	t = a;
	cout <<"��λ��"<< q << '\n' <<"ǧλ��"<< w << '\n' << "��λ��" << e << '\n' << "ʮλ��" << r << '\n' << "��λ��" << t << endl;
	return 0;
}
