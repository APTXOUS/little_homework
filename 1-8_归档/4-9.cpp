/*1650254 ��1 ��Ң��*/
#include<iostream>
using namespace std;
void hn(int n, char a, char b, char c)
{
	if (n == 1)
		cout << "��" << a << "�������Ƶ�" << c << endl;
	else 
	{
		n--;
		hn(n, a, c, b);
		cout << "��" << a << "�������Ƶ�" << c << endl;
		hn(n, b, a, c);
	}
}
int main()
{

	double x;
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
	hn(n, 'A', 'B','C' );
	return 0;
}