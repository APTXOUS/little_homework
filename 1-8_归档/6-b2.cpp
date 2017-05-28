/*1650254 ÓÈÒ¢Òú ¼Æ1*/
#include<iostream>
using namespace std;
void merge(int *la, int *lb, int *lc)
{
	int i = 0, j = 0, k = 0;
	while (*(la + i) != -1 && *(lb + j) != -1)
		if (*(la + i) < *(lb + j))
			*(lc + k++) = *(la + i++);
		else
			*(lc + k++) = *(lb + j++);
	if (*(la + i) == -1)
		while (*(lb + j) != -1)
			*(lc + k++) = *(lb + j++);
	else
		while (*(la + i) != -1)
			*(lc + k++) = *(la + i++);
	*(lc + k) = -1;
}
int main()
{
	int a[] = { 2,5,9,10,16,-1 };
	int b[] = { 1,3,4,6,7,8,17,18,-1 };
	int c[42];
	merge(a, b, c);
	int i = 0;
	while (*(c + i) != -1)
		cout << *(c + i++) << " ";
	cout << endl;

	return 0;
}