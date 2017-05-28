/*1650254 ��1 ��Ң��*/
#include<iostream>
using namespace std;
int is_power(int num, int base)
{
	if (num == 1)
		return 1;
	else if (num%base == 0)
		return is_power(num / base, base);
	else
		return 0;
}
int main()
{
	int num, base;
	while (1)
	{
		cin >> num >> base;
		if (cin.fail())
		{
			cout << "�������" << endl;
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if (num < 1 || base < 2 || base > num)
		{
			cout << "�������" << endl;
			return 0;
		}
		else
			break;
	}
	cout << is_power(num,base);

	return 0;




}