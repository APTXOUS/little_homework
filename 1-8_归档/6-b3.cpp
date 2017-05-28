/*1650254 ”»“¢“˙ º∆1*/
#include<iostream>
using namespace std;
void merge(int *la, int *lb, int *lc)
{
	int i = 0, j = 0, k = 0;
	while (*(la + i) != -1 && *(lb + j) != -1)
		if (*(la + i) > *(lb + j))
		{
			*(lc + k) = *(la + i++);
			if (!(k != 0 && *(lc + k) == *(lc + k - 1)))
				k++;
		}
		else
		{
			*(lc + k) = *(lb + j++);
			if (!(k != 0 && *(lc + k) == *(lc + k - 1)))
				k++;
		}
	if (*(la + i) == -1)
		while (*(lb + j) != -1)
		{
			*(lc + k) = *(lb + j++);
			if (!(k != 0 && *(lc + k) == *(lc + k - 1)))
				k++;
		}
	else
		while (*(la + i) != -1)
		{
			*(lc + k) = *(la + i++);
			if (!(k != 0 && *(lc + k) == *(lc + k - 1)))
				k++;
		}
	*(lc + k) = -1;
}
int main()
{
	int a[] = { 20,18,16,9,5,2,2,1,-1 };
	int b[] = { 18,18,18,18,17,17,5,3,3,-1 };
	int c[42];
	merge(a, b, c);
	int i = 0;
	while (*(c + i) != -1)
		cout << *(c + i++) << " ";
	cout << endl;
	system("pause");
	return 0;
}