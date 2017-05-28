/*1650254 1班 尤尧寅*/
#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	int f(int x, int y, int z);
	cin >> a >> b >> c;
	c = f(a, b, c);
	cout << c << endl;
	return 0;
}
int f(int x, int y, int z)
{
	int m;
	if (x < y)m = x;
	else m = y;
	if (z < m)m = z;
	return (m);
}
/*程序的运行结果是：
  第一次：10
  第二次：10
  第三次：10
  第四次：10
  第五次：10
  第六次：10
  程序的功能是：
  在输入的三个整型变量中
  输出最小的数*/
