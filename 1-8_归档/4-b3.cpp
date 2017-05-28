/* 1650254 º∆1 ”»“¢“˙ */
#include<iostream>
#include <iomanip>  
using namespace std;
void daxie(int num, int flag_of_zero)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//¥À±Íº« ≤√¥“‚Àº«Î◊‘––Àºøº
			cout << "¡„";
		break;
	case 1:
		cout << "“º";
		break;
	case 2:
		cout << "∑°";
		break;
	case 3:
		cout << "»˛";
		break;
	case 4:
		cout << "À¡";
		break;
	case 5:
		cout << "ŒÈ";
		break;
	case 6:
		cout << "¬Ω";
		break;
	case 7:
		cout << "∆‚";
		break;
	case 8:
		cout << "∞∆";
		break;
	case 9:
		cout << "æ¡";
		break;
	default:
		cout << "error";
		break;
	}
}
int main()
{
	int q, w, e, r, t, y, u, i, o, p, s, d;
	double a;
	int count = 0;
	int flag_of_zero = 0;
	while (1)
	{
		cin >> a;
		if (cin.fail())
		{
			if (a <= 9999999999.99&&a >= 0)
				break;
			cout << " ‰»Î¥ÌŒÛ«Î÷ÿ–¬ ‰»Î" << endl;
			cin.clear();
			cin.ignore();
		}
		else
			if (a <= 9999999999.99&&a >= 0)
				break;
	}

	a = a + 0.001;
	q = (int)(a / 1000000000);
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
	daxie(q, flag_of_zero);
	if (q != 0)
	{
		cout << " ∞";
		count = 0;
	}
	else
		count++;
	daxie(w, flag_of_zero);
	if (w != 0)
	{
		flag_of_zero = 1;
		count = 0;
	}
	else
	{
		flag_of_zero = 0;
		count++;
	}
	if (q != 0 || w != 0)
	{
		cout << "“⁄";
		count = 0;
	}
	if (e == 0)
	{
		if (r == 0)
			flag_of_zero = 0; 
		else
			flag_of_zero = 1;
	}
	if(count!=0)
		flag_of_zero = 0;
	daxie(e, flag_of_zero);
	if (e != 0)
	{
		cout << "«™";
		count = 0;
	}
	if (r == 0)
	{
		if (t == 0)
			flag_of_zero = 0;
		else
			flag_of_zero = 1;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(r, flag_of_zero);
	if (r != 0)
	{
		cout << "∞€";
		count = 0;
	}
	if (t == 0)
	{
		if (y == 0)
			flag_of_zero = 0;
		else
			flag_of_zero = 1;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(t, flag_of_zero);
	if (t != 0)
	{
		cout << " ∞";
		count = 0;
	}
	if (y == 0)
	{
		flag_of_zero = 0;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(y, flag_of_zero);
	if (y != 0)
	{
		flag_of_zero = 1;
		count = 0;
	}
	if (e != 0 || r != 0 || t != 0 || y != 0)
	{
		cout << "ÕÚ";
		flag_of_zero = 1;
	}
	if (u == 0)
	{
		if (i == 0)
			flag_of_zero = 0;
		else
			flag_of_zero = 1;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(u, flag_of_zero);
	if (u != 0)
	{
		cout << "«™";
		count = 0;
	}
	if (i == 0)
	{
		if (o == 0)
			flag_of_zero = 0;
		else
			flag_of_zero = 1;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(i, flag_of_zero);
	if (i != 0)
	{
		cout << "∞€";
		count = 0;
	}
	if (o == 0)
	{
		if (p == 0)
			flag_of_zero = 0;
		else
			flag_of_zero = 1;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(o, flag_of_zero);
	if (o != 0)
	{
		cout << " ∞";
		count = 0;
	}
	if (p == 0)
	{
		flag_of_zero = 0;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(p, flag_of_zero);
	if (p != 0)
	{
		flag_of_zero = 1;
		count = 0;
	}
	if (q != 0 || w != 0 || e != 0 || r != 0 || t != 0 || y != 0 || u != 0 || i != 0 || o != 0 || p != 0)
	{
		cout << "‘≤";
	}
	else
		if (s == 0 && d == 0)
		{
			flag_of_zero = 1;
			daxie(p, flag_of_zero);
			cout << "‘≤";
		}
	if (s == 0)
	{
		if (d == 0)
			flag_of_zero = 0;
		else
			flag_of_zero = 1;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(s, flag_of_zero);
	if (s != 0)
	{
		cout << "Ω«";
		count = 0;
	}
	if (d == 0)
	{
		flag_of_zero = 0;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(d, flag_of_zero);
	if (d != 0)
		cout << "∑÷";
	if ((s == 0 && d == 0) || (s != 0 && d == 0))
		cout << "’˚";
	cout << endl;
	return 0;
}
