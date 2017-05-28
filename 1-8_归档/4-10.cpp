/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
#include<math.h>
using namespace std;
void f(int n)
{
	if(n/10!=0)
		f(n/10);
	cout<<(n%10)<<" ";
}

int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			return 0;
		}
		else
			break;
	}
	if (n < 0)
	{
		cout << "- ";
		n = -1 * n;
	}
	f(n);

	return 0;
}

