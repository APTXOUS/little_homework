/* 1650254 ╪ф1 схр╒рЗ */
#include <iostream>
#include <iomanip>  
using namespace std;

int main()
{
	int q, w, e, r;
	int min1, min2, max1, max2;
	cin >> q >> w >> e >> r;
	if (q <= w)
	{
		min1 = q;
		max1 = w;
	}
	else
	{
		min1 = w;
		max1 = q;
	}
	if (e <= r)
	{
		min2 = e;
		max2 = r;
	}
	else
	{
		min2 = r;
		max2 = e;
	}
	if (min1 <= min2)
	{
		cout << min1 << " ";
		if (min2 <= max1)
		{
			cout << min2<<" ";
			if (max1 <= max2)
				cout << max1 <<" "<< max2;
			else
				cout << max2 <<" "<< max1;
		}
		else
			cout << max1<<" "<< min2 <<" "<< max2;
	}
	else
	{
		cout << min2<<" ";
		if (min1 <= max2)
		{
			cout << min1<<" ";
			if (max1 <= max2)
				cout << max1 <<" "<< max2;
			else
				cout << max2 <<" "<< max1;
		}
		else
			cout << max2 << min1 << max1;
	}
	return 0;
}
