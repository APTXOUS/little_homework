/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#define _SERCURE_
using namespace std;
struct KFC {
	char input_name;
	char *output_name;
	double money;
};
struct SPECIAL{
	char *input_name;
	char *output_name;
	double money;
};
/* 模拟数据 */
const struct KFC list[] = {
	{ 'A', "香辣鸡腿堡",         17.0 },
	{ 'B', "劲脆鸡腿堡",         17.0 },
	{ 'C', "新奥尔良烤鸡腿堡",   17.0 },
	{ 'D', "牛油果香辣鸡腿堡",   18.0 },
	{ 'E', "藤椒肯大大鸡排",     11.0 },
	{ 'F', "老北京鸡肉卷",       15.0 },
	{ 'G', "吮指原味鸡(一块)",   10.5 },
	{ 'H', "吮指原味鸡(二块)",   20.0 },
	{ 'I', "新奥尔良烤翅",       10.5 },
	{ 'J', "劲爆鸡米花",         10.5 },
	{ 'K', "香辣鸡翅",           9.5 },
	{ 'L', "黄金鸡块(五块)",     9.0 },
	{ 'M', "鲜蔬色拉",           12.0 },
	{ 'N', "薯条(小)",           8.5 },
	{ 'O', "薯条(中)",           10.0 },
	{ 'P', "薯条(大)",           12.0 },
	{ 'Q', "芙蓉蔬荟汤",         7.5 },
	{ 'R', "骨肉相连",           7.0 },
	{ 'S', "醇香土豆泥",         6.0 },
	{ 'T', "香甜粟米棒",         7.0 },
	{ 'U', "脆皮甜筒",           7.5 },
	{ 'V', "百事可乐(小)",       6.5 },
	{ 'W', "百事可乐(中)",       8.0 },
	{ 'X', "百事可乐(大)",       9.5 },
	{ 'Y', "九珍果汁饮料",       10.5 },
	{ 'Z', "纯纯玉米饮",         9.5 },
	{ '\0', NULL,                0 }
};
//其实这里我默认菜单字母是大写的，交作业前发现要是菜单字母是小写那就爆炸了
//我写的这题从头到尾一直在用初始的字符数组，效率很慢
//这次做题目我思路跑偏了，从头到尾一直在传递一个字符数组
//但是把字符数组转换成整型数组更加方便
//有机会再改
//我选择死亡
//QAQ
const struct SPECIAL special[] = {
	{ "ANV", "香辣汉堡工作日午餐",    20 },
	{ "GGGGGJJJSTWWWWWWWST", "超值全家桶",  82 },
	{ "ZZ", "玉米饮第2件半价",        14.5 },
	{ "UUU","脆皮甜筒买2送1",         15 },
	{ NULL, NULL, 0 }
};
int count_KFC(const struct KFC temp[])
{
	if (temp == NULL)
		return 0;
	int i = 0;
	while (temp[i].input_name != '\0')
		i++;
	return i;
}
int count_SPECIAL(const struct SPECIAL temp[])
{
	if (temp == NULL)
		return 0;
	int i = 0;
	while (temp[i].input_name != NULL)
		i++;
	return i;
}
int count_KFC_MAX_OUTPUTNAME(const struct KFC temp[])
{
	if (temp == NULL)
		return 0;
	int i = 0, max=0;
	while (temp[i].input_name != '\0')
	{
		if ((int)strlen(temp[i].output_name) > max)
			max = strlen(temp[i].output_name);
		i++;
	}
	return max+4;
}
void output_dish(const struct KFC temp[],char name)
{
	int i = 0;
	while (temp[i].input_name != name)
	{
		i++;
	}
	cout << temp[i].output_name;
}
int judge_dish(const struct KFC temp[], char name)
{
int i = 0;
int flag = 0;
while (temp[i].input_name != name)
{
	if (temp[i].input_name == '\0')
	{
		flag = 1;
		break;
	}
	i++;
}
return flag;
}
void sort_input(char *inputname, int NUM)
{
	int max;
	for (int i = 0; i < NUM; i++)
	{
		max = i;
		for (int j = i; j < NUM; j++)
			if (inputname[max] > inputname[j])
				max = j;
		char temp = inputname[max];
		inputname[max] = inputname[i];
		inputname[i] = temp;
	}
}
void count_and_output(const struct KFC list[], const char *inputname)
{
	int i = 0;
	char temp = inputname[0];
	int count = 0;
	while (1)
	{
		if (inputname[i] == '\0')
		{
			output_dish(list, temp);
			if (count > 1)
				cout << "*" << count;
			break;
		}
		if (i != 0 && inputname[i] != temp)
		{
			output_dish(list, temp);
			if (count > 1)
				cout << "*" << count;
			cout << "+";
			count = 0;
			temp = inputname[i];
		}
		if (inputname[i] == temp)
			count++;
		i++;
	}
}
void changeintodaxie(char *input)
{
	int i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= 'a'&&input[i] <= 'z')
			input[i] = input[i] - 'a' + 'A';
		i++;
	}
}
void output_information(const struct KFC dish[], const int num_KFC, const struct SPECIAL dishes[], const int num_SPECIAL, const int max)
{
	system("cls");
	cout << "欢迎光临肯德基！\n以下为菜品\n";
	for (int i = 0; i < num_KFC; i++)
	{
		cout << setw(3) << dish[i].input_name << setw(max) << dish[i].output_name << setw(8) << dish[i].money;
		if (i != num_KFC - 1)
		{
			cout << setw(3) << dish[i + 1].input_name << setw(max) << dish[i + 1].output_name << setw(8) << dish[i + 1].money << endl;
			i++;
		}
		if (i == num_KFC - 1 && num_KFC % 2 != 0)
			cout << endl;
	}
	cout << "\n\n\n当前优惠套餐为：\n";
	for (int i = 0; i < num_SPECIAL; i++)
	{
		char temp_SPECIAL[128];
		strcpy(temp_SPECIAL, dishes[i].input_name);
		sort_input(temp_SPECIAL, strlen(temp_SPECIAL));
		cout << dishes[i].output_name << "=";
		count_and_output(dish, temp_SPECIAL);
		cout << setw(5) << dishes[i].money << endl;
	}
	cout << endl;
	cout << "输入规则说明\nANV = 香辣鸡腿堡 + 薯条(小) + 百事可乐(小) / akaak = 香辣鸡腿堡 * 3 + 香辣鸡翅 * 2\n字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
}
double count_money(char *input, const KFC *list, int num_list, const SPECIAL *special, int num_special)
{
	int num = strlen(input);
	double money = 0;
	for (int i = 0; i < num_special; i++)
	{
		int num_1=strlen(special[i].input_name);
		for (int j = 0; j < num; j++)
		{
			if (input[j] == special[i].input_name[0])
			{
				char *temp;
				temp = new(nothrow)char[num+1];
				if (temp == NULL)
					return-1;
				for (int k = 0; k <= num; k++)
					temp[k] = input[k];
				temp[j] = '\0';
				int count = 1;
				for (int k = 1; k < num_1; k++)
				{
					for (int g = 0; g < num; g++)
					{
						if (temp[g] == special[i].input_name[k])
						{
							temp[g] = '\0';
							count++;
							break;
						}
					}
				}
				if (count == num_1)
				{
					for (int k = 0; k <= num; k++)
						input[k] = temp[k];
					money += special[i].money;
				}
				delete temp;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (input[i] != '\0')
		{
			int j = 0;
			while (list[j].input_name != input[i])
				j++;
			money += list[j].money;
		}
	}
	return money;
}
int shuru_input(char *input,const KFC list[])
{
	int i = 0;
	int num = 0;
	int flag = 1;
	cin >> input;
	if (input[0] == '0'&&strlen(input) == 1)
		flag = 0;
	changeintodaxie(input);
	while (input[i] != '\0')
	{
		num+=judge_dish(list, input[i]);
		i++;
	}
	if (flag == 0)
		return 10;
	if (num != 0)
		return 0;
	else
		return 1;
}
int main()
{
	int num_of_list = count_KFC(list);
	int num_of_special = count_SPECIAL(special);
	int max_of_char = count_KFC_MAX_OUTPUTNAME(list);
	char input[128];
	while (1)
	{
		output_information(list, num_of_list, special, num_of_special, max_of_char);
		int mode = shuru_input(input, list);
		if (mode == 0)
		{
			cout << "这位大哥你似乎输入了什么不明字符，请重输>。<" << endl;
			system("pause");
			continue;
		}
		if (mode == 10)
			break;
		sort_input(input,strlen(input));
		cout << "您的点单是：" << endl;
		count_and_output(list, input);
		cout << endl;
		cout <<"一共是"<< setw(8)<<count_money(input, list, num_of_list, special, num_of_special) <<"元"<< endl;
		system("pause");
	}
	return 0;
}