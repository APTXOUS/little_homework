/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	if (a < b)
		a = b;
	else
		a = a;
	return a;
}
int max(int a,int b,int c)
{
	if (a < b)
		a = b;
	else
		a = a;
	if (a < c)
		a = c;
	else
		a = a;
	return a;
}
int max(int a,int b,int c,int d)
{
	if (a < b)
		a = b;
	else
		a = a;
	if (a < c)
		a = c;
	else
		a = a;
	if (a < d)
		a = d;
	else
		a = a;
	return a;
}
int main()
{
	int num, a, b, c, d, n;
	while (1)
	{
		cin >> num;
		if (cin.fail())
		{
			cout << "ÊäÈë´íÎó" << endl;
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (num != 2 && num != 3 && num != 4)
			return 0;
		n = num;
		cin >> a;
		n--;
		if (cin.fail())
		{
			cout << "ÊäÈë´íÎó" << endl;
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (a < 0 )
			return 0;
		else if (n == 0)
			break;
		cin >> b;
		n--;
		if (cin.fail())
		{
			cout << "ÊäÈë´íÎó" << endl;
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (b < 0)
			return 0;
		else if (n == 0)
			break;
		cin >> c;
		n--;
		if (cin.fail())
		{
			cout << "ÊäÈë´íÎó" << endl;
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (c < 0)
			return 0;
		else if (n == 0)
			break;
		cin >> d;
		n--;
		if (cin.fail())
		{
			cout << "ÊäÈë´íÎó" << endl;
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (d < 0)
			return 0;
		else if (n == 0)
			break;
	

	}
	if(num==2)
	{ 
		cout << max(a, b);
	}
	else if (num == 3)
	{
		cout << max(a, b, c);
	}	
	else if (num == 4)
	{
		cout << max(a, b, c, d);
	}

	return 0;




}