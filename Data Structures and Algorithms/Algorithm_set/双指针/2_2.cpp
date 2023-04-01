#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n, d, k;
int isr[N], cnt[N];

struct Node
{
	int ts, ids;
	bool operator<(const Node &t) const
	{
		return ts < t.ts;
	}
}tz[N];

int main()
{
	cin >> n >> d >> k;
	int j = 1;
	for (int i = 1; i <= n; i ++) cin >> tz[i].ts >> tz[i].ids;
	sort(tz + 1, tz + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		cnt[tz[i].ids] ++;
		while (tz[i].ts - tz[j].ts >= d)
		{
			cnt[tz[j].ids] --;
			j ++;
		}
		if (cnt[tz[i].ids] >= k) isr[tz[i].ids] = 1;
	}
	for (int i = 0; i < N; i ++) if (isr[i]) cout <<i << endl;
	return 0;
}
