/* 1650254 计1 尤尧寅 */
#include <iostream>
#include <iomanip>  
using namespace std;

int main()
{
	int a, b;
	int q, w, e, r, t, num=5;
	cin >> b;
	a = b;
	q = a / 10000;
	a = a - q * 10000;
	w = a / 1000;
	a = a - w * 1000;
	e = a / 100;
	a = a - e * 100;
	r = a / 10;
	a = a - r * 10;
	t = a;
	cout << "它是";
	if (q == 0)
	{
		num--;
		if (w == 0)
		{
			num--;
			if (e == 0)
			{
				num--;
				if (r == 0)
				{
					num--;
					if (t == 0)
						num--;
					else
						cout << num;
				}
				else
					cout << num;
			}
			else
				cout << num;
		}
		else
			cout << num;
	}
	else
		cout << num;
	cout << "位数" << endl;
	if (num == 1)
		cout << "正序" << t<<"\n"<< "逆序" << t;
	else if (num == 2)
		cout << "正序" << t << " " << r<<"\n"<< "逆序" << r << " " << t;
	else if (num == 3)
		cout << "正序" << e << " " << r << " " << t << "\n" << "逆序" << t << " " << r << " " << e;
	else if (num == 4)
		cout << "正序" << w << " " << e << " " << r << " " << t << "\n" << "逆序" << t << " " << r << " " << e<<" "<<w;
	else if (num == 5)
		cout << "正序" << q << " " << w << " " << e << " " << r << " " << t << "\n" << "逆序" << t << " " << r << " " << e << " " << w << " " << q;
	return 0;
}
