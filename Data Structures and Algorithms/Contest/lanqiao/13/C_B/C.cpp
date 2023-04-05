#include <iostream>
#include <algorithm>
#include <cstring>
#define int long long

using namespace std;

int a, b, n;

int32_t main()
{
	cin >> a >> b >> n;	
	int t = 5 * a + 2 * b;
	int ans = 7 * (n / t);
	n %= t;
	int num = 1;
	while (n > 0)
	{
		if (num <= 5) n -= a;
		else n -= b;
		num ++; 
	}
	cout << ans + num - 1<< endl;
	return 0;
}
