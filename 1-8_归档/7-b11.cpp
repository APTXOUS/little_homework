/*1650254 尤尧寅 计算机一班*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define min_l 64
#define max_l 64000
#define voi_l 100
#define min_n 1
#define max_n 10000
#define voi_n 128
#define _l 1
#define _n 2
#define _t 3
#define ip 4
#define OK 1024
#define errorof_l 10
#define errorof_n 11
#define errorof_ip 12
#define repeaterror 13
int judge(char *judge_souce)
{
	if (judge_souce[0] == '-')
	{
		if (judge_souce[1] == 'l'&&judge_souce[2] == '\0')
			return 1;
		else if (judge_souce[1] == 'n'&&judge_souce[2] == '\0')
			return 2;
		else if (judge_souce[1] == 't'&&judge_souce[2] == '\0')
			return 3;
		else
			return -1;
	}
	else if (judge_souce[0] <= 57 && judge_souce[0] >= 48)
	{
		int countofdozen = 0;
		int i = 0;
		while (1)
		{
			while (judge_souce[i] != '\0')
			{
				if (judge_souce[i] == '.')
					countofdozen++;
				else if (atoi(&(judge_souce[i])) > 255 || atoi(&(judge_souce[i])) < 0)
					return -2;
				else if (judge_souce[i] != '.'&& (judge_souce[i] > 57 || judge_souce[i] < 48))
					return -2;
				else
					;
				i++;
			}
			if (countofdozen == 3)
				return 4;
			else
				return -2;
		}
	}
	else
		return -10;
}
void output_result(int p,int l,int n,int t)
{
	if (p == errorof_ip)
		cout << "ip地址错误" << endl;
	if (p == errorof_l)
		cout << "-l缺少参数" << endl;
	if (p == errorof_n)
		cout << "-n缺少参数" << endl;
	if (p == repeaterror)
		cout << "命令重复" << endl;
	if (p == OK)
	{
		cout << "正确" << endl;
		cout << "l=" << l << endl;
		cout << "n=" << n << endl;
		cout << "t=" << t << endl;
	}
	if (p == -10)
		cout << "ip地址错误" << endl;
}
int main(int argc,char *argv[])
{
	int book[4] = { 0 };
	int l=voi_l, n=voi_n, t=0;
	int p = errorof_ip;
	for (int i = 1; i < argc; i++)
	{
		int mode = judge(argv[i]);
		if (mode == _l)
		{
			int temp = judge(argv[i + 1]);
			if (temp != _l&&temp != _n&&temp != _t&&temp!=ip)
			{
				int num = atoi(argv[i+1]);
				if (num <= max_l&&num >= min_l)
					l = num;
				else
					;
				i++;
			}
			else
				p = errorof_l;
			book[_l - 1] ++;
		}
		else if (mode == _n)
		{
			int temp = judge(argv[i + 1]);
			if (temp != _l&&temp != _n&&temp != _t&&temp != ip)
			{
				int num = atoi(argv[i + 1]);
				if (num <= max_n&&num >= min_n)
					n = num;
				else
					;
				i++;
			}
			else
				p = errorof_n;
			book[_n - 1]++;
		}
		else if (mode == _t)
		{
			t = 1;
			book[_t - 1]++;
		}
		else if (mode == ip)
		{
			book[ip - 1]++;
			if (p == errorof_ip)
				p = OK;
		}
		else if (mode == -2)
		{
			p = errorof_ip;
		}
		else if (mode == -10)
		{
			p = -10;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (book[i] > 1)
			p = repeaterror;
	}
	output_result(p, l, n, t);
	return 0;
}