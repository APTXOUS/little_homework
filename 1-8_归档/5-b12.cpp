/*1650254 º∆1 ”»“¢“˙*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;
int main()
{
	char str[3][30];
	char temp[30];
	cout << "«Î ‰»Î3∏ˆ◊÷∑˚¥Æ:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> str[i];
	}
	if (strcmp(str[1], str[2]))
	{
		strcpy(temp, str[1]);
		strcpy(str[1], str[2]);
		strcpy(str[2], temp);

	}
	if (-strcmp(str[0], str[1]))
	{
		cout << str[0] << " " << str[1] << " " << str[2] << endl;
	}
	else if (-strcmp(str[0], str[2]))
	{
		cout << str[1] << " " << str[0] << " " << str[2] << endl;
	}
	else
	{
		cout << str[1] << " " << str[2] << " " << str[0] << endl;
	}

	return 0;
		
}