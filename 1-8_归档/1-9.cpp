/*1650254 1�� ��Ң��*/
#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	int add(int x, int y);
	cin >> a >> b;
	c = add(a, b);
	cout << "a+b=" << c<<endl;
	return 0;
}
int add(int x, int y)
{
	int z;
    z = x + y;
	return(z);
}

/*ԭ����Ĵ�����
1.û������add����
2.û�ж������c
3.��c = add(a, b)��©�򡰣���
4.���ͱ���a��bû�б���ֵ
5.int add(int x, int y)���򡰣���
6.û����add�����ж������z��
7.return���retrun
 */
