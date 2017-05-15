/* 1650254 尤尧寅 计算机一班*/
#include <iostream>
#include <cmath>
using namespace std;

class point {
private:
	int x;
	int y;
public:
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	void set(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	double length(point &temp)
	{
		return sqrt(1.0*(temp.x-x)*(temp.x - x)+1.0*(temp.y - y)*(temp.y - y));
	}
};

class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	double area() {
		double a, b, c;  //分别表示三角形三边的长度
		double s;

		/* 根据需要补充相应的语句，假设三边一定构成三角形 */
		a = p1.length(p2);
		b = p2.length(p3);
		c = p3.length(p1);
	
		s = 1.0 / 2 * (a + b + c);

		return sqrt(s*(s - a)*(s - b)*(s - c));
	}

	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y) {
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
};

/* main函数不准动 */
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //三角形为(0,0) (0,1) (1,0)三点组成
		cout << "三角形面积应该是：0.5，实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //三角形为(0,2) (-1,-1) (1,-1)三点组成
		cout << "三角形面积应该是：3，  实际是：" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //三角形为(5,5) (-3,1) (9,-2)三点组成
		cout << "三角形面积应该是：36， 实际是：" << tr.area() << endl;
	}
	
	return 0;
}
