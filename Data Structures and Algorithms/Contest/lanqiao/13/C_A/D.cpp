#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], dp[N];
map<int, int> mp;

int main()
{
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		dp[i] = dp[i - 1];
		if (mp.count(a[i])) dp[i] = max(dp[i], mp[a[i]]);
		mp[a[i] ^ x] = i;
	}
	while (m --)
	{
		int l, r;
		cin >> l >> r;
		cout << (dp[r] >= l ? "yes": "no") << endl;
	}
	return 0;
}
