/*1650254 1班 尤尧寅*/
#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	int add(int x, int y);
	cin >> a >> b;
	c = add(a, b);
	cout << "a+b=" << c<<endl;
	return 0;
}
int add(int x, int y)
{
	int z;
    z = x + y;
	return(z);
}

/*原代码的错误是
1.没有声明add函数
2.没有定义变量c
3.在c = add(a, b)后漏打“：”
4.整型变量a，b没有被赋值
5.int add(int x, int y)后多打“；”
6.没有在add函数中定义变量z。
7.return打成retrun
 */
