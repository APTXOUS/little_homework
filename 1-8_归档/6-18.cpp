/*1650254 ��Ң�� ��1*/
#include<iostream>
using namespace std;
int main()
{
	int mouth;
	char *ENG_mouth[12]= { "Janurary","February","March","April",
							"May","June","July","August",
							"September","October","November","December" };
	while (1)
	{
		cin >> mouth;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�·��������" << endl;
		}
		else
			break;	
	}
	if (mouth >= 1 && mouth <= 12)
		cout << *(ENG_mouth+mouth-1) << endl;
	else
		cout << "invalid" << endl;

	return 0;
}