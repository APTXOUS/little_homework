/* 1650254 计1 尤尧寅 */
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

	cout << "十亿位: " << q;
	cout << endl;
	cout << "亿位: " << w;
	cout << endl;
	cout << "千万位: " << e;
	cout << endl;
	cout << "百万位: " << r;
	cout << endl;
	cout << "十万位: " << t;
	cout << endl;
	cout << "万位: " << y;
	cout << endl;
	cout << "千位: " << u;
	cout << endl;
	cout << "百亿位: " << i;
	cout << endl;
	cout << "十位: " << o;
	cout << endl;
	cout << "个位: " << p;
	cout << endl;
	cout << "十分位: " << s;
	cout << endl;
	cout << "百分位: " << d;
	return 0;
}
