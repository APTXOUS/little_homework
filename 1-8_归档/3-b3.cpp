/* 1650254 ��1 ��Ң�� */
#include <iostream>
#include <iomanip>  
using namespace std;

int main()
{
	int q, w, e, r, t, y, u, i, o, p, s, d;
	double a;
	cin >> a;
	a = a + 0.001;
	q =(int)( a / 1000000000);
	a = a - q * 1000000000.0;
	w = (int)(a / 100000000);
	a = a - w * 100000000.0;
	e = (int)(a / 10000000);
	a = a - e * 10000000.0;
	r = (int)(a / 1000000);
	a = a - r * 1000000.0;
	t = (int)(a / 100000);
	a = a - t * 100000.0;
	y = (int)(a / 10000);
	a = a - y * 10000.0;
	u = (int)(a / 1000);
	a = a - u * 1000.0;
	i = (int)(a / 100);
	a = a - i * 100.0;
	o = (int)(a / 10);
	a = a - o * 10.0;
	p = (int)(a / 1.0);
	a = a - p * 1;
	s = (int)(a / 0.1);
	a = a - s * 0.1;
	d = (int)(a / 0.01);

	cout << "ʮ��λ: " << q;
	cout << endl;
	cout << "��λ: " << w;
	cout << endl;
	cout << "ǧ��λ: " << e;
	cout << endl;
	cout << "����λ: " << r;
	cout << endl;
	cout << "ʮ��λ: " << t;
	cout << endl;
	cout << "��λ: " << y;
	cout << endl;
	cout << "ǧλ: " << u;
	cout << endl;
	cout << "����λ: " << i;
	cout << endl;
	cout << "ʮλ: " << o;
	cout << endl;
	cout << "��λ: " << p;
	cout << endl;
	cout << "ʮ��λ: " << s;
	cout << endl;
	cout << "�ٷ�λ: " << d;
	return 0;
}
