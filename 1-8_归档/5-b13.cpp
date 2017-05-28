/*1650254 计1 尤尧寅*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
char name[50][10], num[50][10];
int n;
int main()
{
	void input_data();
	void search(char findname[]);
	char findname[10];
	cout << "请输入本班的学生人数：" << endl;
	while (1)
	{
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();

		}
		else
			break;
	}
	input_data();
	cout << "请输入你要找的学生姓名";
	cin >> findname;
	search(findname);
	return 0;

}
void input_data()
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "请输入第"<<i+1<<"学生名字及学号";
		cin >> name[i] >> num[i];
	}
}
void search(char findname[])
{
	int i;
	bool flag = false;
	for(i=0;i<n;i++)
		if (strcmp(name[i], findname)==0)
		{
			cout << name[i] << "被找到了，ta的学号是" << num[i] << endl;
			flag = true;
		}
	if (flag == false)
		cout << "找不到" << endl;
}