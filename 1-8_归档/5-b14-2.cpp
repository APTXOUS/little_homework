/*1650254 计1 尤尧寅*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include <iomanip>  
using namespace std;
char chistr[] = "零壹贰叁肆伍陆柒捌玖";
string result;
char dan[] = "亿万仟佰拾圆角分整";
void daxie(int num, int flag_of_zero, int i)
{
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
		{
			result += chistr[2 * num];
			result += chistr[2 * num + 1];
		}
		break;
	case 1:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 2:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 3:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 4:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 5:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 6:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 7:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 8:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	case 9:
		result += chistr[2 * num];
		result += chistr[2 * num + 1];
		break;
	default:
		cout << "error";
		break;
	}
}
int main()
{
	int q, w, e, r, t, y, u, i, o, p, s, d;
	int ins = 0;
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
			cout << "输入错误请重新输入" << endl;
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
	daxie(q, flag_of_zero, ins);
	if (q != 0)
	{
		result += dan[8];
		result += dan[9];
		count = 0;
	}
	else
		count++;
	daxie(w, flag_of_zero, ins);
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
		result += dan[0];
		result += dan[1];
		count = 0;
	}
	if (e == 0)
	{
		if (r == 0)
			flag_of_zero = 0;
		else
			flag_of_zero = 1;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(e, flag_of_zero, ins);
	if (e != 0)
	{
		result += dan[4];
		result += dan[5];
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
	daxie(r, flag_of_zero, ins);
	if (r != 0)
	{
		result += dan[6];
		result += dan[7];
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
	daxie(t, flag_of_zero, ins);
	if (t != 0)
	{
		result += dan[8];
		result += dan[9];
		count = 0;
	}
	if (y == 0)
	{
		flag_of_zero = 0;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(y, flag_of_zero, ins);
	if (y != 0)
	{
		flag_of_zero = 1;
		count = 0;
	}
	if (e != 0 || r != 0 || t != 0 || y != 0)
	{
		result += dan[2];
		result += dan[3];
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
	daxie(u, flag_of_zero, ins);
	if (u != 0)
	{
		result += dan[4];
		result += dan[5];
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
	daxie(i, flag_of_zero, ins);
	if (i != 0)
	{
		result += dan[6];
		result += dan[7];
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
	daxie(o, flag_of_zero, ins);
	if (o != 0)
	{
		result += dan[8];
		result += dan[9];
		count = 0;
	}
	if (p == 0)
	{
		flag_of_zero = 0;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(p, flag_of_zero, ins);
	if (p != 0)
	{
		flag_of_zero = 1;
		count = 0;
	}
	if (q != 0 || w != 0 || e != 0 || r != 0 || t != 0 || y != 0 || u != 0 || i != 0 || o != 0 || p != 0)
	{
		result += dan[10];
		result += dan[11];
	}
	else
		if (s == 0 && d == 0)
		{
			flag_of_zero = 1;
			daxie(p, flag_of_zero, ins);
			result += dan[10];
			result += dan[11];
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
	daxie(s, flag_of_zero, ins);
	if (s != 0)
	{
		result += dan[12];
		result += dan[13];
		count = 0;
	}
	if (d == 0)
	{
		flag_of_zero = 0;
	}
	if (count != 0)
		flag_of_zero = 0;
	daxie(d, flag_of_zero, ins);
	if (d != 0)
	{
		result += dan[14];
		result += dan[15];
	}
	if ((s == 0 && d == 0) || (s != 0 && d == 0))
	{
		result += dan[16];
		result += dan[17];
	}
	result += '\0';
	cout << result << endl;
	
	return 0;
}
