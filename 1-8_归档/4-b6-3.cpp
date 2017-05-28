/*1650254 计1 尤尧寅*/
#include<iostream>
using namespace std;
int add(int a, int b,int n)
{
	if (n == 3)
		return (a+b);
	else
		return add(b, a + b, --n);
}
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (cin.fail())
		{
			cout << "输入错误请重新输入" << endl;
			cin.clear();
			cin.ignore();
		}
		if (n < 0)
			cout << "输入错误"<<endl;
		else
			break;
	}
	if (n == 0)
		cout << "0";
	else if (n == 1 || n == 2)
		cout << "1";
	else
		cout << add(1, 1, n);

	return 0;




}