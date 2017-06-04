/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:

protected:
	int num;
	string name;
	char sex;
};
class Student1:protected Student
{
public:
	void get_value1()
	{
		cin >> num >> name >> sex;
		cin >> age >> addr;
	}
	void display1()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
		cout << "age:" << age << endl;
		cout << "addr:" << addr << endl;
	}
private:
	int age;
	string addr;
};

int main()
{
	Student1 stud;
//	cout << "请输入学号 姓名 性别 年龄 地址" << endl;
	stud.get_value1();
	stud.display1();
//	system("pause");
	return 0;

}