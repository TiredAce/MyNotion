#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 4e6 + 10;

int n, m, a[N];
int trie[N][2], cnt[N], idx;

void insert(int x, int c)
{
    int p = 0;
    for (int i = 31; i >= 0; i --)
    {
        int t = x >> i & 1;
        if (!trie[p][t]) trie[p][t] = ++ idx;
        p = trie[p][t];
        cnt[p] += c;
    }
}

int find(int x)
{
    int p = 0, ans = 0;
    for (int i = 31; i >= 0; i --)
    {
        int t = x >> i & 1;
        if (cnt[trie[p][!t]])
        {
            ans += 1 << i;
            p = trie[p][!t];
        } else p = trie[p][t];
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] ^ x;
    }
    insert(0, 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (i - m > 0) insert(a[i - m - 1], -1);
        ans = max(ans, find(a[i]));
        insert(a[i], 1);
    }
    cout << ans << endl;
    return 0;
}
