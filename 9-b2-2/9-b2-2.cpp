/*1650254 尤尧寅 计算机一班 */
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //类的提前声明，思考一下，放在这里的目的是为什么
class point {
private:
	int x;
	int y;
public:
	/* 仅允许在此添加一个成员函数【仅限1个】 */
	void set(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	/* 除上面允许的那个成员函数外，不再允许添加任何的数据成员和成员函数，但可以根据需要添加其它内容 */
	friend triangle;
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
		a = length(p1,p2);
		b = length(p2, p3);
		c = length(p3, p1);

		s = 1.0 / 2 * (a + b + c);
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y) {
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	double length(point &temp1,point &temp2)
	{
		return sqrt(1.0*(temp1.x - temp2.x)*(temp1.x - temp2.x) + 1.0*(temp1.y - temp2.y)*(temp1.y - temp2.y));
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
	system("pause");
	return 0;
}
