/*1650254 ��1 ��Ң��*/
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
	cout << "�����뱾���ѧ��������" << endl;
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
	cout << "��������Ҫ�ҵ�ѧ������";
	cin >> findname;
	search(findname);
	return 0;

}
void input_data()
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "�������"<<i+1<<"ѧ�����ּ�ѧ��";
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
			cout << name[i] << "���ҵ��ˣ�ta��ѧ����" << num[i] << endl;
			flag = true;
		}
	if (flag == false)
		cout << "�Ҳ���" << endl;
}