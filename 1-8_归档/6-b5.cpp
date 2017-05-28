/*1650254 схр╒рЗ ╪ф1*/
#include<iostream>
#include<string.h>
using namespace std;
unsigned int change_mode(char *p)
{
	int i = strlen(p) - 1;
	unsigned int ans = 0;
	unsigned int count = 1;
	while (1)
	{
		if (i == -1)
			break;
		ans += (*(p + i--) - '0')* count;
		count *= 2;
	}
	return ans;
}
int main()
{
	char two[32];
	cin >> two;
	cout << change_mode(two) << endl;

	return 0;
}