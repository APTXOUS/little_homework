/*1650254 ��1 ��Ң��*/
#include<iostream>
using namespace std;
int main()
{
	int x;
	int sum = 1;
	while (1)
	{
		if (sum == 1)
		{
			cout << "������x��ֵ��0-100����";
			cin >> x;
		}
		if (x >= 0 && x <= 100)
			break;
		if (cin.fail())
		{
			sum = 0;
			cin.clear();
			cin.ignore();
		}
		if (getchar() == '\n'||sum!=0)
			sum = 1;

	}


	cout << "x=" << x << endl;
	return 0;
}