#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;

const int N = 2e5 + 10;

int n, a[N], s[N];

int32_t main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = n; i >= 1; i --) s[i] = s[i + 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n - 1; i ++)
    {
        ans += a[i] * s[i + 1];
    }
    cout << ans << endl;
    return 0;
}
