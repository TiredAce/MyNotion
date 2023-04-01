#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int N = 1e4 + 10;

typedef pair<int, int> PII;

int n, p, h, m;
int a[N];
map<PII, bool> mp;

void insert(int l, int r, int c)
{
	a[l] += c;
	a[r + 1] -= c;
}

int main()
{
	cin >> n >> p >> h >> m;
	a[1] = h;
	while (m --)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		if (mp[{x, y}]) continue;
		mp[{x, y}] = 1;
		insert(x + 1, y - 1, -1);
	}
	for (int i = 1; i <= n; i ++) a[i] += a[i - 1], cout << a[i] << endl;
	return 0;
}
