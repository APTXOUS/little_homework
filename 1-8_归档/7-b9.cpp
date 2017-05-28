#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <set>
#include <cmath>

using namespace std;

long long n, m, k;
long long ans;
int main()
{
	cin >> n >> m >> k;
	long long dkm = ceil((1.0*m - k) / k);
	long long cur = dkm*k + k - m;
	if ((cur & 1) && (k & 1)) {
		if ((cur + k) / 2 <= k)
			ans = 1 + dkm + 1;
		else {
			long long del_k = n / k;
			cur = n - del_k*k + k;
			if ((cur & 1) && (k & 1)) {
				if (k & 1) {
					if ((cur - k) / 2 >= 0 && (cur - k) / 2 <= k)
						ans = del_k + 1 + 1;
					else
						ans = -1;
				}
			}
			else if ((cur & 1) == 0) {
				if ((k & 1) == 0 && (cur + k) / 2 >= 0 && (cur + k) / 2 <= k)
					ans = del_k;
				else if (cur / 2 >= 0 && cur / 2 <= k)
					ans = del_k + 1;
				else if ((k & 1) == 0 && (cur - k) / 2 >= 0 && (cur - k) / 2 <= k)
					ans = del_k + 2;
				else
					ans = -1;
			}
		}
	}
	else if ((cur & 1) == 0) {
		if (cur / 2 <= k)
			ans = 1 + dkm;
		else
		{
			long long del_k = n / k;
			cur = n - del_k*k + k;
			if ((cur & 1) && (k & 1)) {
				if (k & 1) {
					if ((cur - k) / 2 >= 0 && (cur - k) / 2 <= k)
						ans = del_k + 1 + 1;
					else
						ans = -1;
				}
			}
			else if ((cur & 1) == 0) {
				if ((k & 1) == 0 && (cur + k) / 2 >= 0 && (cur + k) / 2 <= k)
					ans = del_k;
				else if (cur / 2 >= 0 && cur / 2 <= k)
					ans = del_k + 1;
				else if ((k & 1) == 0 && (cur - k) / 2 >= 0 && (cur - k) / 2 <= k)
					ans = del_k + 2;
				else
					ans = -1;
			}
		}
	}
	else {
		long long del_k = n / k;
		cur = n - del_k*k + k;
		if ((cur & 1) && (k & 1)) {
			if (k & 1) {
				if ((cur - k) / 2 >= 0 && (cur - k) / 2 <= k)
					ans = del_k + 1 + 1;
				else
					ans = -1;
			}
		}
		else if ((cur & 1) == 0) {
			if ((k & 1) == 0 && (cur + k) / 2 >= 0 && (cur + k) / 2 <= k)
				ans = del_k;
			else if (cur / 2 >= 0 && cur / 2 <= k)
				ans = del_k + 1;
			else if ((k & 1) == 0 && (cur - k) / 2 >= 0 && (cur - k) / 2 <= k)
				ans = del_k + 2;
			else
				ans = -1;
		}
	}



	cout << ans;
	return 0;
}