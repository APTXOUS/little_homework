/*1650254 ��Ң�� �����һ��*/
#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	void get_value()
	{
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
	}
private:
	int num;
	string name;
	char sex;
};
class Student1 :public Student
{
public:
	void get_value_1()
	{
		Student::get_value();
		cin >> age >> addr;
	}
	void display_1()
	{
		Student::display();
		cout << "age:" << age << endl;
		cout << "addr:" <<addr << endl;
	}
private:
	int age;
	string addr;

};
int main()
{
	Student1 stud;
	//cout << "������ѧ�� ���� �Ա� ���� ��ַ" << endl;
	stud.get_value_1();
	stud.display_1();
	//system("pause");
	return 0;

}