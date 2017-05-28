/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;
int main(int argc, char *argv[])
{
	char name[512];
	if (argc != 1)
		strcpy(name, argv[1]);
	else
		cin >> name;
	ifstream infile;
	infile.open(name, ios::in | ios::binary);
	if (!infile.is_open())
	{
		cerr << "输入失败" << endl;
		exit(-1);
	}
	char temp;
	int count = 0;
	char line[17];
	line[16] = '\0';
	while (infile.read(&temp, sizeof(char)))
	{
		if (count % 16 == 0)
		{
			cout <<"  "<< setfill('0') << setw(8) << hex << count << "： ";
		}
		if (count % 16 != 0 && count % 8 == 0)
			cout << "- ";
		cout << setfill('0') << setw(2) << hex << int(temp & 0x00ff) << " ";
		if (temp >= 32)
			line[count % 16] = temp;
		else
			line[count % 16] = '.';
		count++;
		if (count % 16 == 0)
		{
			cout << " " << line << endl;
			for (int i = 0; i < 16; i++)
				line[i] = '\0';
		}
	}
	cout << endl;
	infile.close();
	return 0;
}