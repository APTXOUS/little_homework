/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<windows.h>
using namespace std;
struct student {
	int no;
	char *name;
	char *school;
};
int length(char *name)
{
	int i = 0, num = 1;
	while (name[i] != '\0')
	{
		num++;
		i++;
	}
	return num;
}
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("stulist.txt", ios::in);
	fout.open("result.txt", ios::out);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	if (!fout.is_open())
	{
		cout << "输出文件失败" << endl;
		fin.close();
		return -1;
	}
	int n, m;
	fin >> n >> m;
	srand(unsigned int(time(0)));
	int *book, flag = 0;
	book = new(nothrow)int[n];
	if (book == NULL)
	{
		cout << "无可用内存" << endl;
		fin.close();
		fout.close();
		return -1;
	}
	for (int i = 0; i < n; i++)
	{
		int temp = rand() % m+1;
		for (int j = 0; j < i; j++)
			if (book[j] == temp)
			{
				flag = 1;
				break;
			}
		if (flag == 1)
		{
			i--;
			flag = 0;
		}
		else
			book[i] = temp;
	}
	int max;
	for (int i = 0; i < n; i++)
	{
		max = i;
		for (int j = i; j < n; j++)
			if (book[max] >book[j])
				max = j;
		int temp = book[max];
		book[max] =book[i];
		book[i] = temp;
	}
	int j = 0;
	student *p;
	p = new(nothrow)student;
	if (p == NULL)
	{
		cout << "内存不够" << endl;
		fin.close();
		fout.close();
		return -1;
	}
	
	for (int i = 0; i < m; i++)
	{
		char name[12];
		char school[10];
		fin >> p->no >> name >>school;
		p->name = new(nothrow)char[length(name)];
		if (p->name == NULL)
		{
			cout << "内存不够" << endl;
			fin.close();
			fout.close();
			return -1;
		}
		p->school = new(nothrow)char[length(school)];
		if (p->school == NULL)
		{
			cout << "内存不够" << endl;
			fin.close();
			fout.close();
			return -1;
		}
		for (int k = 0; k < length(name); k++)
			p->name[k] = name[k];
		for (int k = 0; k < length(school); k++)
			p->school[k] = school[k];
		if (i == book[j])
		{
			fout <<  "第"<<setw(5) <<i+1<<"位"<< setw(13) << p->no <<setw(12)<< p->name << setw(10) << p->school << endl;
			j++;
		}
		delete p->name;
		delete p->school;
	}
	cout << "已生成result.txt" << endl;
	delete p;
	fin.close();
	fout.close();
	return 0;
}