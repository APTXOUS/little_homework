/*1650254 尤尧寅 计1*/
#include<iostream>
#include<math.h>
using namespace std;
const double num_of_point = 5000000;
double fun_sin(double a,double n)
{
	return sin(a)*n;
}
double fun_cos(double a, double n)
{
	return cos(a)*n;
}
double fun_exp(double a, double n)
{
	return exp(a)*n;
}
double definite_integration(double (*a)(double pre,double n),double high,double low,double n)
{
	cout << "采样个数为" <<num_of_point << endl;
	double sum=0;
	for (int i = 0; i < num_of_point; i++)
		sum += a(low + i*n,n);
	return sum;
}
int main()
{
	double low, high, value;
	while (1)
	{
		cin >> low >> high;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024,'\n');	
			cout << "输入错误" << endl;
		}
		else
	    	break;
	}
	value = definite_integration(fun_sin,high,low,(high-low)/ num_of_point);
	cout << value << endl;
	while (1)
	{
		cin >> low >> high;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误" << endl;
		}
		else
			break;
	}
	value = definite_integration(fun_cos,high,low, (high - low) / num_of_point);
	cout << value << endl;

	while (1)
	{
		cin >> low >> high;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入错误" << endl;
		}
		else
			break;
	}
	value = definite_integration(fun_exp,high,low, (high - low) / num_of_point);
	cout << value << endl;
	
	return 0;
}