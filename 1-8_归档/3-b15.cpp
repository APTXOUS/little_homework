/* 1650254 ��1 ��Ң��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
int num = 0;
using namespace std;
int add(int a, int b, int n)
{
	num++;
	if (n == 3)
		return (a + b);
	else
		return add(b, a + b, --n);
}

int main()
{
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&fc_begin);	//��ó�ʼӲ����ʱ������

										/* �˴�����ĳ���ʼ */
	int n;
	for (n = 1; n <= 40; n++)
	{
		if (n == 0)
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) <<"0" << endl;
		else if (n == 1 || n == 2)
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << "1" << endl;
		else
		{
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << n;
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << add(1,1,n);
			cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << num << endl;
			num = 0;
		}
	}
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&fc_end);//�����ֹӲ����ʱ������
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "ʱ��Ƶ�ʣ�" << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "ʱ�Ӽ�����" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "��" << endl;
	system("pause");
	return 0;
}
