/*1650254 计1 尤尧寅*/
#include<iostream>
using namespace std;
int main()
{
	int a, b, c, tap = -1, answer=0;
	cin >> a >> b >> c;
	if (b > 12|| b < 1)
	{
		cout << "输入错误" << endl;
		return 0;
	}
	if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && ((c > 31)||( c < 1 )))
	{
		cout << "输入错误" << endl;
		return 0;
	}
	if ((b == 4 || b == 6 || b == 9 || b == 11) && ((c > 30)||(c<1)))
	{
		cout << "输入错误" << endl;
		return 0;
	}
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		tap = 1;
	else
		tap = 0;
	if (tap==1)
	{
		if (b == 1)
			answer = c;
		if (b == 2)
			answer = 31 + c;
		if (b == 3)
			answer = 31 + 29 + c;
		if (b == 4)
			answer = 31 + 29 + 31 + c;
		if (b == 5)
			answer = 31 + 29 + 31 + 30 + c;
		if (b == 6)
			answer = 31 + 29 + 31 + 30 + 31 + c;
		if (b == 7)
			answer = 31 + 29 + 31 + 30 + 31 + 30 + c;
		if (b == 8)
			answer = 31 + 29 + 31 + 30 + 31 + 30 + 31 + c;
		if (b == 9)
			answer = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + c;
		if (b == 10)
			answer = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c;
		if (b == 11)
			answer = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c;
		if (b == 12)
			answer = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c;
		cout << answer << endl;
	}
	if(tap==0)
	{
		if (b == 1)
			answer = c;
		if (b == 2)
			answer = 31 + c;
		if (b == 3)
			answer = 31 + 28 + c;
		if (b == 4)
			answer = 31 + 28 + 31 + c;
		if (b == 5)
			answer = 31 + 28 + 31 + 30 + c;
		if (b == 6)
			answer = 31 + 28 + 31 + 30 + 31 + c;
		if (b == 7)
			answer = 31 + 28 + 31 + 30 + 31 + 30 + c;
		if (b == 8)
			answer = 31 + 28 + 31 + 30 + 31 + 30 + 31 + c;
		if (b == 9)
			answer = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + c;
		if (b == 10)
			answer = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + c;
		if (b == 11)
			answer = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + c;
		if (b == 12)
			answer = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + c;
		cout << answer << endl;
	}
	return 0;
}