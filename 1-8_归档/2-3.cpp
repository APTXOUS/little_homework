//*1650254 1班 尤尧寅*/
#include<iostream>
using namespace std;
int main()
{
	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = '\101', c5 = '\116';
	cout << c1 << c2 << c3 << '\n';
	cout << "\t\b" << c4 << '\t' << c5 << '\n';
	return 0;
}
/*
程序运行结果
abc
	A	N
A之前输出了一个tab和一个退格
*/
