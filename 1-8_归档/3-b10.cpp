/* 1650254 ��1 ��Ң�� */
#include<iostream>
#include <iomanip>  
using namespace std;

int main()
{
	int q, w, e, r, t, y, u, i, o, p, s, d;
	double a;
	int count = 0;
	int tab = 0;
	cin >> a;
	a = a + 0.001;
	q = (int)(a / 1000000000);
	a = a - q * 1000000000.0;
	w = (int)(a / 100000000);
	a = a - w * 100000000.0;
	e = (int)(a / 10000000);
	a = a - e * 10000000.0;
	r = (int)(a / 1000000);
	a = a - r * 1000000.0;
	t = (int)(a / 100000);
	a = a - t * 100000.0;
	y = (int)(a / 10000);
	a = a - y * 10000.0;
	u = (int)(a / 1000);
	a = a - u * 1000.0;
	i = (int)(a / 100);
	a = a - i * 100.0;
	o = (int)(a / 10);
	a = a - o * 10.0;
	p = (int)(a / 1.0);
	a = a - p * 1;
	s = (int)(a / 0.1);
	a = a - s * 0.1;
	d = (int)(a / 0.01);
	switch (q)
	{
		case 0:
			tab = 0;
			break;
		case 1:
			cout << "Ҽʰ"; 
			tab = 1;
			break;
		case 2:
			cout << "��ʰ";
			tab = 1;
			break;
		case 3:
			cout << "��ʰ"; 
			tab = 1;
			break;
		case 4:
			cout << "��ʰ"; 
			tab = 1;
			break;
		case 5:
			cout << "��ʰ";
			tab = 1;
			break;
		case 6:
			cout << "½ʰ";
			tab = 1;
			break;
		case 7:
			cout << "��ʰ";
			tab = 1;
			break;
		case 8:
			cout << "��ʰ";
			tab = 1;
			break;
		case 9:
			cout << "��ʰ";
			tab = 1;
			break;
	}
	switch (w)
	{
		case 0:
			if (tab == 0)
				tab = 0;
			break;
		case 1:
			cout << "Ҽ";
			tab = 1;
			break;
		case 2:
			cout << "��";
			tab = 1;
			break;
		case 3:
			cout << "��";
			tab = 1;
			break;
		case 4:
			cout << "��"; 
			tab = 1;
			break;
		case 5:
			cout << "��";
			tab = 1;
			break;
		case 6:
			cout << "½"; 
			tab = 1;
			break;
		case 7:
			cout << "��";
			tab = 1;
			break;
		case 8:
			cout << "��";
			tab = 1;
			break;
		case 9:
			cout << "��";
			tab = 1;
			break;
	}
	if (q != 0 || w != 0)
	{
		cout << "��";
		count = 0;
	}
	switch (e)
	{
		case 0:
			count += 1; 
			if (tab == 0)
				tab = 0;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "ҼǪ";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ"; 
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½Ǫ";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
	}
	switch (r)
	{
		case 0:
			count += 1;
			if (tab == 0)
				tab = 0;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "Ҽ��";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "���";
			tab = 1;
			count = 0;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½��";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "���";
			tab = 1;
			count = 0;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "�ư�";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
	}
	switch (t)
	{
		case 0:
			count += 1;
			if (tab == 0)
				tab = 0;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "Ҽʰ";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			tab = 1;
			count = 0;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½ʰ";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			tab = 1;
			count = 0;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			tab = 1;
			count = 0;
			break;
	}
	switch (y)
	{
		case 0:
			count += 1;
			if (tab == 0)
				tab = 0;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "Ҽ"; 
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��"; 
			tab = 1;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��"; 
			tab = 1;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��"; 
			tab = 1;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½"; 
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��"; 
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��"; 
			tab = 1;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��"; 
			tab = 1;
			break;
	}
	if (e != 0 || r != 0 || t != 0 || y != 0)
	{
		cout << "��";
		count = 0;
	}
	else
	{	
		if((u!=0||i!=0||o!=0||p!=0)&&tab!=0&&(e != 0 && r != 0 && t != 0 && y != 0))
			cout << "��";
		count = 0;
	}
	switch (u)
	{
		case 0:
			if (tab == 0)
				tab = 0;
			count += 1;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "ҼǪ";
			count = 0;
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			count = 0;
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½Ǫ";
			count = 0;
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			count = 0;
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��Ǫ";
			count = 0;
			tab = 1;
			break;
		case 9:
			if (count != 0 && tab != 0)
				cout << "��";
			cout << "��Ǫ";
			count = 0;
			tab = 1;
			break;
	}
	switch (i)
	{
		case 0:
			count += 1;
			if (tab == 0)
				tab = 0;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "Ҽ��";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "���";
			count = 0;
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½��";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "���";
			count = 0;
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "�ư�";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			tab = 1;
			count = 0;
			break;
	}
	switch (o)
	{
		case 0:
			count += 1;
			if (tab == 0)
				tab = 0;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "Ҽʰ";
			count = 0;
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			count = 0;
			tab = 1;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			count = 0;
			tab = 1;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			count = 0;
			tab = 1;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			count = 0;
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½ʰ";
			count = 0;
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			count = 0;
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			count = 0;
			tab = 1;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��ʰ";
			count = 0;
			tab = 1;
			break;
	}
	switch (p)
	{
		case 0:
			count += 1;
			if (tab == 0)
				tab = 0;
			if (s == 0 && d == 0 && tab == 0)
				cout << "��";
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "Ҽ";
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½";
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "��";
			tab = 1;
			break;
	}
	if (q != 0 || w != 0 || e != 0 || r != 0 || t != 0 || y != 0 || u != 0 || i != 0 || o != 0 || p != 0 || (s == 0 && d == 0))
		cout << "Բ";
	else if((s!=0||d!=0)&&tab!=0)
		cout << "��";
	count = 0;
	switch (s)
	{
		case 0:
			count += 1;
			break;
		case 1:
			if (count != 0)
				cout << "��";
			cout << "Ҽ��";
			break;
		case 2:
			if (count != 0)
				cout << "��";
			cout << "����";
		break;
		case 3:
			if (count != 0)
				cout << "��";
			cout << "����";
			break;
		case 4:
			if (count != 0)
				cout << "��";
			cout << "����";
			break;
		case 5:
			if (count != 0)
				cout << "��";
			cout << "���";
			break;
		case 6:
			if (count != 0)
				cout << "��";
			cout << "½��";
			break;
		case 7:
			if (count != 0)
				cout << "��";
			cout << "���";
			break;
		case 8:
			if (count != 0)
				cout << "��";
			cout << "�ƽ�";
			break;
		case 9:
			if (count != 0)
				cout << "��";
			cout << "����";
			break;
	}
	switch (d)
	{
		case 0:
			count += 1;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "Ҽ��";
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "���";
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "½��";
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "���";
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "�Ʒ�";
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "��";
			cout << "����";
			break;
	}
	if ((s == 0 && d == 0) || (s != 0 && d == 0))
		cout << "��";
	return 0;
}
