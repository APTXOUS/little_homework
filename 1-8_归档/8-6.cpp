/*1650254 ��Ң�� �����һ��*/
#include<iostream>
using namespace std;
class SQUARE {
private:
	double length;
	double width;
	double height;
	double V;
public:
	void set_square(void);
	void cal_square(void);
	void show_square(void);
};
void SQUARE::set_square()
{
	while (1)
	{
		cin >> length >> width >> height;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "������������" << endl;

		}
		else if (length < 0 || width < 0 || height < 0)
			cout << "������������" << endl;
		else
			break;
	}
}
void SQUARE::cal_square()
{
	V= length*width*height;
}
void SQUARE::show_square()
{
	cout << "����ǣ�" << V << endl;
}
int main()
{
	SQUARE demo;
	demo.set_square();
	demo.cal_square();
	demo.show_square();
//	system("pause");
	return 0;
}