/*1650254 1�� ��Ң��*/
#include<iostream>
using namespace std;
int main()
{
	void sort(int x, int y, int z);
	int x, y, z;
	cin >> x >> y >> z;
	sort(x, y, z);
	return 0;
}
void sort(int x, int y,int z)
{
	int temp;
	if (x > y) { temp = x; x = y; y = temp; }
	if (z < x) cout << z << ',' << x << ',' << y << endl;
	else if (z < y)cout << x << ',' << z << ',' << y << endl;
	else cout << x << ',' << y << ',' << z << endl;
}

/*���鱾�������εĽ����
   3��6��10
   �����Ĵ�����
   10��6��3ʱ
   ��
   -858993460,-858993460,10
   ����Ĺ�����
   �������������
   ��С�����������
   ������֮����붺��
*/
