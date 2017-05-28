/*1650254 计1 尤尧寅*/
#include<iostream>
#include <stdlib.h>	//srand/rand函数
#include <time.h>	//time函数
using namespace std;

void mima(char pass[],int n,int time1)
{
	int numA = 0, numa = 0, num1 = 0, num_ = 0;
	srand(time1);
	int i=0;
	int temp1;
	while (1)
	{
		int temp = rand() % 4;
		if (numA <= 1 && temp == 0)
		{
			numA++;
			temp1=(rand() % 26)+65;
			pass[i] = (char)temp1;
			i++;
		}
		else if (numa <= 1 && temp == 1)
		{
			numa++;
			temp1 = (rand() % 26) + 97;
			pass[i] = (char)temp1;
			i++;
		}
		else if (num1 <= 1 && temp == 2)
		{
			num1++;
			temp1 = (rand() % 10) + 48;
			pass[i] = (char)temp1;
			i++;
		}
		else if (num_ <= 1 && temp == 3)
		{
			num_++;
			while (1)
			{
				temp1 =( rand() % 94) + 33;
				if (!((temp1 >= 48 && temp1 <= 57) || (temp1 >= 65 && temp1 <= 90) || (temp1 >= 97 && temp1 <= 122)))
					break;
			}
			pass[i] = (char)temp1;
			i++;
		}
		else if (numA == 2 && numa == 2 && num1 == 2 && num_ == 2)
		{
			for (int k = 1; k <= n-8; k++)
			{
				temp1 = (rand() % 94) + 33;
				pass[i] = (char)temp1;
				i++;
			}
			break;
		}
	}
	pass[i] = '\0';
	
}
int main()
{
	char password[17];
	int n;
	while (1)
	{
		cout << "请输入一个12-16的数字" << endl;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if (n >= 12 && n <= 16)
			break;
	}
	unsigned int time1 = (unsigned int)time(0);
	srand(time1);
	for (int k = 1; k <= 10; k++)
	{
		mima(password, n,rand());
		cout << password << endl;
	}
	return 0;
}
