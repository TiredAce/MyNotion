#include <iostream>
#include <algorithm>
#include <cstring>
//#define int long long

using namespace std;

const int N = 510;

int n, m, sum;
int s[N][N]; 

int cal(int x1, int y1, int x2, int y2)
{
	return s[x1][y1] - s[x2 - 1][y1] - s[x1][y2 - 1] + s[x2 -1][y2 - 1]; 
}

int32_t main()
{
	cin >> n >> m >> sum;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			cin >> s[i][j];
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j <= n; j ++)
		{
			int t = 1;
			for (int k = 1; k <= m; k ++)
			{
				while (t <= k && s[j][k] + s[i - 1][t - 1] - s[i - 1][k] - s[j][t - 1] > sum) t ++;
				ans += k - t + 1;
			}
		}
		
	}
	cout << ans << endl;
}
