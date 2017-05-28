/*1650254 ��Ң�� �����һ��*/
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
/* ģ������ */
const struct KFC list[] = {
	{ 'A', "�������ȱ�",         17.0 },
	{ 'B', "���༦�ȱ�",         17.0 },
	{ 'C', "�°¶��������ȱ�",   17.0 },
	{ 'D', "ţ�͹��������ȱ�",   18.0 },
	{ 'E', "�ٽ��ϴ����",     11.0 },
	{ 'F', "�ϱ��������",       15.0 },
	{ 'G', "˱ָԭζ��(һ��)",   10.5 },
	{ 'H', "˱ָԭζ��(����)",   20.0 },
	{ 'I', "�°¶�������",       10.5 },
	{ 'J', "�������׻�",         10.5 },
	{ 'K', "��������",           9.5 },
	{ 'L', "�ƽ𼦿�(���)",     9.0 },
	{ 'M', "����ɫ��",           12.0 },
	{ 'N', "����(С)",           8.5 },
	{ 'O', "����(��)",           10.0 },
	{ 'P', "����(��)",           12.0 },
	{ 'Q', "ܽ��������",         7.5 },
	{ 'R', "��������",           7.0 },
	{ 'S', "����������",         6.0 },
	{ 'T', "�������װ�",         7.0 },
	{ 'U', "��Ƥ��Ͳ",           7.5 },
	{ 'V', "���¿���(С)",       6.5 },
	{ 'W', "���¿���(��)",       8.0 },
	{ 'X', "���¿���(��)",       9.5 },
	{ 'Y', "�����֭����",       10.5 },
	{ 'Z', "����������",         9.5 },
	{ '\0', NULL,                0 }
};
//��ʵ������Ĭ�ϲ˵���ĸ�Ǵ�д�ģ�����ҵǰ����Ҫ�ǲ˵���ĸ��Сд�Ǿͱ�ը��
//��д�������ͷ��βһֱ���ó�ʼ���ַ����飬Ч�ʺ���
//�������Ŀ��˼·��ƫ�ˣ���ͷ��βһֱ�ڴ���һ���ַ�����
//���ǰ��ַ�����ת��������������ӷ���
//�л����ٸ�
//��ѡ������
//QAQ
const struct SPECIAL special[] = {
	{ "ANV", "�����������������",    20 },
	{ "GGGGGJJJSTWWWWWWWST", "��ֵȫ��Ͱ",  82 },
	{ "ZZ", "��������2�����",        14.5 },
	{ "UUU","��Ƥ��Ͳ��2��1",         15 },
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
	cout << "��ӭ���ٿϵ»���\n����Ϊ��Ʒ\n";
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
	cout << "\n\n\n��ǰ�Ż��ײ�Ϊ��\n";
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
	cout << "�������˵��\nANV = �������ȱ� + ����(С) + ���¿���(С) / akaak = �������ȱ� * 3 + �������� * 2\n��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
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
			cout << "��λ������ƺ�������ʲô�����ַ���������>��<" << endl;
			system("pause");
			continue;
		}
		if (mode == 10)
			break;
		sort_input(input,strlen(input));
		cout << "���ĵ㵥�ǣ�" << endl;
		count_and_output(list, input);
		cout << endl;
		cout <<"һ����"<< setw(8)<<count_money(input, list, num_of_list, special, num_of_special) <<"Ԫ"<< endl;
		system("pause");
	}
	return 0;
}