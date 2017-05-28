/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;
struct information {
	int id;
	char* name;
	int score;
	int line;
	struct information *next = NULL;
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
	fin.open("student.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "打开文件失败" << endl;
		return -1;
	}
	int num_student;
	fin >> num_student;
	information *student, *head;
	student = new(nothrow) information[num_student];
	//
	if (student == NULL)
	{
		cout << "NO MEMORY!";
		fin.close();
		return -1;
	}
	//
	head = student;
	char name[9];
	for (int i = 0; i < num_student; i++)
	{
		fin >> (student + i)->id >> name >> (student + i)->score;
		(student + i)->name = new char[length(name)];
		if ((student + i)->name == NULL)
		{
			for (int j = 0; j < i-1; j++)
				delete [](student + j)->name;
			delete []head;
			cout << "NO MEMORY!";
			fin.close();
			return -1;
		}
		for (int j = 0; j < length(name); j++)
			(student + i)->name[j] = name[j];
	}
	int max;
	for (int i = 0; i < num_student; i++)
	{
		max = i;
		for (int j = i; j < num_student; j++)
			if (student[max].score < student[j].score)
				max = j;
		information temp = student[max];
		student[max] = student[i];
		student[i] = temp;
	}
	int num = 1;
	int flag = 0;
	int temp = student[0].score;
	for (int i = 0; i < num_student; i++)
	{
		if (student[i].score == temp)
		{
			student[i].line = num;
			flag++;
		}
		else
		{
			num += flag;
			student[i].line = num;
			temp = student[i].score;
			flag = 1;
		}
	}
	for (int i = 0; i < num_student; i++)
	{
		max = i;
		for (int j = i; j < num_student; j++)
			if (student[max].id > student[j].id)
				max = j;
		information temp = student[max];
		student[max] = student[i];
		student[i] = temp;
	}
	for (int i = 0; i < num_student; i++)
		cout << (student + i)->id << setw(8) << (student + i)->name << setw(4) << (student + i)->score << setw(4) << (student + i)->line << endl;
	for (int i = 0; i < num_student; i++)
		delete [](student + i)->name;
	delete []head;
	fin.close();
	return 0;
}