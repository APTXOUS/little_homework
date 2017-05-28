/*1650254 1班 尤尧寅*/
#include<iostream>
using namespace std;
int main()
{
	void sort(int x, int y, int z);
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);
	return 0;
}
void sort(int x, int y,int z)
{
	int temp;
	if (x > y) { temp = x; x = y; y = temp; }
	if (z < x) cout << z << ',' << x << ',' << y << endl;
	else if (z < y)cout << x << ',' << z << ',' << y << endl;
	else cout << x << ',' << y << ',' << z << endl;
}

/*按书本运行三次的结果是
   3，6，10
   而第四次输入
   10，6，3时
   得
   -858993460,-858993460,10
   程序的功能是
   给输入的三个数
   从小到大依次输出
   并两两之间插入逗号
*/
