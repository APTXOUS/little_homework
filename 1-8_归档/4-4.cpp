/*1650254 计1 尤尧寅*/
#include<iostream>
using namespace std;
int fac(int n)
{
	if(n==1||n==0)
		return 1;
	else
		return n*fac(n-1);
}
int main()
{
	int a,b,c;
	while(1)
	{
		cout<<"请确保a！+b！+c！不超过2147483648"<<endl;
		cin>>a>>b>>c;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			return 0;		
		}
		else
			break;
	}
	cout<<(fac(a)+fac(b)+fac(c))<<endl;

	return 0;
} 
