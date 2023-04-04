#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int n, trie[N * 31][2], idx;

void insert(int x)
{
	int p = 0;
	for (int i = 31; i >= 0; i --)
	{
		int t = x >> i & 1;
		if (!trie[p][t]) trie[p][t] = ++ idx;
		p = trie[p][t];
	}
}

int find(int x)
{
	int ans = 0, p = 0;
	for (int i = 31; i >= 0; i --)
	{
		int t = x >> i & 1;
		if (trie[p][!t]) 
		{
		    ans += 1 << i;
		    p = trie[p][!t];
		} else p = trie[p][t];
	}
	return ans;
}

int main()
{
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		insert(x);
		ans = max(ans, find(x));
	}
	cout << ans << endl;
	return 0;
 } 
