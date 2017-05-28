/* 1650254 ��Ң�� �����һ�� */
#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
private:
	int value[2][3];
public:
	matrix operator+(matrix &b);
	/* ----������Ҫ���������Ա�����Ķ���---- */
	friend istream& operator>>(istream &in, matrix &x);
	friend ostream& operator<<(ostream &out, matrix &x);
};

/* ----�������Ա����������ʵ��---- */
istream& operator>>(istream &in, matrix &x)
{
	for (int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++)
			in >> x.value[i][j];
	return in;
}
ostream& operator<<(ostream &out, matrix &x)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			out << x.value[i][j] << " ";
		out << endl;
	}
	return out;
}
matrix matrix::operator+(matrix &b)
{
	matrix temp;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			temp.value[i][j] = value[i][j] + b.value[i][j];

	return temp;
}
/* ----main������׼��---- */
int main()
{
	matrix m1, m2, m3;

	cout << "���������m1��ֵ(��2��3�У������к��е�˳������)" << endl;
	cin >> m1;
	cout << "���������m2��ֵ(��2��3�У������к��е�˳������)" << endl;
	cin >> m2;

	cout << "��ʼ����m1��ֵ��" << endl;
	cout << m1 << endl;
	cout << "��ʼ����m2��ֵ��" << endl;
	cout << m2 << endl;
	cout << "��Ӻ����m3��ֵ��" << endl;
	cout << (m3 = m1 + m2) << endl;
	//system("pause");
	return 0;
}
