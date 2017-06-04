/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include<string>
using namespace std;
class Teacher
{
public:
	Teacher(int n, string nam, char s);
	void display();
private:
	int num;
	string name;
	char sex;
};
Teacher::Teacher(int n, string nam, char s) :num(n), name(nam), sex(s)
{

}
void Teacher::display()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
}
class BirthDate
{
public:
	BirthDate(int y, int m, int d);
	void display();
	void revalue_BirthDate(int y, int m, int d);
private:
	int year;
	int month;
	int day;
};
void BirthDate::revalue_BirthDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
BirthDate::BirthDate(int y, int m, int d) : year(y), month(m), day(d)
{

}
void BirthDate::display()
{
	cout << "year:" << year << endl;
	cout << "month:" << month << endl;
	cout << "day:" << day << endl;
}
class Professor :public Teacher
{
public:
	Professor(int n, string nam, char s, int y, int m, int d) :Teacher(n, nam, s), birthday(y, m, d)
	{

	}
	void revalue_birthday(int y,int m,int d)
	{
		birthday.revalue_BirthDate(y, m, d);
	}
	void show()
	{
		Teacher::display();
		birthday.display();
	}
private:
	BirthDate birthday;
};
int main()
{
	if (1)
	{
		Professor prof1(1001, "张三", 'm', 1949, 7, 21);
		cout << "原始数据：" << endl;
		prof1.show();
		cout << "将生日修改成2000.1.1" << endl;
		prof1.revalue_birthday(2000, 1, 1);
		cout << "修改后数据：" << endl;
		prof1.show();

	}
	if (1)
	{
		Professor prof1(1001, "张三", 'm', 1949, 7, 21);
		cout << "原始数据：" << endl;
		prof1.show();
		cout << "输入要修改的生日" << endl;
		int y, m, d;
		cin >> y >> m >> d;
		prof1.revalue_birthday(y, m, d);
		cout << "修改后数据：" << endl;
		prof1.show();
	}
	//system("pause");
	return 0;
}
/*
1998 2 24
*/