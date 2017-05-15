/*1650254 ��Ң�� �����һ�� */
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //�����ǰ������˼��һ�£����������Ŀ����Ϊʲô
class point {
private:
	int x;
	int y;
public:
	/* �������ڴ����һ����Ա����������1���� */
	void set(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	/* ������������Ǹ���Ա�����⣬������������κε����ݳ�Ա�ͳ�Ա�����������Ը�����Ҫ����������� */
	friend triangle;
};
class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	double area() {
		double a, b, c;  //�ֱ��ʾ���������ߵĳ���
		double s;

		/* ������Ҫ������Ӧ����䣬��������һ������������ */
		a = length(p1,p2);
		b = length(p2, p3);
		c = length(p3, p1);

		s = 1.0 / 2 * (a + b + c);
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y) {
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	double length(point &temp1,point &temp2)
	{
		return sqrt(1.0*(temp1.x - temp2.x)*(temp1.x - temp2.x) + 1.0*(temp1.y - temp2.y)*(temp1.y - temp2.y));
	}
};

/* main������׼�� */
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
	}
	system("pause");
	return 0;
}
