/*1650254 ��1 ��Ң��*/
#include<iostream>
#include <iomanip>  
using namespace std;
extern int a=0;

int add(int n)
{
	a++;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return add(n - 1) + add(n - 2);
}

int main()
{
	int n;
	/*while (1)
	{
		cin >> n;
		if (cin.fail())
		{
			cout << "�����������������" << endl;
			cin.clear();
			cin.ignore();
		}
		if (n < 0)
			cout << "�������"<<endl;
		else
			break;
	}*/
	
	for (n = 1; n <= 40; n++)
	{
		cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << n;
		cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << add(n);
		cout << setiosflags(ios::fixed) << setiosflags(ios::left) << setw(10) << a << endl;
		a = 0;
	}
	system("pause");
	return 0;




}