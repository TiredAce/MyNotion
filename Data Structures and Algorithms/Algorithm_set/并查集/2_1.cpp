#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e4 + 10;

int n, k;
int p[N], d[N];

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
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) p[i] = i;
	int ans = 0;
	while (k --)
	{
		int q, x, y;
		cin >> q >> x >> y;
		if (x > n || y > n) ans ++;
		else
		{
		    int px = find(x), py = find(y);
			if (q == 1)
			{
				if (px == py && (d[x] - d[y]) % 3) ans ++;
				else if (px != py)
				{
					d[px] += d[y] - d[x];
					p[px] = py;
				}
			}
			else
			{
				if (px == py && ((d[x] - d[y]) % 3 + 3) % 3 != 1) ans ++;
				else if (px != py)
				{
					d[px] += 1 + d[y] - d[x];
					p[px] = py;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
