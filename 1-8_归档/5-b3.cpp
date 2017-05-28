/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
using namespace std;
int reng(int a)
{
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		return 1;
	else
		return 0;
}
int day(int a, int b, int c, int d)
{
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int num = 0;
	if (d)
	{
		month[1] = 29;
		for (int i = 0; i < b - 1; i++)
			num += month[i];
		return num + c;
	}
	else
	{
		for (int i = 0; i < b - 1; i++)
			num += month[i];
		return num + c;
	}



}
int main()
{
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "ÊäÈë´íÎó";
			return 0;
		}
		else if (b >= 1 && b <= 12)
		{
			if (reng(a))
			{
				if (b == 2 && c <= 29)
					break;
				else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && ((c <= 31) && (c >= 1)))
				{
					break;
				}
				else if ((b == 4 || b == 6 || b == 9 || b == 11) && ((c <= 30) && (c >= 1)))
				{
					break;
				}
			}
			else
			{
				if (b == 2 && c <= 28)
					break;
				else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && ((c <= 31) && (c >= 1)))
				{
					break;
				}
				else if ((b == 4 || b == 6 || b == 9 || b == 11) && ((c <= 30) && (c >= 1)))
				{
					break;
				}
			}
		}
		else
		{
			cout << "ÊäÈë´íÎó";
			return 0;
		}
	}
	cout<<day(a, b, c,reng(a));
	system("pause");
	return 0;
}