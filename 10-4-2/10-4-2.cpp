/* 1650254 尤尧寅 计算机一班 */
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
private:
	int value[2][3];
public:
	matrix(int(*p)[3]);  //构造函数，用数组初始化矩阵
	void display();       //输出该矩阵
	friend matrix operator+(matrix &a, matrix &b);
	/* ----根据需要添加其它成员函数的定义---- */
	matrix();
};

/* ----给出类成员函数的体外实现---- */
matrix::matrix()
{
	;
}
matrix::matrix(int(*p)[3])
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			value[i][j] = p[i][j];
}
void matrix::display()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << value[i][j] << " ";
		cout << endl;
	}
}

matrix operator+(matrix &a, matrix& b)
{
	matrix temp;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			temp.value[i][j] = a.value[i][j] + b.value[i][j];
	return temp;
}
/* ----main函数不准动---- */
int main()
{
	int a[2][3] = { { 1,2,3 },{ 4,5,6 } };
	int b[2][3] = { { 1,2,3 },{ 4,5,6 } };
	matrix m1(a), m2(b), m3;

	cout << "初始矩阵m1的值：" << endl;
	m1.display();
	cout << "初始矩阵m2的值：" << endl;
	m2.display();
	m3 = m1 + m2;
	cout << "相加后矩阵m3的值：" << endl;
	m3.display();
	//system("pause");
	return 0;
}
