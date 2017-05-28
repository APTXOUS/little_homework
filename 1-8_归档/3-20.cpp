/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
using namespace std;
int main()
{
	int i, c = -1, sum = 0, j;
	for (i = 2; i <= 1000; i++)
	{
		for (j = 1; j < i; j++)
		{
			c = i%j;
			if (c == 0)
				sum += j;
		}
		if (sum == i)
		{
			cout << i << ",";
			c = -1;
			cout << "its factors are ";
			for (j = 1; j < i; j++)
			{
				c = i%j;
				if (j != 1&&c==0)
					cout << ",";
				if (c == 0)
					cout << j;
			}
			cout << endl;
		}
		sum = 0;
		c = -1;
	}
	return 0;
}