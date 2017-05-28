/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
struct student {
	int no;
	char name[9];
	int score;
	struct student *next;
};
int main()
{
	ifstream fin;
	fin.open("list.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	student *head = NULL, *p = NULL, *q = NULL;
	int i=0;
	while (1)
	{
		if (i > 0)
			q = p;
		int temp;
		fin >> temp;
		if (temp == 9999999)
			break;
		p = new(nothrow)student;
		if (p == NULL)
		{
			fin.close();
			return -1;
		}
		p->no = temp;
		fin >> p->name >> p->score;
		if (i == 0)
			head = p;
		else
			q->next = p;
		i++;
		p->next = NULL;
	}
	p = head;
	while (p!=NULL)
	{
		cout << p->no<<setw(9) << p->name << setw(4) << p->score << endl;
		p = p->next;
	}
	p = head;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	fin.close();
	return 0;
}