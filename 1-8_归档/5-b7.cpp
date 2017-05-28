/* 1650254 计1 尤尧寅 */
#include <iostream>
#include <cstdio>
#include <conio.h>

#include <windows.h>
#include <iomanip>
using namespace std;

double num = 0;
int a1[11] = { 0 };
int b1[11] = { 0 };
int c1[11] = { 0 };
int speed;
int co=1;
int xianshi = -1;
void time(int speed)
{
	if (speed == 0)
	{
		if (co == 1)
		{
			co = 0;
			getchar();
			getchar();

		}
		else
		{
			getchar();
		}
	}
	else if(speed == 1)
		Sleep(500);
	else if (speed == 2)
		Sleep(400);
	else if (speed == 3)
		Sleep(300);
	else if (speed == 4)
		Sleep(200);
	else if (speed == 5)
		Sleep(10);
}
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}
void print1()
{
	cout << " A:";
	for (int i = 9; i >= 0; i--)
	{
		if (a1[i] != 0)
			cout << setw(2) << a1[i];
	}
	for (int i = 9; i >= 0; i--)
	{
		if (a1[i] == 0)
			cout << "  ";
	}
	cout << " B:";
	for (int i = 9; i >= 0; i--)
	{
		if (b1[i] != 0)
			cout << setw(2) << b1[i];
	}
	for (int i = 9; i >= 0; i--)
	{
		if (b1[i] == 0)
			cout << "  ";
	}
	cout << " C:";
	for (int i = 9; i >= 0; i--)
	{
		if (c1[i] != 0)
			cout << setw(2) << c1[i];
	}
	for (int i = 9; i >= 0; i--)
	{
		if (c1[i] == 0)
			cout << "  ";
	}
}
void print(int n, char a, char b, char c,int num1)//输出部分
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (xianshi == 1)
	{
		gotoxy(hout, 0, 18);
		cout << setiosflags(ios::right) << setw(5) << num1;
		cout << ": ";
		cout << setw(2) << n;
		cout << "#" << " " << a << "---->" << c;
		print1();
	}
	if(speed==0)
		time(speed);
	int num2 = 0;
	for (int i = 9; i >= 0; i--)
	{
	
		if (a1[i] != 0)
		{
			gotoxy(hout, 11, 13-num2);
			cout << a1[i];
			num2++;
			
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		if (a1[i] == 0)
		{
			gotoxy(hout, 11, 13 - num2);
			cout << "  ";
			num2++;
			 
		}
	}
	num2 = 0;
	for (int i = 9; i >= 0; i--)
	{
		
		if (b1[i] != 0)
		{
			gotoxy(hout, 21,13-num2);
			cout << b1[i];
			num2++;
			
		}

	}
	for (int i = 9; i >= 0; i--)
	{
		if (b1[i] == 0)
		{
			gotoxy(hout, 21, 13 - num2);
			cout << "  ";
			num2++;
			
		}
	}
	num2 = 0;
	for (int i = 9; i >= 0; i--)
	{
			
		if (c1[i] != 0)
		{
			gotoxy(hout, 32,13-num2);
			cout << c1[i];
			num2++;
		
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		if (c1[i] == 0)
		{
			gotoxy(hout, 32, 13 - num2);
			cout << "  ";
			num2++;
			
		}
	}

	time(speed);

}
void set(int x[], int n)//初始化
{
	for (int i = 0; i < n; i++)
	{
			x[i] = i + 1;
	}
}
void push(int x[], int y[])//出栈入栈
{
	for (int j = 9; j >= 0; j--)
	{
		y[j] = y[j - 1];
	}
	y[0] = x[0];
	for (int j = 0; j < 10; j++)
		x[j] = x[j + 1];


}
void change(char flag1, char flag2)//交换
{
	if (flag1 == 'A'&&flag2 == 'B')
	{
		push(a1, b1);
	}
	else if (flag1 == 'A'&&flag2 == 'C')
	{
		push(a1, c1);
	}
	else if (flag1 == 'B'&&flag2 == 'C')
	{
		push(b1, c1);
	}
	else if (flag1 == 'B'&&flag2 == 'A')
	{
		push(b1, a1);
	}
	else if (flag1 == 'C'&&flag2 == 'A')
	{
		push(c1, a1);
	}
	else if (flag1 == 'C'&&flag2 == 'B')
	{
		push(c1, b1);
	}
}
void hn(int n, char a, char b, char c)	//汉诺塔
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	void change(char flag1, char flag2);
	if (n == 1)
	{
		num++;

		change(a, c);
		print(n, a, b,c,num);
		

	}
	else
	{
		n--;
		hn(n, a, c, b);
		num++;
		n = n + 1;
		change(a, c);
		print(n, a, b, c,num);
		
		n = n - 1;
		hn(n, b, a, c);
	}
}
void clear()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 0, 0);
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;

	gotoxy(hout, 0, 0);

}
int main()
{
	void set(int x[], int n);
	int n;
	char a, b, c;
	while (1)
	{
		while (1)
		{
			cout << "请输入层数<1-10>";
			cin >> n;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();

			}
			if (n >= 1 && n <= 10)
				break;
		}
		while (1)
		{
			cout << "请输入起始圆柱名<A-C>";
			cin >> a;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();

			}
			if (a == 'A' || a == 'B' || a == 'C')
				break;
		}
		while (1)
		{
			cout << "请输入结束圆柱名<A-C>";
			cin >> c;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();

			}
			if ((c == 'A' || c == 'B' || c == 'C') && (c != a))
				break;
		}
		while (1)
		{
			cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)";
			cin >> speed;//记得要判断输入输出！！！！！！！！
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();

			}
			if (speed==0||speed==1||speed==2||speed==3||speed==4||speed==5)
				break;
		}
		while (1)
		{
			cout << "请输入是否显示内部数组值(0-不显示 1-显示)";
			cin >> xianshi;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore();

			}
			if (xianshi == 1 || xianshi == 0)
				break;
		}
		break;

	}
	if (a == 'A'&&c == 'B')
	{
		b = 'C';
		set(a1, n);
	}
	else if (a == 'A'&&c == 'C')
	{
		b = 'B';
		set(a1, n);
	}
	else if (a == 'B'&&c == 'C')
	{
		b = 'A';
		set(b1, n);
	}
	else if (a == 'B'&&c == 'A')
	{
		b = 'C';
		set(b1, n);
	}
	else if (a == 'C'&&c == 'A')
	{
		b = 'B';
		set(c1, n);
	}
	else if (a == 'C'&&c == 'B')
	{
		b = 'A';
		set(c1, n);
	}
	clear();
	cout << "从" << a << "移动到" << c << "，共 "<<n<<" 层，延时设置为" << speed;
	if (xianshi == 1)
		cout << "，显示内部数组值：" << endl;
	else
		cout << ",不显示内部数组值：" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "         =========================" << endl;
	cout << "           A         B          C  ";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	print(n, a, b, c, num);
	hn(n, a, b, c);

	return 0;
}