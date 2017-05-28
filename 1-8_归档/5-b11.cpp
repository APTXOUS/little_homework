/*1650254 计1 尤尧寅*/
#include<iostream>
#include<iomanip>
using namespace std;
int zeller(int year, int month, int day)
{
	int c, y, m, d, w;
	if (month == 1 || month == 2)
	{
		c = (int)((year - 1) / 100);
		y = (int)((year - 1) % 100);
		m = month + 12;
	}
	else
	{
		c = (int)(year / 100);
		y = (int)(year % 100);
		m = month;
	}
	d = day;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0)
		while (w < 0)
			w = w + 7;
	w = w % 7;
	return w;
}

void title(int a)
{
	for(int i=0;i<3;i++)
		cout << "              "<<setw(2)<<a/7*3+i+1<<"月              ";
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << "  Sun Mon Tue Wed Thu Fri Sat   ";
	cout << endl;
}
int reng(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
		return 1;
	else
		return 0;
}
int main()
{
	int a, b[500][500] = { 0 };
	while (1)
	{
		cout << "请输入1900 - 2100之间的年份：";
		cin >> a;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "输入错误请重新输入（1900-2100之间的年份）：" << endl;
		}
		else if (a >= 1900 && a <= 2000)
			break;
	}
	int num2;
	if (reng(a))
	{
		num2 = 29;
	}
	else
	{
		num2 = 28;
	}
	for (int s = 0; s < 4; s++)
	{
		for (int i = 0+s*3; i < 3+s*3; i++)//kuai
		{
			for (int j = 0+s * 7; j < 7 + s * 7; j++)//hang
			{
				for (int m = 0 + (i-s*3) * 7; m < 7 + (i-s*3) * 7; m++)//lie
				{
					if (j == 0 + s * 7 && m == 0 + (i-s*3) * 7)
					{
						b[j][0+(i-s*3)*7 + zeller(a, i + 1, 1)] = 1;
						m = (i-s*3) * 7 + zeller(a, i + 1, 1);
					}
					else if (m == 0 + (i-s*3) * 7 && j != 0 + s * 7)
					{
						b[j][m] = b[j - 1][6 + (i-s*3) * 7] + 1;
					}
					else
						b[j][m] = b[j][m - 1] + 1;
					if (b[j][m] == 31 && (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i==9||i == 11))
					{
						j = 7 + s * 7;
						break;
					}
					else if (b[j][m] == 30 && (i == 3 || i == 5 || i == 8 || i == 10 ))
					{
						j = 7 + s * 7;
						break;
					}
					if (i == 1 && b[j][m] == num2)
					{
						j = 7 + s * 7;
						break;
					}
				}
			}
		}
	}

	cout << a << "年的月历为：" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 28; i++)
	{
		if (i == 0 || i == 7 || i == 14 || i == 21)
			title(i);
		for (int j = 0; j < 21; j++)
		{
			cout << " ";
			if (b[i][j] != 0)
				cout << setw(3) << b[i][j];
			else
				cout << "   ";
			if (j == 6 || j == 13)
			{
				cout << "    ";
			}
		}
		cout << endl;

	}
	system("pause");
	return 0;
	
}