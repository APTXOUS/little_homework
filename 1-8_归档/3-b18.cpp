/*1650254 ��1 ��Ң��*/
#include <iostream>
#include <stdlib.h>	//srand/rand����
#include <time.h>	//time����
#include<iomanip>
using namespace std;
int main()
{
	int i, n=0;
	int num, rem, rem1, rem2;
	double mon, mon1;
	unsigned int t;
	unsigned long long sum = 0;
	double temp;
	int spen1,spen2;
	int spe1,spe2;
	double k = 0, m = 0;
	while(1)
	{ 
		cin >> num >> mon;
		if (mon >= num*0.01)
			break;
	}

	t = (unsigned int)time(0);//�洢ʱ��
	srand(t);
	for (i = 0; i < num; i++)
	{
		sum += rand();//��������ۼ�
	}
	mon1 = mon * 100;//����Ǯ��
	rem = (int)mon1;//��rem����ֵ
	mon1 = (int)mon1;//ǿתint��֤����
	srand(t);
	for (i = 0; i <= num; i++)
	{
		rand();
		if (i == num)
			spe1 = rand();//Ҫ������һ�������1
		if (i == 0)
			spe2 = rand();//Ҫ������һ�������2
	}

	spen1 = spe1%num;//�õ������Ǹ������1
	spen2 = spe2%num;//�õ������Ǹ������2
	srand(t);
	for (i = 0; i < num; i++)
	{
		temp = 1 + ((mon1 - num * 1)*(rand()*1.0 / sum));
		rem = rem - (int)temp;//ʣ�µ�Ǯ
	}
	if (spe1 % 2 == 0 && rem%2==0)
	{
		rem1 = rem / 2;
		rem2 = rem / 2;
	}
	else
	{
		rem1 = rem;
		rem2 = 0;
	}
	srand(t);
	for (i = 0; i < num; i++)
	{
		temp = 1 + ((mon1 - num * 1)*(rand()*1.0 / sum));
		if (i == spen1)
			temp = temp + rem1;
		if (i == spen2)
			temp = temp + rem2;
		temp = (int)temp;
		temp = temp / 100.0;
	        cout << setiosflags(ios::fixed) << setprecision(2) << temp << endl;
	}
	system("pause");
	return 0;
}