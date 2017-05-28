/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
#include<cmath>
using namespace std;
int reng(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
		return 1;
	else
		return 0;
}
int zeller(int year, int month, int day)
{
	int c, y, m, d, w;
	if (month == 1 || month == 2)
	{
		c = (int)((year-1) / 100);
		y = (int)((year-1) % 100);
		m = month + 12;
	}
	else
	{
		c = (int)(year / 100);
		y = (int)(year % 100);
		m = month;
	}
	d = day;
	w = y + y / 4 + c / 4 - 2*c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0)
		while (w < 0)
			w = w + 7;
	w = w % 7;
	return w;
}
int main()
{
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (cin.fail())
		{
			cout << "ÊäÈë´íÎóÇëÖØĞÂÊäÈë" << endl;
			cin.clear();
			cin.ignore();
		}
		if (cin.good())
		{
			if (a >= 1900 && a <= 2100)
			{
				if (b > 12 || b < 1)
				{
					cout << "ÊäÈë´íÎó" << endl;
				}
				else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && ((c > 31) || (c < 1)))
				{
					cout << "ÊäÈë´íÎó" << endl;
				}
				else if ((b == 4 || b == 6 || b == 9 || b == 11) && ((c > 30) || (c < 1)))
				{
					cout << "ÊäÈë´íÎó" << endl;
				}
				else if (reng(a) && b == 2)
				{
					if (c >= 1 && c <= 29)
						break;
					else
						cout << "ÊäÈë´íÎó" << endl;
				}
				else if (!reng(a) && b == 2)
				{
					if (c >= 1 && c <= 28)
						break;
					else
						cout << "ÊäÈë´íÎó" << endl;
				}
				else
					break;
			}
			else
				cout << "ÊäÈë´íÎó" << endl;
		}
	}
	switch (zeller(a,b,c))
	{
		case 0:
			cout << "ÈÕ" << endl;
			break;
		case 1:
			cout << "Ò»" << endl;
			break;
		case 2:
			cout << "¶ş" << endl;
			break;
		case 3:
			cout << "Èı" << endl;
			break;
		case 4:
			cout << "ËÄ" << endl;
			break;
		case 5:
			cout << "Îå" << endl;
			break;
		case 6:
			cout << "Áù" << endl;
			break;

	}
	return 0;
}