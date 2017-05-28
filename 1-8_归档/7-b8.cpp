/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include<windows.h>
#include<time.h>
#include<iomanip>
using namespace std;
const char *name[] = { "辟雅可","闵骊燕","励天晴","夷翊君","楚向雁","波元","马佳嘉致","天千易","计水","纳喇秋蝶","俊雅","进从珊","靳雨文",
"单乐容","霍清馨","鲜学真",NULL };
//将名字定义为常量
const short room[] = {
	(short)0x0092,
	(short)0x0072,
	(short)0x0042,
	(short)0x0092,
	(short)0x0092,
	(short)0x0002,
	(short)0x0092,
	(short)0x0092,
	(short)0x0032,
	(short)0x0007,
	(short)0x0000
};
//不确定此题是否能用全局变量，以防万一使用常量
void coutput(const short *seat,int max,int *book,int num_name)
{
	int i = 0;
	int num_out = 0;
	while (seat[i] != 0x0000)
	{
		if (max == 0)
			cout << "|    /   ";
		short in = seat[i];
		cout << "|";
		for (int j = 0; j < 16; j++)
		{
			if (j >= max-1)
			{
				if (!((in & 0x8000) == 0x8000))
					cout << "    /   |";
				else
				{
					if (num_out < num_name)
					{
						cout << setw(8)<<name[book[num_out]] << "|";
						num_out++;
					}
					else
						cout << "    /   |";
				}
			}
			in = in << 1;
		}
		cout << endl;
		i++;
	}
}
void coutput_2(const short *seat, int max, int *book, short *temp_room)
{
	int i = 0;
	int num_out = 0;
	int k = 0;
	while (seat[i] != 0x0000)
	{
		if (max == 0)
			cout << "|    /   ";
		short in = seat[i];
		cout << "|";
		for (int j = 0; j < 16; j++)
		{
			if (j >= max - 1)
			{
				if (!((in & 0x8000) == 0x8000))
					cout << "    /   |";
				else
				{
					if (temp_room[k] == num_out)
					{
						cout << setw(8) << name[book[k]] << "|";
						k++;
					}
					else
					{
						cout << "    /   |";
					}
					num_out++;
				}
			}
			in = in << 1;
		}
		cout << endl;
		i++;
	}
}
void count_of_max(const short *temp, int *max)
{
	int i = 0;
	while (temp[i] != 0x0000)
	{
		short in = temp[i];
		short num = 0;
		while (!((in & 0x8000)==0x8000))
		{
			in=in << 1;
			num++;
		}
		if (i == 0)
			*max = num;
		if (num < *max)
			*max = num;
		i++;
	}
}
void count_of_carrary(const char* temp[],int *num)
{
	int i = 0;
	while (*(temp+i) != NULL)
		i++;
	*num = i;
}
void count_of_short_arrary(const short* temp, int *num,int *max)
{
	int i = 0;
	while (temp[i] != 0x0000)
	{
		short in = temp[i];
		for (int j = 0; j < 16; j++)
		{
			if (in % 2)
				(*num)++;
			else
				;
			in = in >> 1;
		}
		i++;
	}
	*max = i;
}
void random_arrary(int *book,int num)
{
	srand(unsigned int (time(0 )));
	for (int i = 0; i < num; i++)
	{
		int temp = rand() % num;
		int flag = 0;
		for (int j = 0; j < i; j++)
			if (book[j] == temp)
				flag = 1;
		if (flag == 0)
			book[i] = temp;
		else
			i--;
	}
}
void random_seat(short *book, const short *room,int num,int kat)
{
	srand(unsigned int(time(0)));
	for (int i = 0; i < num; i++)
	{
		int temp = rand() % kat;
		int flag = 0;
		for (int j = 0; j < i; j++)
			if (book[j] == temp)
				flag = 1;
		if (flag == 0)
			book[i] = temp;
		else
			i--;   
	}
}
int main()
{
	int num_name, num_seat = 0, num_max = 0, line;
	int mode;
	count_of_carrary(name, &num_name);
	count_of_short_arrary(room, &num_seat,&line);
	count_of_max(room, &num_max);
	if (num_name > num_seat)
	{
		cout << "座位不足！" << endl;
		return 0;
	}
	cout << "请输入要选择排序的模式！\n";
	cout << "(1)先行后列\n";
	cout << "(2)随机座位\n";
	while (1)
	{
		cin >> mode;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (mode == 1 || mode == 2)
			break;
		cout << "输入错误，请重新输入！" << endl;
	}
	if (mode == 1)
	{
		int *book = new(nothrow) int[num_name]; 
		if (book == NULL)
			return -1;
		random_arrary(book, num_name);
		coutput(room,num_max,book,num_name);
		delete book;
	}
	else
	{
		int *book = new(nothrow) int[num_name];
		if (book == NULL)
			return -1;
		short *temp_room = new(nothrow) short[num_seat];
		if (temp_room == NULL)
		{
			delete book;
			return -1;
		}
		random_arrary(book, num_name);
		random_seat(temp_room,room, num_name,num_seat);
		int max;
		for (int i = 0; i < num_name; i++)
		{
			max = i;
			for (int j = i; j <  num_name; j++)
				if (temp_room[max] > temp_room[j])
					max = j;
			short temp = temp_room[max];
			temp_room[max] = temp_room[i];
			temp_room[i] = temp;
		}
		coutput_2(room, num_max, book, temp_room);
		delete book;
		delete temp_room;
	}
	return 0;
}