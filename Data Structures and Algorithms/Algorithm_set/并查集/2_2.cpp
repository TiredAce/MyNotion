#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 3e4 + 10;

int n, t;
int p[N], d[N], sz[N];

int find(int x)
{
	int t = p[x];
	if (p[x] != x)
	{
		p[x] = find(p[x]);
		d[x] += d[t]; 
	}
	return p[x];
}

int main()
{
	cin >> t;
	for (int i = 1; i < N; i ++) p[i] = i, sz[i] = 1;
	while (t --)
	{
		char op;
		int x, y;
		cin >> op >> x >> y;
		int px = find(x), py = find(y);
		if (op == 'M')
		{
		    if (px == py) continue;
			d[px] = sz[py];
			sz[py] += sz[px];
			p[px] = py;
		}
		else
		{
			if (px != py) cout << -1 << endl;
			else cout << max(0, abs(d[x] - d[y]) - 1) << endl;
		}
	}
	return 0;
}
