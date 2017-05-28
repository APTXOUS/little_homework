/*1650254 尤尧寅 计1*/
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
	cout << "请输入m,n:";
	while (1)
	{
		cin >> m >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误" << endl;
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
				cout << "类型不正确，请重新输入"<<endl;
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