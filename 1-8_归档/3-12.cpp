/* 1650254 ��1 ��Ң�� */
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
	cout << "����";
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
	cout << "λ��" << endl;
	if (num == 1)
		cout << "����" << t<<"\n"<< "����" << t;
	else if (num == 2)
		cout << "����" << t << " " << r<<"\n"<< "����" << r << " " << t;
	else if (num == 3)
		cout << "����" << e << " " << r << " " << t << "\n" << "����" << t << " " << r << " " << e;
	else if (num == 4)
		cout << "����" << w << " " << e << " " << r << " " << t << "\n" << "����" << t << " " << r << " " << e<<" "<<w;
	else if (num == 5)
		cout << "����" << q << " " << w << " " << e << " " << r << " " << t << "\n" << "����" << t << " " << r << " " << e << " " << w << " " << q;
	return 0;
}
