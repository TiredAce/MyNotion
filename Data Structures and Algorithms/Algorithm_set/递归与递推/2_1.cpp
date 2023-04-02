#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#define int long long

using namespace std;

const int mod = 9901;

int a, b;
map<int, int> primes;

void cal_p(int x)
{
	for (int i = 2; i <= x; i ++)
	{
		if (x % i == 0)
		{
			while (x % i == 0)
			{
				primes[i] ++;
				x /= i;
			}
			primes[i] *= b;
		}
	}
}

int qmi(int a, int k, int mod)
{
	int ans = 1;
	while (k)
	{
		if (k & 1) ans = ans * a % mod;
		k >>= 1;
		a = a * a % mod;
	}
	return ans;
}

int sum(int p, int c)
{
    if (c == 0) return 1;
    if (c == 1) return p + 1;
	if (c & 1) return (1 + qmi(p, (c + 1) / 2, mod)) * sum(p, (c - 1) / 2) % mod;
	else return (sum(p, c - 1) + qmi(p, c, mod)) % mod;
}

int32_t main()
{
	cin >> a >> b;
	cal_p(a);
	int ans = 1, ok = 0;
	for (auto &t: primes)
	{
	    ok = 1;
		ans = ans * sum(t.first, t.second) % mod;
	}
	if (ok) cout << ans << endl;
	else cout << 0 << endl;
}
