/*1650254 ��Ң�� �����һ��*/
#include<iostream>
#include<string>
using namespace std;
class Teacher
{
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tel;
	string title;
public:
	Teacher(string, int, char, string, string, string);
	void display();
};
Teacher::Teacher(string nam, int ag, char se, string add, string t, string tit)
{
	name = nam;
	age = ag;
	sex = se;
	addr = add;
	tel = t;
	title = tit;
}
void Teacher:: display()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "addr:" << addr << endl;
	cout << "tel:" << tel << endl;
	cout << "title:" << title<< endl;
}
class Cadre
{
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tel;
	string post;
public:
	Cadre(string, int, char, string, string, string);
	void display();
};
Cadre::Cadre(string nam, int ag, char se, string add, string t, string pos)
{
	name = nam;
	age = ag;
	sex = se;
	addr = add;
	tel = t;
	post = pos;
}
void Cadre::display()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "addr:" << addr << endl;
	cout << "tel:" << tel << endl;
	cout << "post:" << post << endl;
}
class Teacher_Cadre :public Teacher, public Cadre
{
public:
	Teacher_Cadre(string nam, int ag, char se, string add, string t, string tit,string pos,double wa);
	void show();
protected:
	double wage;
};
Teacher_Cadre::Teacher_Cadre(string nam, int ag, char se, string add, string t, string tit, string pos, double wa):Teacher(nam, ag, se, add, t, tit),Cadre(nam, ag, se, add, t, pos),wage(wa)
{

}
void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "post:" << Cadre::post << endl;
	cout << "wage:" << wage << endl;
}
int main()
{
	if (1)
	{
		Teacher_Cadre t("���", 35, 'm', "ͬ�ô�ѧ", "189XXXXXXXX","����ʦ", "�߳��ڿν�ʦ", 50000);
		t.show();
	}
	if (1)
	{
		string nam, add, tel, title, pos;
		int ag;
		char se;
		double wa;
		cout << "���������� ���� �Ա� ��ַ �绰 ְ�� ְ�� ����" << endl;
		cin >> nam >> ag >> se >> add >> tel >> title >> pos >> wa;
		Teacher_Cadre t(nam ,ag , se , add , tel , title , pos , wa);
		t.show();
	}
	//system("pause");
	return 0;
}
/*�������ݣ�
��� 35 m ͬ�ô�ѧ 189XXXXXXXX ����ʦ �߳��ڿν�ʦ 50000
*/