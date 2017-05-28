/*1650254 计1 尤尧寅*/
#include<iostream>
#include<iomanip>
using namespace std;
double num = 0;
int a1[11] = { 0 };
int b1[11] = { 0 };
int c1[11] = { 0 };
void print()//输出部分
{
	cout << " A:";
	for (int i = 9; i >=0; i--)
	{
		if (a1[i] != 0)
			cout << setw(2)<<a1[i];
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
			cout <<setw(2)<< b1[i] ;
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
			cout <<setw(2)<< c1[i];
	}
	for (int i = 9; i >= 0; i--)
	{
		if (c1[i] == 0)
			cout << "  ";
	}
	cout << endl;

}
void set(int x[],int n)//初始化
{
	for (int i = 0; i < n; i++)
	{
		x[i] = i + 1;
	}
}
void push(int x[], int y[])//出栈入栈
{
	for (int j =9; j >=0; j--)
	{
		y[j] = y[j-1];
	}
	y[0] = x[0];
	for (int j = 0; j < 10; j++)
		x[j] = x[j + 1];
	

}
void change(char flag1,char flag2)//交换
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
void hn(int n, char a, char b, char c)//汉诺塔
{

	if (n == 1)
	{
		num++;
		cout << setiosflags(ios::right) << setw(5) << num;
		cout << ": ";
		cout << setw(2)<<n;
		cout << "#" << " " << a << "---->" << c;
		change(a, c);
		print();
	}
	else
	{
		n--;
		hn(n, a, c, b);
		num++;
		cout << setiosflags(ios::right) << setw(5) << num;
		cout << ": ";
		cout <<setw(2)<< n + 1;
		cout << "#" << " " << a << "---->" << c;
		change(a,c);
		print();
		hn(n, b, a, c);
	}
}
int main()
{
	int n;
	char a, b, c;
	while (1)
	{
		cout << "请输入层数<1-10>";
		cin >> n;
		cout << "请输入起始圆柱名<A-C>";
		cin >> a;
		cout << "请输入结束圆柱名<A-C>";
		cin >> c;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (n < 0)
		{
			cout << "error";
			return 0;
		}
		else if (a!='A'&& a != 'B' && a != 'C' )
		{
			cout << "error";
			system("pause");
			return 0;
		}
		else if (c != 'A' && c != 'B' && c != 'C')
		{
			cout << "error";
				system("pause");
			return 0;
		}
		else
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
	cout << "初始：            ";
	print();
	hn(n, a, b, c);
	system("pause");
	return 0;
}