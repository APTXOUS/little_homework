/*1650254 ��Ң�� ��1*/
#include <iostream>
#include<iomanip>
using namespace std;
void move1(int *p, int n, int m)
{
	for (int i = n-m; i< n; i++)
	{
		int temp = *(p + i);
		for (int j = i - 1; j >= (i-n+m); j--)
			*(p + j + 1) = *(p + j);
		*(p + i - n + m) = temp;
	}
}
int main()
{
	int a[20];
	int m, n;
	cout << "������m,n:";
	while (1)
	{
		cin >> m >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�������" << endl;
		}
		else if (m < n && m >= 0 && n>0 && n <= 20)
			break;
	}
	int *p = a;
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			cin >> *(p + i);
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "���Ͳ���ȷ������������"<<endl;
			}
			else
				break;
		}
	}
	move1(p, n,m);
	for (int i = 0; i < n; i++)
		cout << *(p + i) << " ";
	cout << endl;

	return 0;

}