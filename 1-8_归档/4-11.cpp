/* 1650254 ��1 ��Ң��*/
#include <iostream>
using namespace std;
int f(int n)
{
	if (n == 1)
		return 1;
	else
		return (n*n + f(n - 1));


}


int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else if (n <= 0)
		{
			cout << "������һ������0������" << endl;
			return 0;
		}
		else
			break;

	}
	cout << f(n) << endl;
	return 0;

}