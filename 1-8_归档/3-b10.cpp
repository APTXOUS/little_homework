/* 1650254 ¼Æ1 ÓÈÒ¢Òú */
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
			cout << "Ò¼Ê°"; 
			tab = 1;
			break;
		case 2:
			cout << "·¡Ê°";
			tab = 1;
			break;
		case 3:
			cout << "ÈşÊ°"; 
			tab = 1;
			break;
		case 4:
			cout << "ËÁÊ°"; 
			tab = 1;
			break;
		case 5:
			cout << "ÎéÊ°";
			tab = 1;
			break;
		case 6:
			cout << "Â½Ê°";
			tab = 1;
			break;
		case 7:
			cout << "ÆâÊ°";
			tab = 1;
			break;
		case 8:
			cout << "°ÆÊ°";
			tab = 1;
			break;
		case 9:
			cout << "¾ÁÊ°";
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
			cout << "Ò¼";
			tab = 1;
			break;
		case 2:
			cout << "·¡";
			tab = 1;
			break;
		case 3:
			cout << "Èş";
			tab = 1;
			break;
		case 4:
			cout << "ËÁ"; 
			tab = 1;
			break;
		case 5:
			cout << "Îé";
			tab = 1;
			break;
		case 6:
			cout << "Â½"; 
			tab = 1;
			break;
		case 7:
			cout << "Æâ";
			tab = 1;
			break;
		case 8:
			cout << "°Æ";
			tab = 1;
			break;
		case 9:
			cout << "¾Á";
			tab = 1;
			break;
	}
	if (q != 0 || w != 0)
	{
		cout << "ÒÚ";
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
				cout << "Áã";
			cout << "Ò¼Çª";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡Çª"; 
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÈşÇª";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁÇª";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÎéÇª";
			tab = 1;
			count = 0;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½Çª";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÆâÇª";
			tab = 1;
			count = 0;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°ÆÇª";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾ÁÇª";
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
				cout << "Áã";
			cout << "Ò¼°Û";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡°Û";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Èş°Û";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁ°Û";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Îé°Û";
			tab = 1;
			count = 0;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½°Û";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Æâ°Û";
			tab = 1;
			count = 0;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°Æ°Û";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾Á°Û";
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
				cout << "Áã";
			cout << "Ò¼Ê°";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡Ê°";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÈşÊ°";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁÊ°";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÎéÊ°";
			tab = 1;
			count = 0;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½Ê°";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÆâÊ°";
			tab = 1;
			count = 0;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°ÆÊ°";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾ÁÊ°";
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
				cout << "Áã";
			cout << "Ò¼"; 
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡"; 
			tab = 1;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Èş"; 
			tab = 1;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁ"; 
			tab = 1;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Îé";
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½"; 
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Æâ"; 
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°Æ"; 
			tab = 1;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾Á"; 
			tab = 1;
			break;
	}
	if (e != 0 || r != 0 || t != 0 || y != 0)
	{
		cout << "Íò";
		count = 0;
	}
	else
	{	
		if((u!=0||i!=0||o!=0||p!=0)&&tab!=0&&(e != 0 && r != 0 && t != 0 && y != 0))
			cout << "Áã";
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
				cout << "Áã";
			cout << "Ò¼Çª";
			count = 0;
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡Çª";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÈşÇª";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁÇª";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÎéÇª";
			count = 0;
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½Çª";
			count = 0;
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÆâÇª";
			count = 0;
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°ÆÇª";
			count = 0;
			tab = 1;
			break;
		case 9:
			if (count != 0 && tab != 0)
				cout << "Áã";
			cout << "¾ÁÇª";
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
				cout << "Áã";
			cout << "Ò¼°Û";
			tab = 1;
			count = 0;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡°Û";
			tab = 1;
			count = 0;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Èş°Û";
			tab = 1;
			count = 0;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁ°Û";
			tab = 1;
			count = 0;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Îé°Û";
			count = 0;
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½°Û";
			tab = 1;
			count = 0;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Æâ°Û";
			count = 0;
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°Æ°Û";
			tab = 1;
			count = 0;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾Á°Û";
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
				cout << "Áã";
			cout << "Ò¼Ê°";
			count = 0;
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡Ê°";
			count = 0;
			tab = 1;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÈşÊ°";
			count = 0;
			tab = 1;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁÊ°";
			count = 0;
			tab = 1;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÎéÊ°";
			count = 0;
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½Ê°";
			count = 0;
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ÆâÊ°";
			count = 0;
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°ÆÊ°";
			count = 0;
			tab = 1;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾ÁÊ°";
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
				cout << "Áã";
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Ò¼";
			tab = 1;
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡";
			tab = 1;
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Èş";
			tab = 1;
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁ";
			tab = 1;
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Îé";
			tab = 1;
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½";
			tab = 1;
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Æâ";
			tab = 1;
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°Æ";
			tab = 1;
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾Á";
			tab = 1;
			break;
	}
	if (q != 0 || w != 0 || e != 0 || r != 0 || t != 0 || y != 0 || u != 0 || i != 0 || o != 0 || p != 0 || (s == 0 && d == 0))
		cout << "Ô²";
	else if((s!=0||d!=0)&&tab!=0)
		cout << "Áã";
	count = 0;
	switch (s)
	{
		case 0:
			count += 1;
			break;
		case 1:
			if (count != 0)
				cout << "Áã";
			cout << "Ò¼½Ç";
			break;
		case 2:
			if (count != 0)
				cout << "Áã";
			cout << "·¡½Ç";
		break;
		case 3:
			if (count != 0)
				cout << "Áã";
			cout << "Èş½Ç";
			break;
		case 4:
			if (count != 0)
				cout << "Áã";
			cout << "ËÁ½Ç";
			break;
		case 5:
			if (count != 0)
				cout << "Áã";
			cout << "Îé½Ç";
			break;
		case 6:
			if (count != 0)
				cout << "Áã";
			cout << "Â½½Ç";
			break;
		case 7:
			if (count != 0)
				cout << "Áã";
			cout << "Æâ½Ç";
			break;
		case 8:
			if (count != 0)
				cout << "Áã";
			cout << "°Æ½Ç";
			break;
		case 9:
			if (count != 0)
				cout << "Áã";
			cout << "¾Á½Ç";
			break;
	}
	switch (d)
	{
		case 0:
			count += 1;
			break;
		case 1:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Ò¼·Ö";
			break;
		case 2:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "·¡·Ö";
			break;
		case 3:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Èş·Ö";
			break;
		case 4:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "ËÁ·Ö";
			break;
		case 5:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Îé·Ö";
			break;
		case 6:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Â½·Ö";
			break;
		case 7:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "Æâ·Ö";
			break;
		case 8:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "°Æ·Ö";
			break;
		case 9:
			if (count != 0&&tab!=0)
				cout << "Áã";
			cout << "¾Á·Ö";
			break;
	}
	if ((s == 0 && d == 0) || (s != 0 && d == 0))
		cout << "Õû";
	return 0;
}
