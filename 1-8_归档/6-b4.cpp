/*1650254 ÓÈÒ¢Òú ¼Æ1*/
#include<iostream>
#include<string.h>
using namespace std;
char* huiweng(char *str)
{
	int num_end = strlen(str) - 1;
	int i = 0;
	int flag = 0;
	if (num_end == -1 || num_end == 0)
		return "yes";
	else
		while (i < num_end)
			if (*(str + i) != *(str + num_end))
			{
				flag = 1;
				break;
			}
			else
			{
				i++;
				num_end--;
			}
	if (flag == 1)
		return "no";
	else
		return "yes";
}
int main()
{
	char str[100];
	gets_s(str);
	cout << huiweng(str) << endl;
	
	return 0;
}