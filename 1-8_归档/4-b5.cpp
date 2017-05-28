/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
using namespace std;
void f(int n)
{
	if(n==1||n==2||n==3||n==4||n==5||n==6||n==7||n==8||n==9||n==0)
		cout<<n<<' ';
	else 
	{
		cout<<n%10<<' ';
		f((n-n%10)/10);
	}
}

int main()
{
	
	int n, t;
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
		t = -1 * n;
	f(t);
	if(n<0)
	cout<<"-";

	return 0;
}

