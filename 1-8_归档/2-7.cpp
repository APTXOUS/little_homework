//*1650254 1�� ��Ң��*/
#include<iostream>
using namespace std;
int main()
{
	int i, j, m, n;
	i = 8;
	j = 10;
	m = ++i + j++;
	n = (++i) + (++j) + m;
	cout << i << '\t' << j << '\t' << m << '\t' << n << endl;
	return 0;
}
/*
�������н��
10      12      19      41
������
m=9+10=19
֮��i=9 j=11
n=10+12+19=41
��ʱi=10 j=12 m=19 n=41
*/
