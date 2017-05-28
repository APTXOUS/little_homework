/*1650254 ÓÈÒ¢Òú ¼Æ1*/
#include<iostream>
using namespace std;
int main()
{
	double a[15] = { -1,3,4,32,45,66,78,90,123,456,789,9999 };
	double b;
	while (1)
	{
		cin >> b;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else
			break;
	}
	double temp;
	for (int i = 0; i < 12; i++)
	{
		if (i == 0)
		{
			if (b < a[i])
			{
				for (int j = 12; j >= 0; j--)
					if (j == 0)
						a[j] = b;
					else
						a[j] = a[j - 1];
				break;
			}
		}
		else if(i == 10)
		{
			if (b >= a[10])
				a[11] = b;
		}
		else
		{
			if (b >= a[i] && b < a[i + 1])
			{
				temp = a[i + 1];
				a[i+1] = b;
				b = temp;
			}
		}
	}
	for (int i = 0; i < 12; i++)
		cout << a[i] << " ";
	return 0;




}