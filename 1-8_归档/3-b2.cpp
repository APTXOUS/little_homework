/* 1650254 计1 尤尧寅 */
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
	cout <<"万位："<< q << '\n' <<"千位："<< w << '\n' << "百位：" << e << '\n' << "十位：" << r << '\n' << "个位：" << t << endl;
	return 0;
}
