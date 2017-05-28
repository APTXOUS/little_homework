/*1650254 尤尧寅 计1*/
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	char temp;
	char ch[10000];
	char *p = ch;
	char *a[10];
	char **k = a;
	int num = 0;
	int count = 0;
	int count_zero = 0;
	while (1)
	{
		temp = getchar();
		if (temp == '\n')
			break;
		else
		{
			*p = temp;
			if (temp == '0'&&num == 1 && *(p - 1) == '0')
				count_zero++;
			else
				count_zero = 0;
			if (temp <= '9'&&temp >= '0')
			{
				if (num == 1 && count_zero != 0 )
				{
					*(k - 1) = p;
					num = 1;
					p++;
					continue;
				}
				if (num == 1 && *(p - 1) == '0'&&temp != '0')
				{
					*(k - 1) = p;
					num = 1;
					p++;
					continue;
				}
				num++;
				if (num == 1)
				{
					if (temp == '0')
						count_zero = 1;
					count++;
					*(k++) = p;
				}
				
				p++;
			}
			else
			{
				count_zero = 0;
				if (num != 0)
				{
					num = 0;
					p++;
					*p = temp;
					*(p - 1) = '\0';
				}
			}
		}
	}
	*p = '\0';
	cout << "共" << count << "个整数" << endl;
	for (int i = 0; i < count; i++)
		cout <<"a["<<i<<"]="<< *(a + i) << endl;
	return 0;
}