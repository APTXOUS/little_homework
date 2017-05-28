/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<fstream>
#include<io.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include <experimental/filesystem>
#define OK              1
#define INPUT_ERROR    -1
#define CHECK           1
#define REP             2
#define THE_FILE_IS_CPP 1
#define THE_FILE_IS_H   2
#define THE_FILE_IS_C   3
#define THE_FILE_IS_ALL 4
#define WHAT_THE_HELL_IS_IT 999
#define THE_FILE_IS_MISSING -1
#define HAVE_FOUND_THE_FILE 1
#define MAX_LENTH_CLASS 16
#define MAX_LENTH_STUENT 8
#define MAX_LENTH_PROGRAME 32
#define END -999
using namespace std;
const char check[] = "-checktitle";
const char rep[] = "-replace";
const char CPP[] = ".cpp";

const char H[] = ".h";
const char C[] = ".c";
const char all[] = "all";
const char file[] = "source\\";
int judge_EXPANDNAME(const char *file_name)
{
	int i = 0;
	if (file_name == NULL)
		return -99;
	if (strcmp(file_name, "all") == 0)
		return THE_FILE_IS_ALL;
	while (file_name[i] != '\0')
	{
		if (file_name[i] == '.')
		{
			if (strcmp(&file_name[i], CPP) == 0)
				return THE_FILE_IS_CPP;
			if (strcmp(&file_name[i], H) == 0)
				return THE_FILE_IS_H;
			if (strcmp(&file_name[i], C) == 0)
				return THE_FILE_IS_C;
		}
		i++;
	}
	return WHAT_THE_HELL_IS_IT;
}
int judge_mode(const int argc, char *argv[])
{
	if (argc > 1)
	{
		if (_strcmpi(argv[1], check) == 0 && argc == 4)
			return CHECK;
		else if (_strcmpi(argv[1], rep) == 0 && argc == 5)
			return REP;
		else
			return INPUT_ERROR;
	}
	else
		return INPUT_ERROR;
}
int find_document(const char *name)
{
	long file;
	struct _finddata_t find;
	if ((file = _findfirst(name, &find)) == -1L)
	{
		_findclose(file);
		return THE_FILE_IS_MISSING;
	}
	else
	{
		_findclose(file);
		return OK;
	}
}
int judge_input_correct(const int argc, char *argv[])
{
	int mode = judge_mode(argc, argv);
	if (mode == INPUT_ERROR)//判断输入参数错误
	{
		cout << "输入参数错误" << endl;
		return END;
	}
	else
	{
		char *target;
		target = new(nothrow)char[strlen(argv[2]) + 12];
		if (target == NULL)
			return END;
		strcpy(target, file);
		strcat(target, argv[2]);
		strcat(target, ".dat");
		if (find_document(target) == THE_FILE_IS_MISSING)//判断对应课号文件是否存在
		{
			cout << target << "名单不存在！" << endl;
			delete target;
			return END;
		}
		delete target;
		if (mode == CHECK&&judge_EXPANDNAME(argv[3]) == WHAT_THE_HELL_IS_IT)//判断输入文件是否是程序
		{
			cout << "不是源程序文件" << endl;
			return END;
		}
		if (mode == REP && (judge_EXPANDNAME(argv[3]) == WHAT_THE_HELL_IS_IT || judge_EXPANDNAME(argv[4]) == WHAT_THE_HELL_IS_IT))//判断输入文件是否是程序
		{
			cout << "不是源程序文件" << endl;
			return END;
		}
		if (mode == REP)
		{
			target = new(nothrow)char[strlen(argv[4]) + 9];
			strcpy(target, file);
			strcat(target, argv[4]);
			if (find_document(target) == THE_FILE_IS_MISSING)
			{
				delete target;
				cout << "替换文件不存在" << endl;
				return END;
			}
			delete target;
		}
		return mode;
	}

}
int judge_right(char *temp, char *id, char *name, char *cla1, char *cla2)
{
	int book[3] = { 0,0,0 };
	while (temp[strlen(temp)-1] == ' ' || temp[strlen(temp)-1] == '\t')
		temp[strlen(temp)-1] = '\0';
	if (temp[0] == '/'&&temp[strlen(temp) - 1] == '/'&&temp[1] == '*'&&temp[strlen(temp) - 2] == '*')
		temp[strlen(temp) - 2] = '\0';
	else if (temp[0] == '/'&&temp[1] == '/')
		;
	else
	{
		cout << "未取到首行信息" << endl;
		return END;
	}
	int i = 2;
	int flag = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] != ' '&&temp[i] != '\t'&&temp[i] != '\0')
		{
			int j = i;
			while (1)
			{
				if (temp[j] == ' ' || temp[j] == '\t' || temp[j] == '\0')
					break;
				j++;
			}
			int temp_char = temp[j];
			temp[j] = '\0';
			if (strcmp(&temp[i], id) == 0)
				book[0] = 1;
			else if (strcmp(&temp[i], name) == 0)
				book[1] = 1;
			else if (strstr(&temp[i], cla1) != NULL)
				book[2] = 1;
			else if (strstr(&temp[i], cla2) != NULL)
				book[2] = 1;
			else
				;
			temp[j] = temp_char;
			flag++;
			if (temp[j] != '\0')
				i = j;
			else
				i = j - 1;
		}
		if (flag == 3)
		{
			break;
		}
		if (book[0] == 1 && book[1] == 1 && book[2] == 1)
		{
			break;
		}
		i++;
	}
	if (flag != 3)
		cout << "首行信息不全";
	else
	{
		if (book[0] == 0)
			cout << "学号不匹配  ";
		if (book[1] == 0)
			cout << "姓名不匹配  ";
		if (book[2] == 0)
			cout << "班级不匹配  ";
		if (book[0] == 1 && book[1] == 1 && book[2] == 1)
			cout << "通过";
	}
	cout << endl;
	return 0;
}
int check_titile(const int argc, char *argv[])
{
	char *target;
	target = new(nothrow)char[strlen(argv[2]) + 12];
	if (target == NULL)
		return END;
	strcpy(target, file);
	strcat(target, argv[2]);
	strcat(target, ".dat");
	ifstream inlist;
	inlist.open(target, ios::in);
	if (!inlist.is_open())
		return END;
	char id[128];
	char line_name[128];
	char line_class[128];
	char line_cla[128];
	while (1)
	{
		if (inlist.eof() != 0)
			break;
		inlist >> id;
		inlist >> line_name;
		inlist >> line_class;
		inlist >> line_cla;
		char *stu;
		stu = new(nothrow)char[strlen(argv[2]) + 11 + strlen(id) + strlen(argv[3])];
		if (stu == NULL)
			return END;
		strcpy(stu, file);
		strcat(stu, argv[2]);
		strcat(stu, "-");
		strcat(stu, id);
		strcat(stu, "\\");
		strcat(stu, argv[3]);
		cout << id << "  " << line_name << ":  \n";
		if (find_document(stu) == THE_FILE_IS_MISSING)
		{
			cout << "未提交" << endl;
			continue;
		}
		ifstream instudent;
		instudent.open(stu, ios::in);
		if (!instudent.is_open())
			continue;
		char temp[128];
		while (((temp[0] = instudent.get()) == '\n') || temp[0] == '\t' || temp[0] == ' ')
			;
		instudent.getline(&temp[1], 128, '\n');
		judge_right(temp, id, line_name, line_class, line_cla);
		instudent.close();
		delete stu;
	}
	inlist.close();
	delete target;
	return OK;
}
void get_and_judge(char *f_name, char *id, char *name, char *cla1, char *cla2,char *argv[])
{
	char *file_name;
	file_name = new(nothrow)char[strlen(argv[2]) + 11 + strlen(id) + strlen(f_name)];
	strcpy(file_name, file);
	strcat(file_name, argv[2]);
	strcat(file_name, "-");
	strcat(file_name, id);
	strcat(file_name, "\\");
	strcat(file_name, f_name);
	ifstream instudent;
	instudent.open(file_name, ios::in);
	if (!instudent.is_open())
		return;
	char temp[128];
	while (((temp[0] = instudent.get()) == '\n') || temp[0] == '\t' || temp[0] == ' ')
		;
	instudent.getline(&temp[1], 128, '\n');
	judge_right(temp, id, name, cla1,cla2);
	instudent.close();
	delete file_name;
}
int check_titile_all(const int argc, char *argv[])
{
	char *target;
	target = new(nothrow)char[strlen(argv[2]) + 12];
	if (target == NULL)
		return END;
	strcpy(target, file);
	strcat(target, argv[2]);
	strcat(target, ".dat");
	ifstream inlist;
	inlist.open(target, ios::in);
	if (!inlist.is_open())
		return END;
	char id[128];
	char line_name[128];
	char line_class[128];
	char line_cla[128];
	while (1)
	{
		if (inlist.eof() != 0)
			break;
		inlist >> id;
		inlist >> line_name;
		inlist >> line_class;
		inlist >> line_cla;
		char *stu;
		stu = new(nothrow)char[strlen(argv[2]) + 11 + strlen(id) + 3];
		if (stu == NULL)
			return END;
		strcpy(stu, file);
		strcat(stu, argv[2]);
		strcat(stu, "-");
		strcat(stu, id);
		strcat(stu, "\\");
		strcat(stu, "*.*");
		cout << id << "  " << line_name << ":  \n";
		long file;
		struct _finddata_t find;
		if ((file = _findfirst(stu, &find)) == -1L)
		{
			;
		}
		else 
		{
			if (judge_EXPANDNAME(find.name) != WHAT_THE_HELL_IS_IT&&judge_EXPANDNAME(find.name) != THE_FILE_IS_ALL)
			{
				cout << find.name << ":  ";
				get_and_judge(find.name, id, line_name, line_class, line_cla, argv);
			}
			while (_findnext(file, &find) == 0)
			{
				if (judge_EXPANDNAME(find.name) != WHAT_THE_HELL_IS_IT&&judge_EXPANDNAME(find.name) != THE_FILE_IS_ALL)
				{
					cout << find.name << ":  ";
					get_and_judge(find.name, id, line_name, line_class, line_cla, argv);
				}
			}
		}
		_findclose(file);
		delete stu;
	}
	inlist.close();
	delete target;
	return OK;
}
int search_main(fstream &infile)
{
	infile.seekp(0, ios::beg);
	int start = (int)infile.tellp();
	infile.seekp(0, ios::end);
	int n;
	int flag1 = 0;
	while (1)
	{
		infile.seekp(-1, ios::cur);
		n = int(infile.tellp());
		char c;
		infile.read((char *)&c, sizeof(c));
		if (c == '}')
			flag1++;
		else if(c=='{')
			flag1--;
		else if(c== 'i'&&flag1==0)
		{
			char temp[]="int main";
			infile.seekp(-1, ios::cur);
			int i = 0, flag = 0;
			while (temp[i] != '\0')
			{
				char cat;
				infile.read((char *)&cat, sizeof(cat));
				if (cat == temp[i])
					;
				else
				{
					flag = 1;
					break;
				}
				i++;
			}
			if (flag == 1)
				infile.seekp(n, ios::beg);
			else
				return n;
		}
		if (n == start)
			break;
		infile.seekp(-1, ios::cur);
	}
	return END;
}
int replace_all(const int argc, char *argv[])
{
	char *target;
	target = new(nothrow)char[strlen(argv[2]) + 12];
	if (target == NULL)
		return END;
	strcpy(target, file);
	strcat(target, argv[2]);
	strcat(target, ".dat");
	ifstream inlist;
	inlist.open(target, ios::in);
	if (!inlist.is_open())
		return END;
	char *target_1;
	target_1 = new(nothrow)char[strlen(argv[4]) + 9];
	strcpy(target_1, file);
	strcat(target_1, argv[4]);
	fstream inmian;
	inmian.open(target_1, ios::in | ios::out | ios::binary);
	if (!inmian.is_open())
		return END;
	char id[128];
	char line[128];
	while (1)
	{
		if (inlist.eof())
			break;
		inlist >> id;
		for (int i = 0; i < 3; i++)
			inlist >> line;
		char *stu;
		stu = new(nothrow)char[strlen(argv[2]) + 11 + strlen(id) + strlen(argv[3])];
		if (stu == NULL)
			return END;
		strcpy(stu, file);
		strcat(stu, argv[2]);
		strcat(stu, "-");
		strcat(stu, id);
		strcat(stu, "\\");
		strcat(stu, argv[3]);
		if (find_document(stu) == THE_FILE_IS_MISSING)
		{
			cout << "未提交" << endl;
			continue;
		}
		fstream instudent;
		instudent.open(stu, ios::in|ios::out|ios::binary);
		if (!instudent.is_open())
			continue;
		int targer = search_main(instudent);
		cout << stu << endl;
		if (targer == END)
			cout << "找不到main函数" << endl;
		else
		{
			inmian.clear();
			inmian.seekp(0, ios::beg);
			instudent.seekp(0, ios::end);
			int end = (int)instudent.tellp();
			instudent.seekp(targer, ios::beg);
			while (1)
			{
				char cat = inmian.get();
				instudent.write((char *)&cat, 1);
				if (inmian.eof())
					break;
			}
			if((int) instudent.tellp()<end)
				experimental::filesystem::resize_file(stu, (int)instudent.tellp());
				
		}
		instudent.close();
		delete stu;
	}
	inmian.close();
	delete target_1;
	inlist.close();
	delete target;
	return OK;
}
int main(int argc, char *argv[])
{
	switch (judge_input_correct(argc, argv))
	{
	case END:
		return 0;
		break;
	case CHECK:
		if(judge_EXPANDNAME(argv[3])!=THE_FILE_IS_ALL)
			check_titile(argc, argv);
		else
			check_titile_all(argc, argv);
		break;
	case REP:
		replace_all(argc, argv);
		break;
	}
	return 0;
}