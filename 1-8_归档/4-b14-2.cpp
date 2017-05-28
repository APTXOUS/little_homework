/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
#include<iomanip>
using namespace std;

void hn(int n, char a, char b, char c)
{
	static double num=0;
	if (n == 1)
	{
		num++;
		cout << setiosflags(ios::right) << setw(5) << num;
		cout << ": ";
		cout << n << "#" << " " << a << "---->" << c << endl;

	}
	else
	{
		n--;
		hn(n, a, c, b);
		num++;
		cout << setiosflags(ios::right) << setw(5) << num;
		cout << ": ";
		cout << n + 1 << "#" << " " << a << "---->" << c << endl;
		hn(n, b, a, c);
	}
}
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (n < 0)
		{
			cout << "error";
			return 0;
		}
		else
			break;
	}
	hn(n, 'A', 'B', 'C');
	return 0;
}