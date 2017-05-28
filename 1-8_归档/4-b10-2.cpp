/* 1650254 计1 尤尧寅*/
#include <iostream>
using namespace std;

/* 此处给出fun函数的实现 */
template<typename T>
T fun(T x)
{
	T temp = 0;
	T t = x;
	for (t = 1; t <=x; t++)
	{
		temp = temp+t;
	}
	return temp;
}
/* main函数不准修改 */
int main()
{
	short          s1 = 255, s2 = s1 + 1;
	unsigned short us1 = 255, us2 = us1 + 1;
	int            i1 = 65535, i2 = i1 + 1;
	unsigned int   ui1 = 65535, ui2 = ui1 + 1;

	cout << fun(s1) << endl; //期望输出 32640
	cout << fun(s2) << endl; //期望输出 -32640
	cout << fun(us1) << endl; //期望输出 32640
	cout << fun(us2) << endl; //期望输出 32896
	cout << fun(i1) << endl; //期望输出 2147450880
	cout << fun(i2) << endl; //期望输出 -2147450880
	cout << fun(ui1) << endl; //期望输出 2147450880
	cout << fun(ui2) << endl; //期望输出 2147516416

	return 0;

}