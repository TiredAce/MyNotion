#include <iostream>
#include <algorithm>
#define int long long 

using namespace std;

const int N = 1e5 + 10, mod = 1000000007;

int n;
int ma, mb;
int a[N], b[N];

int32_t main()
{
    cin >> n;
    cin >> ma;
    for (int i = ma; i >= 1; i --) cin >> a[i];
    cin >> mb;
    for (int i = mb; i >= 1; i --) cin >> b[i];
    int ans = 0, t = 1;
    for (int i = 1; i <= ma; i ++)
    {
        ans = (ans + (a[i] - b[i]) * t) % mod;
        t = (t * max(max(a[i], b[i]) + 1, (int)2)) % mod;
    }
    cout << ans << endl;
    return 0;
}
