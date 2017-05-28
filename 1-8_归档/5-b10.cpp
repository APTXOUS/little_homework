/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
using namespace std;
int main()
{
	char a[10000];
	char temp = ' ';
	int num=0;
	gets_s(a);
	int count = 0;
	while (1)
	{
		if (a[num] == '\0')
			break;
		else if (count == 0)
		{
			if (a[num] >= 'A'&&a[num] <= 'Z')
			{
				a[num] = a[num];
				count++;
			}
			else if (a[num] >= 'a'&&a[num] <= 'z')
			{
				a[num] = a[num] - 32;
				count++;
			}
			else if (a[num] == ' ')
			{
				a[num] = a[num];
	
			}
			else 
			{
				a[num] = a[num];
				count++;
			}
		}
		else
		{
			if (a[num] >= 'A'&&a[num] <= 'Z')
			{
				a[num] = a[num]+32;
				count++;
			}
			else if (a[num] >= 'a'&&a[num] <= 'z')
			{
				a[num] = a[num];
				count++;
			}
			else if (a[num] == ' ')
			{
				a[num] = a[num];
				count = 0;
			}
			else
			{
				a[num] = a[num];
				count++;
			}
		}
		num++;
	}
	cout << a << endl;


	return 0;

}