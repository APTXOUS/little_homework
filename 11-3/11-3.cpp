/*1650254 ��Ң�� �����һ��*/
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
//	cout << "������ѧ�� ���� �Ա� ���� ��ַ" << endl;
	stud.get_value1();
	stud.display1();
//	system("pause");
	return 0;

}