#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, l;
double a[N], b[N], s[N], dp[N];

bool check(double x)
{
	for (int i = 1; i <= n; i ++)
	{
		b[i] = a[i] - x;
		s[i] = b[i] + s[i - 1];
	}
	for (int i = 1; i <= n; i ++)
	{
		dp[i] = b[i] + max((double)0, dp[i - 1]);
	}
	double minx = 0;
	for (int i = l; i <= n; i ++)
	{
		if (s[i] - s[i - l] + max(dp[i - l], double(0)) > 0) return true;
	}
	return false;
}

int32_t main()
{
	cin >> n >> l;
	double l = 0, r = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i], r = max(r, a[i]);
	while (r - l > 1e-6)
	{
		double mid = (l + r) / 2;
		if (check(mid)) l = mid; else r = mid;
	}
	cout << int(r * 1000) << endl;
	return 0;
}
