/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include <conio.h>
using namespace std;
const int MAXLENGTH = 10;
const short light[10] = {
	(short)0x0001,
	0x0002,
	0x0004,
	0x0008,
	0x0010,
	0x0020,
	0x0040,
	0x0080,
	0x0100,
	0x0200
};
void change(char *input)
{
	int i = 0;
	while (input[i] != '\n')
	{
		if (input[i] >= 'a'&&input[i] <= 'z')
			input[i] -= ('a' - 'A');
		else if (input[i] >= 'A'&&input[i] <= 'Z')
			;
		else if (input[i] == 32)
			;
		else
			break;
		i++;
	}
}
int judge(int *num,int *sta)
{
	cout << "请输入开关操作" << endl;
	while (1)
	{
		char temp[30];
		int i = 0;
		while (1)
		{
			temp[i] = getchar();
			if (i > 5)
			{ 
				cout << "输入错误"<<endl;
				i = 0;
			}
			if (temp[i] == '\n')
				break;
			i++;
		}
		change(temp);
		if (temp[0] == 'E'&&temp[1] == 'N'&&temp[2] == 'D')
			return -1;
		if (temp[0] >= 'A'&&temp[0] <= 'J'&&temp[1]==32)
		{
			if (temp[2] == 'O'&&temp[3] == 'N')
			{
				*num = temp[0] - 'A';
				*sta = 1;
				break;
			}
			else if (temp[2] == 'O'&&temp[3] == 'F'&&temp[4] == 'F')
			{
				*num = temp[0] - 'A';
				*sta = -1;
				break;
			}
			else
			{
				cout << "输入错误请重新输入" << endl;
				continue;
			}
		}
		else
		{
			cout << "输入错误请重新输入" << endl;
			continue;
		}
	}
	return 0;
}
void print_light(const short temp_input)
{
	short temp = temp_input;
	int temparrary[MAXLENGTH];
	for (int i = 0; i < MAXLENGTH; i++)
	{
		temparrary[i] = temp % 2;
		temp = temp >> 1;
	}
	cout << " A   B   C   D   E   F   G   H   I   J" << endl;
	for (int i = 0; i < MAXLENGTH; i++)
	{
		if (temparrary[i] == 0)
			cout << "OFF " ;
		if (temparrary[i] == 1)
			cout << "ON  ";
	}
	cout <<endl;
}
int main()
{
	int num;
	int sta;
	short on_off_switch = 0x0000;
	print_light(on_off_switch);
	while (judge(&num,&sta)!=-1)
	{
		if (sta == 1)
			on_off_switch = on_off_switch | light[num];
		if(sta==-1)
			on_off_switch = on_off_switch & (~light[num]);
		print_light(on_off_switch);
	}
	return 0;
}

