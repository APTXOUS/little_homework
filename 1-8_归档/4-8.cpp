/*1650254 ¼Æ1 ÓÈÒ¢Òú*/
#include<iostream>
using namespace std;
double de(double x,int n)
{
	if(n==0) 
		return 1;
	else if(n==1) 
		return x;
	else 
		return ( (2*n-1)*x*de(n-1,x) - (n-1)*de(n-2,x) )/n;
} 
int main()
{
	double x;
	int n;
	while(1)
	{
		cin>>x>>n;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			return 0;
		}
		else if(n<0)
		{
			cout<<"error";
			return 0;
		}
		else
			break;
	}
	cout<<de(x,n)<<endl;
	return 0;
}
		
