/*1650254 ��Ң�� �����һ��*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;
struct student {
	int *no;
	char *name;
	int *score;
	struct student *next;
};
int length(char *name)
{
	int sum = 1;
	int i = 0;
	while (name[i] != '\0')
	{
		sum++;
		i++;
	}
	return sum;
}
int main()
{
	ifstream fin;
	fin.open("list.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return -1;
	}
	student *head = NULL, *p = NULL, *q = NULL;
	int i = 0;
	while (1)
	{
		if (i > 0)
			q = p;
		int temp;
		char temp_name[9];
		fin >> temp;
		if (temp == 9999999)
			break;
		fin >> temp_name;
		//
		p =new student;
		if (p == NULL)
		{
			fin.close();
			return -1;
		}
		p->no = new(nothrow) int;
		if (p->no == NULL)
		{
			fin.close();
			return -1;
		}
		p->name = new(nothrow) char[length(temp_name)];
		if (p->name == NULL)
		{
			fin.close();
			return -1;
		}
		p->score = new(nothrow) int;
		if (p->score == NULL)
		{
			fin.close();
			return -1;
		}
		*p->no = temp;
		//
		for (int j = 0; j < length(temp_name); j++)
			p->name[j] = temp_name[j];
		fin >> *(p->score);
		if (i == 0)
			head = p;
		else
			q->next = p;
		i++;
		p->next = NULL;
	}
	p = head;
	while (p != NULL)
	{
		cout << *p->no << setw(9) << p->name << setw(4) << *p->score << endl;
		p = p->next;
	}
	p = head;
	while (p)
	{
		q = p->next;
		delete p->no;
		delete []p->name;
		delete p->score;
		delete p;
		p = q;
	}
	fin.close();
	return 0;
}