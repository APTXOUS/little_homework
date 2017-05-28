/* 1650254 计1 尤尧寅*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
int num = 0;
using namespace std;
int add(int a, int b, int n)
{
	num++;
	if (n == 3)
		return (a + b);
	else
		return add(b, a + b, --n);
}

int main()
{
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&fc_begin);	//获得初始硬件定时器计数

										/* 此处是你的程序开始 */
	int n;
	for (n = 1; n <= 40; n++)
	{
		if (n == 0)
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) <<"0" << endl;
		else if (n == 1 || n == 2)
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << "1" << endl;
		else
		{
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << n;
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << add(1,1,n);
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << num << endl;
			num = 0;
		}
	}
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&fc_end);//获得终止硬件定时器计数
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "时钟频率：" << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "时钟计数：" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "秒" << endl;
	system("pause");
	return 0;
}
