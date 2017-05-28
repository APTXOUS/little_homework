/*1650254 计1 尤尧寅*/
#include<iostream>
using namespace std;

double add(double x, double y)
{
	return x + y;
}
double jian(double x, double y)
{
	return  (x-y);
}
double chen(double x, double y)
{
	return x*y;
}
double chu(double x, double y)
{
	return x*1.0 / y;
}
double all(double x, double y,int temp)
{
	if (temp == 1)
	{
		return add(x, y);
	}
	else if (temp == 2)
	{
		return jian(x, y);
	}
	else if (temp == 3)
	{
		return chen(x, y);
	}
	else
	{
		return chu(x, y);
	}
}
void p(int x)
{
	if (x == 1)
		cout << "+";
	else if (x == 2)
		cout << "-";
	else if (x == 3)
		cout << "*";
	else
		cout << "/";
}
void print(int x, int y, int z,int k,int a,int b,int c,int d)
{
	if (k == 1)
	{
		cout << "((" << a;
		p(x);
		cout << b << ")";
		p(y);
		cout << c << ")";
		p(z);
		cout << d <<"=24"<< endl;
	}
	else if (k == 2)
	{
		cout << "(" << a;
		p(x);
		cout << b << ")";
		p(y);
		cout <<"("<< c ;
		p(z);
		cout << d <<")"<<"=24"<< endl;
	}
	else if (k == 3)
	{
		cout << "(" << a;
		p(x);
		cout <<"("<< b ;
		p(y);
		cout << c << ")";
		p(z);
		cout << d << ")" <<"=24"<< endl;
	}
	else if (k == 4)
	{
		cout << a ;
		p(x);
		cout <<"(("<< b ;
		p(y);
		cout << c << ")";
		p(z);
		cout << d << ")" << "=24"<<endl;
	}
	else if (k == 5)
	{
		cout << a;
		p(x);
		cout << "(" << b;
		p(y);
		cout <<"("<< c;
		p(z);
		cout << d << "))" << "=24"<<endl;
	}
}
int main()
{
	int a, b, c, d;
		while (1)
	{
		cout << "请输入四个（1-10）之间的整数 :";
		cin >> a >> b >> c >> d;
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
			cin.ignore();
		}
		else if ((a >= 1 && a <= 10) && (b >= 1 && b <= 10) && (c >= 1 && c <= 10) && (d >= 1 && c <= 10))
			break;
	}
	double sum;
	int num = 0;
	for (int j = 1; j <=4; j++)//no1
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int m = 1; m <= 4; m++)
			{
				sum = all(all(all(a, b, j),c, k),d, m);
				if (sum == 24) {
					print(j, k, m,1,a,b,c,d);
					num++;
				}
			}
		}		
	}
	for (int j = 1; j <= 4; j++)//no2
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int m = 1; m <= 4; m++)
			{
				sum = all(all(a, b, j), all(c, d, m), k);
				if (sum == 24) {
					print(j, k, m,2,a,b,c,d);
					num++;
				}
			}
		}
	}
	for (int j = 1; j <= 4; j++)//no3
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int m = 1; m <= 4; m++)
			{
				sum = all(all(a, all(b, c, k), j), d, m);
				if (sum == 24) {
					print(j, k, m,3,a,b,c,d);
					num++;
				}
			}
		}
	}
	for (int j = 1; j <= 4; j++)//no4
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int m = 1; m <= 4; m++)
			{
				sum = all(a, all(all(b, c, k), d, m), j);
				if (sum == 24) {
					print(j, k, m,4,a,b,c,d);
					num++;
				}
			}
		}
	}
	for (int j = 1; j <= 4; j++)//no5
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int m = 1; m <= 4; m++)
			{
				sum = all(a, all(b, all(c, d, m), k), j);
				if (sum == 24) {
					print(j, k, m,5,a,b,c,d);
					num++;
				}
			}
		}
	}
	if (num == 0)
		cout << "无解" << endl;
	return 0;
}