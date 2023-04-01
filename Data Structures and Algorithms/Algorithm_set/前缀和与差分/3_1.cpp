#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

void insert(int l, int r, int c)
{
	a[l] += c;
	a[r + 1] -= c;
 } 

int32_t main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		insert(i, i, x);
	}
	int neg = 0, pos = 0;
	for (int i = 2; i <= n; i ++)
	{
		if (a[i] > 0) pos += a[i];
		else neg -= a[i]; 
	}
	cout << min(neg, pos) + abs(neg - pos) << endl;
	cout << abs(neg - pos) + 1 << endl;
	return 0;
}
